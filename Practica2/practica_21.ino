int opc = 0;

void combinacion(long cantidad){
  long denominaciones[]={50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
  long cantidades[10]={0};
  long total;
  
  for (int i=0; i<10; i++){
    total=cantidad/denominaciones[i];
    cantidad%=denominaciones[i];
    
    Serial.print(denominaciones[i]);
    Serial.print(": ");
    Serial.println(total);
  }

  Serial.print("Faltante: ");
  Serial.println(cantidad);
}


void convmay(char* cadena) {
  for (int i = 0; cadena[i] != '\0'; i++) {
    if (cadena[i] >= 'a' && cadena[i] <= 'z') {
      cadena[i] = cadena[i] - 'a' + 'A';
    }
  }
}


int convromano(String nromano) {
    int total = 0;
    int longitud = nromano.length();
    int vanterior = 0;
    for (int i = longitud - 1; i >= 0; i--) {
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


int sumadivisores(int num) {
    int suma = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            suma += i;
        }
    }
    return suma;
}

int amigables(int limite) {
    int total = 0;
    for (int i = 1; i < limite; i++) {
        int sumadiv = sumadivisores(i);
        if (i != sumadiv && sumadivisores(sumadiv) == i) {
            total += i;
        }
    }
    return total;
}



void menu(){
  Serial.println("MENU PRINCIPAL");
  Serial.println("1. Problema 1: Combinacion billetes y monedas");
  Serial.println("2. Problema 6: Cambio a mayusculas");
  Serial.println("3. Problema 10: Conversion de numeros romanos");
  Serial.println("4. Problema 17: Numeros amigables");
  Serial.println("Ingrese una opcion: ");
}




void setup() {
    Serial.begin(9600);
}


void loop() {
  menu();
  while (Serial.available() == 0);
  opc = Serial.parseInt();
  
  if(opc==1){
  long pesos;
  Serial.println("Ingrese la cantidad en pesos:");
  while (!Serial.available()) {}
  pesos = Serial.parseInt();
  combinacion(pesos);
  while (Serial.available()) {
  Serial.read();
  }
}
  
  else if(opc==2){
  char cadena[100];
  Serial.println("Ingrese una cadena de caracteres: ");
  while (!Serial.available()); 
  Serial.readBytesUntil('\n', cadena, 100);

  Serial.print("Original: ");
  Serial.print(cadena);

  convmay(cadena);

  Serial.print(". En mayuscula: ");
  Serial.println(cadena);
}
  
  else if(opc==3){
  String nrorom;

  Serial.println("Ingrese un numero del sistema romano: ");
  while (!Serial.available());
  nrorom = Serial.readStringUntil('\n');

  int varabigo = convromano(nrorom);

  Serial.print("El numero ingresado fue: ");
  Serial.print(nrorom);
  Serial.print(". Que corresponde a: ");
  Serial.println(varabigo);
  
}
  
  else if(opc==4){
  Serial.println("Ingrese un numero:");    
  while (!Serial.available()) {}    
  int numero = Serial.parseInt();
  int sumamigables = amigables(numero);
  Serial.print("La suma de los numeros amigables menores a ");
  Serial.print(numero);
  Serial.print(" es: ");
  Serial.println(sumamigables);
 }
}
