/*
* TP#1 Tipos de Datos  
* Nombre: Nicolás Anderson
* Curso: K1051
* Fecha: 23-04-2015
* Versión: 1.0.0
* Muestra los diferentes tipos de datos y sus operaciones
*/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main ()
{
	
	//Declaracion de Variables
	int entero1;
	int entero2;
	
	cout << "*** TIPOS DE DATOS Y SUS OPERACIONES *** \n\n";
	
	cout << ">>> Tipo de dato: bool" << endl;
	cout << "1. Valor de la proposicion (Verdadero o Verdadero) " << endl;
	cout << "Valor: "  << true || true; 
	cout << "\n";
	cout << "2. Valor de la proposicion (Falso y Verdadero) " << endl;
	cout << "Valor: " << false && true;
	cout << "\n";
	cout << "3. Valor de la proposicion (!Falso) " << endl;
	cout << "Valor: " << !false;
	cout << "\n\n";
	
	
	cout << ">>> Tipo de dato: char" << endl;
	cout << "1. Comparacion de dos caracteres ('a' & 'b') " << endl;
	
	if ( 'a' != 'b' ) {
		
		cout << "El caracter 'a' no es igual al caracter 'b'" << endl; 
		
	} // Fin del if
	
	cout << "\n\n";
	
	
	cout << ">>> Tipo de dato: int " << endl;
	cout << "1. Suma de tres numeros enteros (10 + 30 + 209) " << endl;
	cout << "Resultado: " << 10 + 30 + 209 << "\n";
	cout << "2. Resta de dos numeros enteros (55 - 105)" << endl;
	cout << "Resultado: " << 55 - 105 << "\n";
	cout << "3. Comparacion de dos numeros enteros " << endl;
	cout << "	Ingrese el primer numero entero: ";
	cin >> entero1;
	cout << "	Ingrese el segundo numero entero: ";
	cin >> entero2;
	
	if ( entero1 > entero2) {
	
		cout << "El numero entero " << entero1 << " es mayor al numero entero " << entero2 << endl;

	} // fin del if
	
	else {
	
		cout << "El numero entero " << entero2 << " es mayor o igual al numero entero " << entero1 << endl; 
		
	} //fin del else
	
	cout << "4. Operacion modulo con dos numeros enteros" << endl;
	cout << "	Ingrese el primer numero entero: ";
	cin >> entero1;
	cout << "	Ingrese el segundo numero entero: ";
	cin >> entero2;
	cout << "El resultado de " << entero1 << "%" << entero2 << " es: " << entero1%entero2 << endl;
	cout << "\n\n";
	
	
	cout << "> float " << endl;
	cout << "1. Suma de tres numeros reales (10.5 + 30.8 + 209.01) " << endl;
	cout << "Resultado: " << 10.5 + 30.8 + 209.01 << "\n";
	cout << "2. Resta de dos numeros reales (55.008 - 105.5)" << endl;
	cout << "Resultado: " << 55.008 - 105.5 << "\n";
	cout << "\n\n";
		
	
	cout << "> string " << endl;
	cout << "1. Ejemplo de concatenacion de cadenas: " << endl;
	cout << "Esto " << "es una concatenacion " << "de cadenas" << endl;

} // fin  de la funcion main.
