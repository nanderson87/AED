/*
* TP#2 Par  
* Nombre: Nicolás Anderson
* Curso: K1051
* Fecha: 23-04-2015
* Versión: 1.0.0
* Programa para Ddtermina si un numero entero es par
*/


#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void determinarpar ( int a ); // prototipo de la funcion

int cpar = 0;							//contador de numeros impares introducidos
int cimpar = 0;						//contador de numeros pares introducidos


int main ()

{
		
	int entero1;  					//numero introducidos
	int contador;					//contador de numeros introducidos	
	char centinela;  				//valor centinela
	
	centinela = ('S');			//inicializacion de la variable centinela
	contador = 0;					//inicializacion de la variable contador
	

	cout << "DETERMINA SI UN NUMERO ES PAR " << endl;
	cout << "========================================== \n\n";
	
	while ( (centinela == 's') || (centinela == 'S') ) {
		
		cout << "Introduzca un numero entero: ";
		cin >> entero1;
		contador++;
		determinarpar (entero1);
		cout << "\n";
		cout << "Desea introducir otro numero?(S/N):";
		cin >> (centinela);
		
		while ( (centinela != 'n') && (centinela != 'N') && (centinela != 's') && (centinela != 'S') ) {
			
			cout << "El valor ingresado no es correcto, se esperaba el valor 'S' o el valor 'N'" << endl;
			cout << "Desea introducir otro numero?(S/N):";
			cin >> (centinela);
			
		
		} // Fin del While interno	
		
		cout << endl;

	} // Fin del While externo
	
	cout << "\n\n";
	cout << ">>> Resumen \n\n";	
	cout << "Total de numeros introducidos: " << contador << endl;
	cout << "Total de numeros pares: " << cpar << endl;
	cout << "Total de numeros impares: " << cimpar << endl;

} // fin  de la funcion main.


void determinarpar (int a)
{
	if ( a%2 == 0 ) {
		
		cout << "El numero " << a << " es par." << endl;
		cpar++;
		
	} // fin del if
	
	else {
		
		cout << "El numero " << a << " es impar." << endl;
		cimpar++;
		
	} // fin del else
	
} //fin funcion enteropar
