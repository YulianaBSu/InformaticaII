#include <iostream>

using namespace std;

int asientos (void);
int cuadrado (void);
int rotar (void);

int main()
{
    cout << "\n\tPROBLEMA #11 PROGRAMA PARA GESTIÓN DE ASIENTOS EN CINE\n" << endl;
    asientos();
    cout << "\n\tPROBLEMA #12 PROGRAMA CUADRADO MAGICO\n" << endl;
    cuadrado(); 
    cout << "\n\tPROBLEMA #14 PROGRAMA ROTACUIB DE MATRIZ 5x5\n" << endl;
    rotar();

    return 0;
}
int asientos(void)
    {
    int columnas[21] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 }, Matriz[21][16] = { 0 };
    string filas[16] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O"};
    int i, j, k, l, C, F,O,ans;
    char letra;

    sillas:
    cout<<"\nLos asientos vacios estan representados con un '0'\nSolo se pueden seleccionar los asientos que se encuentren vacios\n"<<endl;

    for (i=0; i<=20; i++)
    {
        cout<<"\t"<<columnas[i];
    }
    cout<<endl;
    for (i=0; i<15; i++)
    {
        cout<<"\t"<<filas[i];
        for (j=0; j<20; j++)
        {
            cout<<"\t"<< Matriz[i][j];
        }
        cout<<endl;
    }
    cout<<"\nEn pantalla se encuentran los asientos disponibles, ¿Cuantos asientos desea reservar?"<<endl;
    cout<<"Ingrese cantidad: ";
    cin>>k;
    if( k>0 && k<=20)
    {
        for (l=1; l<=k; l++)
        {

        Ubicacion:
            cout<<"\nSeleccione la ubicación de su preferencia"<<endl;
            cout<<"\tIngrese letra de la fila deseada: "; cin>>letra;
            if (letra == 'A')
                F = 1;
            else if (letra == 'B')
                F = 2;
            else if (letra == 'C')
                F = 3;
            else if (letra == 'D')
                F = 4;
            else if (letra == 'E')
                F = 5;
            else if (letra == 'F')
                F = 6;
            else if (letra == 'G')
                F = 7;
            else if (letra == 'H')
                F = 8;
            else if (letra == 'I')
                F = 9;
            else if (letra == 'J')
                F = 10;
            else if (letra == 'K')
                F = 11;
            else if (letra == 'L')
                F = 12;
            else if (letra == 'M')
                F = 13;
            else if (letra == 'N')
                F = 14;
            else if (letra == 'O')
                F = 15;

            cout<<"\tIngrese # de silla: "; cin>>C;
            if (Matriz[F-1][C-1] == '+')
            {
                if ((F>0 && F<=15) && (C>0 && C<=20))
                {
                    for (i=0; i<=15; i++)
                    {
                        for (j=0; j<21; j++)
                        {
                            Matriz[F-1][C-1] = '-';
                        }
                    }
                }
                else
                {
                    cout<<"Este asiento no se encuentra disponible"<<endl;
                    goto menup;

                }
            }
            else
            {
                cout<<"El asiento indicado no existe o está ocupado"<<endl;
                cout<<"\t1.Volver a escoger silla\n\t2.Cancelar operacion"<<endl;
                cout<<"Ingrese opcion: "; cin>>O;

                if (O == 2)
                {
                    return 0;
                }
                else
                    goto Ubicacion;
            }
        }
    }
    else
    {
        cout<<"Solo puede reservar 20 sillas max"<<endl;
        goto sillas;
    }
    cout<<"\nConfirme sus asientos, los asientos disponibles se encuentran representados por un '0'"<<endl;
    for (i=0; i<=20; i++)
    {
        cout<<"\t"<<columnas[i];
    }
    cout<<endl;
    for (i=0; i<15; i++)
    {
        cout<<"\t"<<filas[i];
        for (j=0; j<20; j++)
        {
            cout<<"\t"<< Matriz[i][j];
        }
        cout<<endl;
    }

    cout<<"\nConfirme si sus asientos son correctos.\n\t1.Si\n\t2.No"<<endl;
    cout<<"Ingrese opción: ";
    cin >> ans;
    switch (ans)
    {
    case 1:
    salida:
        return 0;
        break;
    case 2:
    menup:
        cout<<"Ingrese opción deseada:\n\t1.Volver a escoger asientos\n\t2.Cancelar operacion"<<endl;
        cin>>O;
        if (O ==2)
        {
            goto salida;
        }
        else
            goto sillas;
    default:
        cout<<"Opcion invalida, saliendo del programa"<<endl;
        goto salida;
    }

}



//******************************************************************************************************************************

int cuadrado(void)
{
    int grado, i, j, suma, aux;

    cout<<"\n\t-------> Cuadrado Magico <-------\n"<<endl;

    cout<<"\nPara comenzar, es necesario saber algunos puntos clave para el buen uso del Cuadrado Magico"<<endl;
    cout<<"\n -La suma de los numeros por fila, columna o diagonal debe ser igual siempre."<<endl;
    cout<<"\n -Los cuadrados Magicos deben de ser de 3 o mas numeros por lado."<<endl;

    cout<<"\n\nPara iniciar ingrese el tamaño del cuadrado mágico: ";
    cin>>grado;

    if(grado<3)
    {
        cout<<"Error, el tamaño del cuadrado mágico debe ser mayor o igual a 3"<<endl;
        cout<<"Cerrando programa"<<endl;
        return(0);
    }

    int matrix[grado][grado],comp[grado],compb[grado];
    cout<<"\n\nPara continuar ingrese los datos del cuadrado mágico\n"<<endl;
    suma = (grado*(grado*grado+1))/2;
    cout<<"Recuerde que la suma de cada fila, columna o diagonal es: "<< suma<<endl;
    for(i=0;i<grado;i++)
    {
        for(j=0;j<grado;j++)
        {
            matrix[i][j]=0;
        }
    }

    for(i=0;i<grado;i++)
    {
        comp[i]=0;
    }

    for(i=0;i<grado;i++)
    {
        compb[i]=0;
    }

    for(i=0;i<grado;i++)
    {
        for(j=0;j<grado;j++)
        {
            aux=0;
            cout<<"Ingresa valor de la casilla ["<<i<<"]["<<j<<"]: ";
            cin>>aux;
            matrix[i][j]=aux;
        }
    }

    for(i=0;i<grado;i++)
    {
        for(j=0;j<grado;j++)
        {
            comp[i]=comp[i]+matrix[i][j];
        }
    }

    for(i=0;i<grado;i++)
    {
        for(j=0;j<grado;j++)
        {
            compb[i]=compb[i]+matrix[j][i];
        }
    }

    for(i=0;i<grado;i++)
    {
        if(comp[i]!=suma)
        {
            cout<<"\n\t\tERROR\n"<<endl;
            cout<<"Su Cuadrado mágico presenta un error\n\n"<<endl;
            return(0);
        }
    }

    for(i=0;i<grado;i++)
    {
        if(compb[i] != suma)
        {
            cout<<"\n\t\tERROR\n"<<endl;
            cout<<"Su Cuadrado mágico presenta un error\n\n"<<endl;
            return(0);
        }

    }

    cout<<"\n\tSu Cuadrado mágico es válido\n"<<endl;

    for(i=0;i<grado;i++)
    {
        for(j=0;j<grado;j++)
        {
            cout<<"\t "<<matrix[i][j];
        }
        cout<<"\n\n"<<endl;

    }
}


//******************************************************************************************************************************

int rotar(void)
    {
    int t=0;
    int m[5][5];
    for(int i=0;i<5;i++)
    {

        for(int j=0;j<5;j++){

            t=t+1;

            m[i][j]=t;

        }

    }
    cout<<"\t\tMatriz original\n"<<endl;
    for(int i=0;i<5;i++){

        for(int j=0;j<5;j++){

            cout<<"\t"<<m[i][j];

        }

        cout<<endl;
    }


}
