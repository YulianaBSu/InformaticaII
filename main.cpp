#include <iostream>
#include <cmath>
using namespace std;


//PRACTICA 0

int main()
{
    int opcion=1;
    while(opcion !=0)
    {
      cout <<" "<<endl;
      cout <<"Ingrese una opcion"<<endl;
      cout <<"1. Ejercicio 1 "<<endl;
      cout <<"2. Ejercicio 2 "<<endl;
      cout <<"Presione cualquier tecla para salir"<<endl;
      cin>>opcion;
      switch (opcion){
      {
       case 1:
              {
          char letra=65;
              for (int i=0;i<7;i++)
              {
                  letra=65;
                  for(int j=0;j<=i;j++)
                  {
                      cout << letra;
                      letra++;
                  }
                  for(int j=11-2*i;j>0;j--)
                  {
                      cout<<' ';
                  }
                  letra=65+i;
                  for(int j=0;j<=i;j++)
                  {
                      if(letra!='G')
                      cout << letra;
                      letra--;
                  }
                 cout<<endl;
              }
              for (int i=0;i<6;i++)
              {
                  letra=65;

                  for(int j=1;j<=6-i;j++)
                  {
                      cout<<letra;
                      letra++;
                  }

                  for(int j=0;j<=2*i;j++)
                  {
                      cout<<' ';
                   }
                  letra=letra-1;
                  for(int j=1;j<=6-i;j++)
                  {
                      cout<<letra;
                      letra--;
                  }

                  cout<<endl;
              }
              break;
      }
      case 2:
      {
          int numero,residuo,i;
              double result=0,potencia=0;
              cout<<"Ingrese un numero: ";
              cin>>numero;

              while(numero>0)
              {
                  residuo= numero%10;
                  numero=numero/10;
                  for(i=1;i<=1;i++){
                      potencia=pow(residuo,residuo);
                      result+=potencia;
                  }
              }

              cout<<endl<<"El resultado es: "<<result<<endl;
                }
          break;
      }
        default:
          if(opcion!=0)
          cout<<"opción no válida"<<endl;
        }
}
    return 0;
}
