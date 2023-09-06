#include <iostream>
using namespace std;

int main()
{
    int opcion=1;
    while(opcion!=0)
    {
    cout<<"\nMenu principal, ingrese una de las opciones disponibles o presione cualquier tecla para salir\n "<<endl;
    cout<<"1. Identificar vocales o consonantes "<<endl;
    cout<<"2. Combinacion de billetes y monedas "<<endl;
    cout<<"3. Fechas validas "<<endl;
    cout<<"4. Calculo de horas "<<endl;
    cout<<"5. Patron rombo "<<endl;
    cout<<"6. Valor aproximado de euler "<<endl;
    cout<<"7. Serie de Fibonacci "<<endl;
    cout<<"8. Suma de multiplos "<<endl;
    cout<<"9. Suma de digitos "<<endl;
    cout<<"10. Enesimo numero primo "<<endl;
    cout<<"11. Minimo comun multiplo "<<endl;
    cout<<"12. Maximo factor primo "<<endl;
    cout<<"13. Suma de numeros primos "<<endl;
    cout<<"14. Numero palindromo "<<endl;
    cout<<"15. Espiral de numeros "<<endl;
    cout<<"16. Serie de Collatz "<<endl;
    cout<<"17. Numeros triangulares "<<endl;
    cout<<"\nSeleccione una opcion: ";

    cin>>opcion;
    switch (opcion)

    {
    case 1:

         //Problema 1
     {
        char letra;

            cout << "Ingrese una letra: ";
            cin >> letra;
            if (letra>='a' && letra<='z') {
                letra= toupper(letra);
            }
            if ((letra>= 'A' && letra<= 'Z')) {
                if (letra=='A' || letra=='E' || letra=='I' || letra=='O' || letra=='U') {
                    cout<<letra<<" es una vocal."<<endl;
                } else {
                    cout<<letra<<" es una consonante."<<endl;
                }
            } else {
                cout<< "No es una letra."<<endl;
            }
         break;
    }


    case 2:

         //Problema 2
     {
         int pesos, total;
         cout<<"Ingrese la cantidad en pesos: ";
         cin >> pesos;
         cout<<"\n";

         total = pesos/50000;
         pesos%=50000;
         cout<< "50000: "<<total<<endl;

         total = pesos/20000;
         pesos%=20000;
         cout<< "20000: "<<total<<endl;

         total = pesos/10000;
         pesos%=10000;
         cout<< "10000: "<<total<<endl;

         total = pesos/5000;
         pesos%=5000;
         cout<< "5000: "<<total<<endl;

         total = pesos/2000;
         pesos%=2000;
         cout<< "2000: "<<total<<endl;

         total = pesos/1000;
         pesos%=1000;
         cout<< "1000: "<<total<<endl;

         total = pesos/500;
         pesos%=500;
         cout<< "500: "<<total<<endl;

         total = pesos/200;
         pesos%=200;
         cout<< "200: "<<total<<endl;

         total = pesos/100;
         pesos%=100;
         cout<< "100: "<<total<<endl;

         total = pesos/50;
         pesos%=50;
         cout<< "50: "<<total<<endl;

         cout<<"Faltante: "<<pesos<<endl;

         break;
    }

    case 3:

         //Problema 3
     {
         int mes, dia;

         cout << "Ingrese un mes (1-12): ";
         cin >> mes;
         cout << "Ingrese un dia entre 1 y 31 (si aplica): ";
         cin >> dia;

         if (mes<1 || mes>12) {
             cout<<mes<<" es un mes invalido."<<endl;
         }
         else if (dia<1 || dia>31) {
             cout << dia << " es un dia invalido." <<endl;
         }
         else if (mes==2) {
             if (dia==29) {
                 cout << "posiblemente año bisiesto." <<endl;
                 cout << "29/2 es valida en bisiesto." <<endl;
             }
             else if (dia<1 || dia>28) {
                 cout<<dia<<"/"<<mes<<" es una fecha invalida."<<endl;
             }
             else {
                 cout<<dia<<"/"<<mes<<" es una fecha valida."<<endl;
             }
         }
         else if ((mes==4 || mes==6 || mes==9 || mes==11) && (dia<1 || dia>30)) {
             cout<<dia<<"/"<<mes<<" es una fecha invalida."<<endl;
         }
         else {
             cout<<dia<<"/"<<mes<<" es una fecha valida."<<endl;
         }

         break;
    }

    case 4:

         //Problema 4
     {
        int hora, duracion;
            cout<<"Ingrese la hora en formato de 24 horas: ";
            cin>>hora;
            cout<<"Ingrese la duración en formato de tiempo: ";
            cin>> duracion;
            if (hora<0 || hora>=2400 || hora%100>=60) {
                cout<<hora<< " es un tiempo inválido."<<endl;
                return 1;
            }

            if (duracion<0 || duracion>=2400 || duracion%100>= 60) {
                cout<< duracion<<" es un tiempo inválido." << endl;
                return 1;
            }
            int minutos=(hora % 100 + duracion % 100) % 60;
            int horas=hora/100+duracion/100+(hora%100+duracion%100)/60;
            horas=horas%24;
            cout << "La hora es ";
            if (horas<10) {
                cout<<"0";
            }
            cout<<horas;
            if (minutos<10) {
                cout << "0";
            }
            cout<<minutos<<endl;

         break;
    }


    case 5:
        //Problema 5
    {
        int base;
        do{
        cout<<"Ingrese cantidad de asteriscos (*) en el medio del rombo (numero impar): ";
        cin>>base;
        }while(base%2==0 ||base<=0);

        int b=base/2;
        int cont=1;
        bool band=true;
        for(int i=0;i<base;i++){
            for(int i=0;i<b;i++)
                cout<<" ";
            for(int i=0;i<cont;i++){
                cout<<"*";}
                cout<<endl;
            if(b>0 && band==true) {
                b=b-1;
                cont=cont+2;
            }
            else{
                b=b+1;
                cont=cont-2;
                band=false;
               }
    }
        break;
    }

    case 6:

         //Problema 6
     {
        int n;
        cout << "Ingrese el numero de terminos para la aproximacion de e: ";
        cin >> n;
        float  e = 0.0;
        int  f = 1 ;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                f *= i;
            }
            e += (float)1 / f;
        }
        cout<<"e es aproximadamente: "<<e<<endl;
         break;
    }

    case 7:

         //Problema 7
     {
        int n;
        cout << "Ingrese un numero n: ";
        cin >> n;
        int f1 = 1;
        int f2 = 1;
        int suma = 0;
        while (f2<n) {
            if (f2 % 2==0) {
                suma+= f2;
            }
            int temp=f1+f2;
            f1=f2;
            f2=temp;
        }
        cout<<"El resultado de la suma es: "<<suma<< endl;

         break;
    }

    case 8:

         //Problema 8
     {
        int a,b,c;

        cout<<"Ingrese el valor de a: ";
        cin>>a;
        cout<<"Ingrese el valor de b: ";
        cin>>b;
        cout<<"Ingrese el valor de c: ";
        cin>>c;
        int suma=0;
        for (int i=1; i<c; i++) {
            if (i % a == 0 || i % b == 0) {
                suma+= i;
            }
        }
        cout<<"Resultado: ";
        for (int i=1; i<c; i++) {
            if ((i % a == 0 || i % b == 0)) {
               cout << i;
                if (i<c-1) {
                    cout << " + ";
                }
            }
        }
        cout<<" = "<<suma<<endl;

         break;
    }

    case 9:

         //Problema 9
     {
        int numero;

        cout<<"Ingrese un numero entero: ";
        cin>>numero;

        int suma=0;
        int temp=numero;

        while (temp>0) {
            int digito=temp%10;
            int digitoElevado=1;
            for (int i=0; i<digito; i++) {
                digitoElevado*=digito;
            }
            suma+=digitoElevado;
            temp/=10;
        }
        cout<<"El resultado de la suma es: "<<suma<< endl;

         break;
    }
    case 10:

         //Problema 10
     {
        int n;

        cout<<"Ingrese el valor de n: ";
        cin>>n;

        int contador=0;
        int numeroPrimo=2;
        while (contador<n) {
            bool Primo=true;
            for (int i=2; i*i<=numeroPrimo; i++) {
                if (numeroPrimo%i==0) {
                    Primo = false;
                    break;
                }
            }
            if (Primo) {
                contador++;
            }
            if (contador < n) {
                numeroPrimo++;
            }
        }
        cout<<"El primo numero "<<n<<" es: "<<numeroPrimo<< endl;

         break;
    }

    case 11:

         //Problema 11
     {
        int n;
        cout<<"Ingrese un numero entero: ";
        cin>>n;
        int mcm = 1;
        for (int i=2; i<=n; i++) {
            int a=mcm;
            int b=i;
            while (b!=0) {
                int temp=b;
                b=a%b;
                a=temp;
            }
            mcm=(mcm*i)/a;
        }
        cout<<"El minimo comun multiplo es: "<<mcm<<endl;

         break;
    }

    case 12:

         //Problema 12
     {
        int numero;
            cout << "Ingrese un numero: ";
            cin >> numero;
            int n = numero;
            int mPrimo = 2;
            while (numero>1) {
                if (numero%mPrimo==0) {
                    while (numero%mPrimo==0) {
                        numero/=mPrimo;
                    }
                }
                mPrimo++;
            }
            mPrimo--;
            cout<<"El mayor factor primo de "<<n<<" es: "<<mPrimo<<endl;
         break;

    }
    case 13:

         //Problema 13
     {
        int numero;

        cout<<"Ingrese un número: ";
        cin>>numero;
        int suma = 0;
        for (int i=2; i<numero; i++) {
            bool esPrimo = true;
            if (i <= 1) {
                esPrimo = false;
            } else if (i <= 3) {
                esPrimo = true;
            } else if (i%2==0 || i%3==0) {
                esPrimo = false;
            } else {
                for (int j=5; j*j<=i; j+=6) {
                    if (i%j==0 || i%(j+2)==0) {
                        esPrimo = false;
                        break;
                    }
                }
            }
            if (esPrimo) {
                suma+=i;
            }
        }
        cout<<"El resultado de la suma es: "<<suma<<endl;
        break;
    }

    case 14:

         //Problema 14
     {
        int n=0;
        int n1=0;
        int n2=0;
        for (int i=100; i<1000; i++) {
            for (int j=100; j<1000; j++) {
            int producto=i*j;
            int original=producto;
            int inverso=0;
            while (producto>0) {
                inverso=inverso*10+producto%10;
                producto/=10;
            }
            if (original==inverso && original>n) {
                n=original;
                n1=i;
                n2=j;
            }
          }
        }
        cout<<n1<<"*"<<n2<<"="<<n<<endl;
        break;


    }
    case 15:

         //Problema 15
     {
        int n;
        cout<<"Ingrese un número impar n: ";
        cin>>n;

        if (n%2==0) {
            cout << "El número ingresado no es impar. Debe ser un número impar."<<endl;
            return 1;
        }
        int sumaDiagonal = 1;
        int valor = 1;
        int incremento = 2;
        for (int i=1; i<=n/2; i++) {
            for (int j = 0; j<4; j++) {
                valor += incremento;
                sumaDiagonal+=valor;
            }
            incremento+=2;
        }
        cout<<"En una espiral de "<<n<<"x"<<n<<", la suma es: "<<sumaDiagonal<<endl;

         break;
    }

}
}
}
