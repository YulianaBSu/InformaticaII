#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string binario(char c) {
    int chascii = static_cast<int>(c);
    string repbinaria = "";

    int mpotencia = 1;
    while (mpotencia <= chascii) {
        mpotencia *= 2;
    }
    mpotencia /= 2;

    int temp = chascii;

    while (mpotencia > 0) {
        if (temp >= mpotencia) {
            repbinaria += "1";
            temp -= mpotencia;
        } else {
            repbinaria += "0";
        }
        mpotencia /= 2;
    }

    while (repbinaria.length() < 8) {
        repbinaria = "0" + repbinaria;
    }

    return repbinaria;
}



void metodo1(const char* inputFile, const char* outputFile, int agrupacion) {
    ifstream inFile(inputFile, ios::in);
    ofstream outFile(outputFile, ios::out);

    char c;
    int count = 0;
    bool invertir = true;
    bool invertir2 = true;
    bool invertir3 = true;

    int unos = 0, ceros = 0;
    int nbloque = 1;

    while (inFile.get(c)) {
        string repbinaria = binario(c);

        for (char bit : repbinaria) {
            if (invertir) {
                if (bit == '1') {
                    outFile << '0';
                } else {
                    outFile << '1';
                }
            } else if (invertir2) {
                if (count % 2 == 1) {
                    if (bit == '1') {
                        outFile << '0';
                    } else {
                        outFile << '1';
                    }
                } else {
                    outFile << bit;
                }
            } else if (invertir3) {
                if (count % 3 == 2) {
                    if (bit == '1') {
                        outFile << '0';
                    } else {
                        outFile << '1';
                    }
                } else {
                    outFile << bit;
                }
            } else {
                outFile << bit;
            }

            if (bit == '1') {
                unos++;
            } else {
                ceros++;
            }

            count++;
            if (count == agrupacion) {
                count = 0;

                if (nbloque >= 1) {
                    if (ceros == unos) {
                        //cout << "Condicion1 para bloque: " << nbloque << endl; //VERIFICACION: Condicional en cada bloque
                        invertir = true;
                        invertir2 = false;
                        invertir3 = false;
                    } else if (ceros > unos) {
                        //cout << "Condicion2 para bloque: " << nbloque << endl; //VERIFICACION: Condicional en cada bloque
                        invertir = false;
                        invertir2 = true;
                        invertir3 = false;
                    } else if (ceros < unos) {
                        //cout << "Condicion3 para bloque: " << nbloque << endl; //VERIFICACION: Condicional en cada bloque
                        invertir = false;
                        invertir2 = false;
                        invertir3 = true;
                    } else {
                        invertir = false;
                        invertir2 = false;
                        invertir3 = false;
                    }
                }

                // VERIFICACION: Mostrar el conteo de unos y ceros por bloque
               // cout << "Bloque " << nbloque << " - Unos: " << unos << ", Ceros: " << ceros << endl;

                unos = 0;
                ceros = 0;

                nbloque++;
            }
        }
    }

    inFile.close();
    outFile.close();
}


bool validarcont(const string& contrasena) {
    ifstream archivosudo("sudo.txt", ios::in);
    ofstream archivocontrasena("cont.txt", ios::out);
    string contrasenaguardada;

    if (!archivosudo) {
        cerr << "No se pudo abrir el archivo sudo.txt" << endl;
        return false;
    }
    if (!archivocontrasena) {
        cerr << "No se pudo crear el archivo de contrasena" << endl;
        return false;
    }
    archivocontrasena << contrasena;
    archivocontrasena.close();

    archivosudo >> contrasenaguardada;
    archivosudo.close();

    metodo1("cont.txt", "temporal.txt", 4);

    ifstream tempo("temporal.txt", ios::in);
    string contrasenacftemp;

    if (!tempo) {
        cerr << "No se pudo abrir el archivo temporal" << endl;
        return false;
    }

    tempo >> contrasenacftemp;
    tempo.close();

    remove("cont.txt");
    remove("temporal.txt");

    //VERIFICACION: Contrasenas iguales para autenticacion

   // cout << "Contrasena cifrada temporal: " << contrasenacftemp << endl;
   // cout << "Contrasena guardada cifrada: " << contrasenaguardada << endl;

    return (contrasenacftemp == contrasenaguardada);
}

void registrarusuario() {
    ofstream archivoUsuarios("usuarios.txt", ios::app);

    string cedula, clave;
    double saldo;

    cout << "Ingrese cedula: ";
    cin >> cedula;

    cout << "Ingrese clave: ";
    cin >> clave;

    cout << "Ingrese saldo (COP): ";
    cin >> saldo;

    archivoUsuarios << cedula << " " << clave << " " << saldo << "\n";
    archivoUsuarios.close();

    cout << "Usuario registrado exitosamente.\n";
}


bool validaracceso(string cedula, string clave) {
    ifstream archivoUsuarios("usuarios.txt");
    ofstream archivoTemporal("tmp.txt");

    if (!archivoUsuarios) {
        cerr << "No se pudo abrir el archivo de usuarios" << endl;
        return false;
    }

    string cedulausuario, claveusuario;
    double saldo;
    bool usuarioencontrado = false;
    double costotran = 1000;

    while (archivoUsuarios >> cedulausuario >> claveusuario >> saldo) {
        if (cedulausuario == cedula && claveusuario == clave) {
            usuarioencontrado = true;
            double nuevosaldo = saldo - costotran;
            if (nuevosaldo < 0) {
                cout << "Saldo insuficiente para cubrir el costo de operacion." << endl;
            } else {
                cout << "Acceso exitoso.\nCosto de operacion: " << costotran << " COP" << endl;
                cout << "Saldo restante: " << nuevosaldo << " COP" << endl;

                archivoTemporal << cedulausuario << " " << claveusuario << " " << nuevosaldo << "\n";
            }
        } else {
            archivoTemporal << cedulausuario << " " << claveusuario << " " << saldo << "\n";
        }
    }

    archivoUsuarios.close();
    archivoTemporal.close();

    remove("usuarios.txt");
    rename("tmp.txt", "usuarios.txt");

    if (!usuarioencontrado) {
        cout << "Usuario no encontrado." << endl;
    }
    return usuarioencontrado;

}


void consultarsaldo(string cedula) {
    ifstream archivoUsuarios("tmp.txt");

    if (!archivoUsuarios) {
        cerr << "No se pudo abrir el archivo de usuarios" << endl;
        return;
    }

    string cedulausuario, claveusuario;
    double saldo;

    while (archivoUsuarios >> cedulausuario >> claveusuario >> saldo) {
        if (cedulausuario == cedula) {
            cout << "Su saldo es: " << saldo << " COP" << endl;
            archivoUsuarios.close();
            return;
        }
    }

    archivoUsuarios.close();
    cout << "Usuario no encontrado." << endl;
}



void retirarDinero(string cedula, double cantidad) {
    ifstream archivoUsuarios("tmp.txt", ios::in);
    ofstream archivoTemporal("temp.txt", ios::out);

    if (!archivoUsuarios || !archivoTemporal) {
        cerr << "Error al abrir los archivos" << endl;
        return;
    }

    string cedulausuario, claveusuario;
    double saldo;

    bool usuarioencontrado = false;

    while (archivoUsuarios >> cedulausuario >> claveusuario >> saldo) {
        if (cedulausuario == cedula) {
            usuarioencontrado = true;
            if (cantidad > 0 && cantidad <= saldo) {
                saldo -= cantidad;
            } else {
                cout << "Cantidad invalida." << endl;
            }
        }
        archivoTemporal << cedulausuario << " " << claveusuario << " " << saldo << "\n";
    }

    archivoUsuarios.close();
    archivoTemporal.close();

    remove("tmp.txt");
    rename("temp.txt", "usuarios.txt");

    if (!usuarioencontrado) {
        cout << "Usuario no encontrado." << endl;

    }
}

void menuAdministrador() {
    char opcion;
    do {
        cout << "\nMenu de Administrador\n";
        cout << "1. Registrar usuario\n";
        cout << "2. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                registrarusuario();
                break;
            case '2':
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != '2');
}

void menuUsuario(const string& cedula) {
    char opcion;
    do {
        cout << "\nMenu de Usuario\n";
        cout << "1. Consultar saldo\n";
        cout << "2. Retirar dinero\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                consultarsaldo(cedula);
                break;
            case '2':
                double cantidad;
                cout << "Ingrese la cantidad a retirar: ";
                cin >> cantidad;
                retirarDinero(cedula, cantidad);
                break;
            case '3':
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != '3');
}


int main() {
    int opcion;
    do {
        cout << "\nBienvenido al sistema:\n";
        cout << "1. Acceder como administrador\n";
        cout << "2. Acceder como usuario normal\n";
        cout << "3. Codificacion de archivo\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string contrasenaAdmin;
                cout << "Ingrese la contrasena de administrador: ";
                cin >> contrasenaAdmin;
                if (validarcont(contrasenaAdmin)) {
                    cout << "Acceso concedido." << endl;
                    bool useradmin = true;
                    if (useradmin) {
                        menuAdministrador();
                    }
                } else {
                    cout << "Acceso denegado." << endl;
                }
                break;
            }
            case 2: {
                string cedula, clave;
                bool accesovalido = false;
                cout << "\nIngreso con usuario normal, por favor ingrese sus datos:\n";
                cout << "Ingrese su cedula: ";
                cin >> cedula;
                cout << "Ingrese su clave: ";
                cin >> clave;
                accesovalido = validaracceso(cedula, clave);

                if (accesovalido) {
                    cout << "Acceso valido.\n";
                    menuUsuario(cedula);
                } else {
                    cout << "Acceso no valido. Verifique su cedula y clave." << endl;
                }
                break;
            }

        case 3:{
            string inputFile, outputFile;
            int agrupacion;
            cout << "Codificacion de archivo por metodo 1: " << endl;
            cout << "Ingrese nombre del archivo de entrada: ";
            cin >> inputFile;
            cout << "Ingrese nombre del archivo de salida: ";
            cin >> outputFile;
            cout << "Ingrese tamano del grupo de binarios: ";
            cin >> agrupacion;

            metodo1(inputFile.c_str(), outputFile.c_str(), agrupacion);
        }
                break;
            case 4:
              cout << "Saliendo...\n";
              break;

            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}
