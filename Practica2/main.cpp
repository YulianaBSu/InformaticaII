
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


//******FUNCIONES******

//Problema 3
bool compcad(const char* cadena1, const char* cadena2) {
    while (*cadena1 != '\0' && *cadena2 != '\0') {
        if (*cadena1 != *cadena2) {
            return false;
        }
        cadena1++;
        cadena2++;
    }
    return *cadena1 == *cadena2;
}

//Problema 4
int convint(const char* cadena) {
    int resultado = 0;
    int i = 0;
    while (cadena[i] != '\0') {
        if (cadena[i] >= '0' && cadena[i] <= '9') {
            resultado = resultado * 10 + (cadena[i] - '0');
        } else {
            cout << "La cadena contiene caracteres no numericos." << endl;
            return -1;
        }
        i++;
    }
    return resultado;
}

//Problema 5
void convcad(int numero, char* cadena) {
    if (numero == 0) {
        cadena[0] = '0';
        return;
    }
    int temp = numero;
    int longitud = 0;

    while (temp!=0) {
        temp /= 10;
        longitud++;
    }

    cadena[longitud] = '\0';

    for (int i = longitud - 1; i >= 0; i--) {
        cadena[i] = '0' + (numero % 10);
        numero /= 10;
    }
}

//Problema 6
void convmay(char* cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            cadena[i] = cadena[i] - 'a' + 'A';
        }
    }
}

//Problema 7
void norep(char* cadena) {
    int caracteres[256] = {0};
    int i, j = 0;

    for (i = 0; cadena[i] != '\0'; i++) {
        if (caracteres[(int)cadena[i]] == 0) {
            caracteres[(int)cadena[i]] = 1;
            cadena[j++] = cadena[i];
        }
    }
    cadena[j] = '\0';
}


//Problema 8
void sepnum(char* cadena, char* texto, char* numeros) {
    int j = 0, k = 0;

    for (int i = 0; cadena[i] != '\0'; i++) {
        if (isdigit(cadena[i])) {
            numeros[j++] = cadena[i];
        } else {
            texto[k++] = cadena[i];
        }
    }
    numeros[j] = '\0';
    texto[k] = '\0';
}


//Problema 9
int sumncif(int n, char* cadena) {
    int longitud = 0;
    while (cadena[longitud] != '\0') {
        longitud++;
    }
    int ceros = n-(longitud % n);
    if (ceros == n) ceros = 0;

    char nuevaCadena[100]={0};
    for (int i = 0; i <ceros; i++) {
        nuevaCadena[i] = '0';
    }
    for (int i = ceros, j = 0; j <longitud; i++, j++) {
        nuevaCadena[i] =cadena[j];
    }
    int suma = 0;
    for (int i = 0; i <longitud + ceros; i += n) {
        int numero = 0;
        for (int j = 0; j < n; j++) {
            numero= numero*10+(nuevaCadena[i+j] - '0');
        }
        suma += numero;
    }

    return suma;
}

//Problema 10
int convromano(string nromano) {
    int total = 0;
    int longitud = nromano.length();
    int vanterior = 0;
    for (int i = longitud-1; i >= 0; i--) {
        int valor = 0;
        switch (nromano[i]) {
            case 'I': valor = 1; break;
            case 'V': valor = 5; break;
            case 'X': valor = 10; break;
            case 'L': valor = 50; break;
            case 'C': valor = 100; break;
            case 'D': valor = 500; break;
            case 'M': valor = 1000; break;
            default: return 0; // Carácter inválido
        }
        if (valor >= vanterior) {
            total += valor;
        } else {
            total -= valor;
        }
        vanterior = valor;
    }
    return total;
}



//Problema 11
const int filas = 15;
const int asientos = 20;
char sala[filas][asientos];

void crearsala() {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < asientos; j++) {
            sala[i][j] = '-';
        }
    }
}

void mostrarsala() {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < asientos; j++) {
            cout << sala[i][j] << '\t';
        }
        cout << endl;
    }
}

void reserva(int fila, int asiento) {
    if (fila >= 0 && fila < filas && asiento >= 0 && asiento < asientos) {
        if (sala[fila][asiento] == '-') {
            sala[fila][asiento] = '+';
            cout << "Asiento reservado" << endl;
        } else {
            cout << "El asiento ya esta reservado." << endl;
        }
    } else {
        cout << "Fila o asiento invalido." << endl;
    }
}

void cancelaciones(int fila, int asiento) {
    if (fila >= 0 && fila < filas && asiento >= 0 && asiento < asientos) {
        if (sala[fila][asiento] == '+') {
            sala[fila][asiento] = '-';
            cout << "Reserva cancelada." << endl;
        } else {
            cout << "El asiento no esta reservado." << endl;
        }
    } else {
        cout << "Fila o asiento invalido." << endl;
    }
}


//Problema 12

const int maxfilas = 10;
const int maxcolumnas = 10;

bool cuadradomag(int matriz[maxfilas][maxcolumnas], int tamano) {
    int constante = 0;

    for (int i = 0; i < tamano; i++) {
        constante += matriz[0][i];
    }

    for (int i = 1; i < tamano; i++) {
        int sumfila = 0;
        for (int j = 0; j < tamano; j++) {
            sumfila += matriz[i][j];
        }
        if (sumfila != constante) {
            return false;
        }
    }

    for (int j = 0; j < tamano; j++) {
        int sumcolumna = 0;
        for (int i = 0; i < tamano; i++) {
            sumcolumna += matriz[i][j];
        }
        if (sumcolumna != constante) {
            return false;
        }
    }

    int sumdiag = 0;
    for (int i = 0; i < tamano; i++) {
        sumdiag += matriz[i][i];
    }
    if (sumdiag != constante) {
        return false;
    }

    int sumdiagsec = 0;
    for (int i = 0; i < tamano; i++) {
        sumdiagsec += matriz[i][tamano - 1 - i];
    }
    if (sumdiagsec != constante) {
        return false;
    }

    return true;
}


//Problema 13

int contestrellas(int (*matriz)[8]) {
    int cont = 0;

    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 7; j++) {
           int suma = matriz[i][j] + matriz[i][j-1] + matriz[i][j+1] + matriz[i-1][j] + matriz[i+1][j];
            if (suma / 5 > 6) {
                cout << "El elemento en la fila " << i+1 << ", columna " << j+1 << " (" << matriz[i][j] << ") es una estrella"<<endl;
                cont++;

            }
        }
    }

    return cont;
}



//Problema 14
const int matfilas = 5;
const int matcolumnas = 5;

void genmatriz(int matriz[matfilas][matcolumnas]) {
    int cont = 1;
    for (int i = 0; i < matfilas; i++) {
        for (int j = 0; j < matcolumnas; j++) {
            matriz[i][j] = cont++;
        }
    }
}

void impmatriz(int matriz[matfilas][matcolumnas]) {
    for (int i = 0; i < matfilas; i++) {
        for (int j = 0; j < matcolumnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

void rotarmatriz90(int matriz[matfilas][matcolumnas], int nuevaMatriz[matfilas][matcolumnas]) {
    for (int i = 0; i < matfilas; i++) {
        for (int j = 0; j < matcolumnas; j++) {
            nuevaMatriz[j][matfilas - i - 1] = matriz[i][j];
        }
    }
}

void rotarmatriz180(int matriz[matfilas][matcolumnas], int nuevaMatriz[matfilas][matcolumnas]) {
    for (int i = 0; i < matfilas; i++) {
        for (int j = 0; j < matcolumnas; j++) {
            nuevaMatriz[matfilas - i - 1][matcolumnas - j - 1] = matriz[i][j];
        }
    }
}

void rotarmatriz270(int matriz[matfilas][matcolumnas], int nuevaMatriz[matfilas][matcolumnas]) {
    for (int i = 0; i < matfilas; i++) {
        for (int j = 0; j < matcolumnas; j++) {
            nuevaMatriz[matcolumnas - j - 1][i] = matriz[i][j];
        }
    }
}



//Problema 15

void interseccion(int Ax, int Ay, int Aancho, int Aalto, int Bx, int By, int Bancho, int Balto) {
    int Cx, Cy, Cancho, Caltura;
    Cx=max(Ax, Bx);
    Cy=max(Ay, By);
    Cancho = min(Ax + Aancho, Bx + Bancho) - Cx;
    Caltura = min(Ay + Aalto, By + Balto) - Cy;

    cout << "Coordenadas de la esquina superior izquierda (x, y): (" << Cx << ", " << Cy << ")" << endl;
    cout << "Ancho: " << Cancho << ", Altura: " << Caltura << endl;
    cout <<"Arreglo: {"<< Cx<<","<<Cy<<","<<Cancho<<","<<Caltura<<"}"<<endl;
}


//Problema 16

int caminosposibles(int n) {
    //(2n)!/(n!*n!)
    int num = 1;
    int den = 1;

    for (int i = 1; i <= 2*n; ++i) {
        num *= i;
    }

    for (int i = 1; i <= n; ++i) {
        den *= i;
    }
    den *= den;

    return num/den;
}


//Problema 17
int sumdiv(int num) {
    int suma = 0;
    for (int i = 1; i <= num/2; i++) {
        if (num % i == 0) {
            suma += i;
        }
    }
    return suma;
}

void amigables(int limite) {
    int total = 0;
    for (int i = 1; i <= limite; i++) {
        int sumadivs = sumdiv(i);
        if (sumadivs != i && sumdiv(sumadivs) == i) {
            total += i;
        }
    }
    cout << "El resultado de la suma es: " << total << endl;
}



int main()
{
    int opcion=1;
    while(opcion!=0)
    {
    cout<<"\nMenu principal, ingrese una de las opciones disponibles o presione cualquier tecla para salir\n "<<endl;
    cout<<"1. Combinacion de billetes y monedas (Arduino) "<<endl;
    cout<<"2. Generar arreglo y conteo de letras "<<endl;
    cout<<"3. Comparar cadenas de caracteres "<<endl;
    cout<<"4. Cadena de caracteres a enteros "<<endl;
    cout<<"5. Entero a cadena de caracteres "<<endl;
    cout<<"6. Cadena de caracteres a mayusculas "<<endl;
    cout<<"7. Eliminar caracteres repetidos "<<endl;
    cout<<"8. Separar numeros de caracteres "<<endl;
    cout<<"9. Suma de numeros agrupados "<<endl;
    cout<<"10. Convertir numero romano "<<endl;
    cout<<"11. Reservas sala de cine "<<endl;
    cout<<"12. Cuadrado magico "<<endl;
    cout<<"13. Numero de estrellas "<<endl;
    cout<<"14. Matriz rotada "<<endl;
    cout<<"15. Interseccion de rectangulos "<<endl;
    cout<<"16. Caminos posibles en malla "<<endl;
    cout<<"17. Numeros amigables "<<endl;
    cout<<"\nSeleccione una opcion: ";

    cin>>opcion;
    switch (opcion)

    {
    case 1:

         //Problema 1
     {
            cout << "Ver solucion del problema en el siguiente enlace: https://www.tinkercad.com/things/0l9N4h8ztbt?sharecode=67snZthjsc9W893XF1ze_C8aYt308z7VEgfjyMZ1-P0";
         break;
    }


    case 2:

         //Problema 2
     {
        srand(time(0)); // Inicializar la semilla para números aleatorios
        char letras[200]; // Crear un arreglo de 200 caracteres
        for (int i=0; i<200; i++) {
            letras[i]='A'+rand()%26; // Generar letras aleatorias
        }
        cout << "Arreglo y cantidad de letras: ";
        for (int i = 0; i < 200; i++) {
            cout << letras[i];
        }
        cout << endl;
        int cont[26]={0};
        for (int i = 0; i < 200; i++) {
            cont[letras[i]-'A']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cont[i] > 0) {
                cout << (char)('A'+i)<<": "<<cont[i]<<endl;
            }
}
         break;
    }

    case 3:

         //Problema 3
     {
        char cadena1[50];
        char cadena2[50];

        cout << "Ingresa la primera cadena: ";
        cin >> cadena1;

        cout << "Ingresa la segunda cadena: ";
        cin >> cadena2;

        if (compcad(cadena1, cadena2)) {
            cout << "Las cadenas 1 y 2 son iguales." << endl;
        }

        else {
            cout << "Las cadenas 1 y 2 son diferentes." << endl;
        }

         break;
    }

    case 4:

         //Problema 4
     {
            char cadena[10];
            cout<<"Ingresa cadena de caracteres numericos: ";
            cin>>cadena;
            int numero = convint(cadena);
            if (numero != -1) {
                cout << "El numero entero es: "<<numero<< endl;
            }
         break;
    }


    case 5:
        //Problema 5
    {
        int numero;
        cout<<"Ingrese numero a convertir: ";
        cin>>numero;
        char cadena[50]; // Asumimos que la cadena no tendrá más de 50 caracteres

        convcad(numero, cadena);

        cout << "El entero convertido a cadena es: " << cadena << endl;

        break;
    }

    case 6:

         //Problema 6
     {
        char cadena[100];
        cout << "Ingrese una cadena de caracteres: ";
        cin>>cadena;
        cout << "\nOriginal: " << cadena<<". ";
        convmay(cadena);
        cout << "En mayuscula: " << cadena << endl;
        break;
    }

    case 7:

         //Problema 7
     {
        char cadena[100];
        cout << "Ingrese una cadena de caracteres: ";
        cin>>cadena;
        cout << "\nOriginal: "<<cadena<<". ";
        norep(cadena);
        cout << "Sin repetidos: " << cadena << endl;
        break;
    }

    case 8:

         //Problema 8
     {
        char cadena[100];
        char texto[100] = "";
        char numeros[100] = "";
        cout << "Ingrese una cadena de caracteres: ";
        cin>>cadena;
        cout << "\nOriginal: " << cadena << endl;
        sepnum(cadena, texto, numeros);
        cout << "Texto: " << texto << ". Numero: " << numeros << endl;
        break;
    }

    case 9:

         //Problema 9
     {
        int n;
        char cadena[100];

        cout << "Ingrese n: ";
        cin >> n;
        cout << "Ingrese una cadena de caracteres numericos: ";
        cin >> cadena;
        cout << "Original: " << cadena << ". ";
        int resultado = sumncif(n, cadena);
        cout << "Suma: " << resultado << "." << endl;
        break;
    }



    case 10:

         //Problema 10
     {
        string nrorom;

        cout << "Ingrese un numero del sistema romano: ";
        cin >> nrorom;

        int varabigo = convromano(nrorom);

        if (varabigo != 0) {
            cout << "El numero ingresado fue: " << nrorom << ". Que corresponde a: " << varabigo << "." << endl;
        } else {
            cout << "Numero romano inválido." << endl;
        }
        break;
    }

    case 11:

         //Problema 11
     {
        crearsala();

        char opcion = ' ';
        int fila, asiento;

        while (opcion != 'q') {
            cout << "-------- Sala de Cine --------" << endl;
            mostrarsala();
            cout << "-------------------------------" << endl;
            cout << "a. Reservar Asiento" << endl;
            cout << "b. Cancelar Reserva" << endl;
            cout << "q. Salir" << endl;
            cout << "Elija una opcion: ";
            cin >> opcion;

            switch(opcion) {
                case 'a':
                    cout << "Ingrese la fila (A-O) y el numero del asiento (1-20) separados por un espacio: ";
                    char letraFila;
                    cin >> letraFila >> asiento;
                    fila = toupper(letraFila) - 'A'; // Convertir la letra a un índice de fila (0-14)
                    asiento--; // Restar 1 para ajustar al índice del arreglo (0-19)
                    reserva(fila, asiento);
                    break;
                case 'b':
                    cout << "Ingrese la fila (A-O) y el numero del asiento (1-20) separados por un espacio: ";
                    char letraFilaCancel;
                    cin >> letraFilaCancel >> asiento;
                    fila = toupper(letraFilaCancel) - 'A'; // Convertir la letra a un índice de fila (0-14)
                    asiento--; // Restar 1 para ajustar al índice del arreglo (0-19)
                    cancelaciones(fila, asiento);
                    break;
                case 'q':
                    cout << "Saliendo..." << endl;
                    break;
                default:
                    cout << "Opción inválida. Intente de nuevo." << endl;
            }
        }

         break;
    }

    case 12:

         //Problema 12
     {
        int tamano;
        cout << "Ingrese el tamano de la matriz cuadrada (maximo " << maxfilas << "x" << maxcolumnas << "): ";
        cin >> tamano;

        if (tamano <= 0 || tamano > maxfilas) {
            cout << "Tamano invalido." << endl;
            return 1;
        }

        int matriz[maxfilas][maxcolumnas];

        cout << "Ingrese los elementos de la matriz fila por fila (separados por espacios):" << endl;
        for (int i = 0; i < tamano; i++) {
            for (int j = 0; j < tamano; j++) {
                cin >> matriz[i][j];
            }
        }

        cout << "Matriz ingresada:" << endl;
        for (int i = 0; i < tamano; i++) {
            for (int j = 0; j < tamano; j++) {
                cout << matriz[i][j] << "\t";
            }
            cout << endl;
        }

        if (cuadradomag(matriz, tamano)) {
            cout << "La matriz es un cuadrado magico." << endl;
        } else {
            cout << "La matriz no es un cuadrado magico." << endl;
        }

        break;
    }



    case 13:

         //Problema 13
     {
        int matriz[6][8] = {
            {0, 3, 4, 0, 0, 0, 6, 8},
            {5, 13, 6, 0, 0, 0, 2, 3},
            {2, 6, 2, 7, 3, 0, 10, 0},
            {0, 0, 4, 15, 4, 1, 6, 0},
            {0, 0, 7, 12, 6, 9, 10, 4},
            {5, 0, 6, 10, 6, 4, 8, 0}
        };

        int estrellas = contestrellas(matriz);

        cout << "Numero de estrellas encontradas: " << estrellas << endl;
        break;
    }

    case 14:

         //Problema 14
     {
        int matrizorg[matfilas][matcolumnas];
        int matriz90[matfilas][matcolumnas];
        int matriz180[matfilas][matcolumnas];
        int matriz270[matfilas][matcolumnas];

        genmatriz(matrizorg);

        cout << "Matriz original" << endl;
        impmatriz(matrizorg);

        cout << "\nMatriz rotada 90 grados" << endl;
        rotarmatriz90(matrizorg, matriz90);
        impmatriz(matriz90);

        cout << "\nMatriz rotada 180 grados" << endl;
        rotarmatriz180(matrizorg, matriz180);
        impmatriz(matriz180);

        cout << "\nMatriz rotada 270 grados" << endl;
        rotarmatriz270(matrizorg, matriz270);
        impmatriz(matriz270);

        break;


    }
    case 15:

         //Problema 15
     {
        int Ax, Ay, Aancho, Aalto, Bx, By, Bancho, Balto;

        // Ingresar los datos del rectángulo A
        cout << "Ingrese las coordenadas de la esquina superior izquierda del rectangulo A (x y): ";
        cin >> Ax >> Ay;
        cout << "Ingrese el ancho y la altura de A (separados por espacio): ";
        cin >> Aancho >> Aalto;

        // Ingresar los datos del rectángulo B
        cout << "Ingrese las coordenadas de la esquina superior izquierda del rectangulo B (x y): ";
        cin >> Bx >> By;
        cout << "Ingrese el ancho y la altura de B (separados por espacio): ";
        cin >> Bancho >> Balto;

        // Hallar la intersección entre A y B
        cout << "\nRectangulo de interseccion (C):" << endl;
        interseccion(Ax, Ay, Aancho, Aalto, Bx, By, Bancho, Balto);

         break;
    }

    case 16:

         //Problema 16
     {
        int n;
        cout << "Ingrese el tamano de la cuadricula (n): ";
        cin >> n;

        int caminos = caminosposibles(n);

        cout << "\nPara una malla de " << n << "x" << n << " puntos hay " << caminos << " caminos." << endl;

        break;


    }
    case 17:

         //Problema 17
     {
        int numero;
        cout << "Ingrese un numero: ";
        cin >> numero;
        amigables(numero);

        break;

    }
}
}
}

