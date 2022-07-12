#include <iostream>

using namespace std;

int main()
{
    int opcion=1;
    while(opcion!=0)
    {
    cout<<"\nMenu principal, ingrese una de las opciones disponibles o presione cualquier tecla para salir\n "<<endl;
    cout<<"1. Problema 2 "<<endl;
    cout<<"2. Problema 5 "<<endl;
    cout<<"3. Problema 15 "<<endl;
    cout<<"4. Decodificador de permisos en Linux "<<endl;
    cout<<"\nSeleccione una opcion: ";

    cin>>opcion;
    switch (opcion) {

    case 1:

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


    case 2:
        //Problema 5
    {
        int base;
        do{
        cout<<"Ingrese cantidad de * en el medio del rombo: ";
        cin>>base;
        }while(base%2==0 ||base<=0);

        int b=base/2;
        int cont=1;
        bool band=true;
        for(int i=0;i<base;i++){
            for(int i=0;i<b;i++)
                cout<<" ";
            for(int i=0;i<cont;i++)
                cout<<"*";
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

    case 3:
        //Problema 15
    {
        int n;
        cout<<"Digite el numero de elementos: ";
        cin>>n;
        cout<<n;
        break;
     }


      return 0;
    }
    }
}
