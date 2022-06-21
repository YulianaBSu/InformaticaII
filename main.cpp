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
              for (int i=0;i<7;i++)//i es el contador, inicia en 0, va hasta el 7 (va de 0 a 6) el 7 es porque son 7 filas e incrementa de 1 en 1
          // el for de afuera está contando las filas
              {
                  letra=65; // Para que cada vez que inicie el ciclo lo empiece en A
                  for(int j=0;j<=i;j++)//Desde que j empiece en 0 hasta que j sea menor o igual a i e incrementa de 1 en 1
                  {
                      cout << letra;//imprimo la A
                      letra++; // incrementa la letra, osea que en cada ciclo la letra cambia de A-B-C-D...
                  }
                  for(int j=11-2*i;j>0;j--) //Hasta que decremente y sea mayor a 0
                  {
                      cout<<' ';
                  }
                  letra=65+i;
                  for(int j=0;j<=i;j++)
                  {
                      if(letra!='G')// Si la letra es diferente de G la imprime, sino lo omite (la G solo está una vez y se puso en el primer ciclo)
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
