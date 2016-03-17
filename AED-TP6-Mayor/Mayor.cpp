/*
* TP#6 Mayor  
* Nombre: Nicolás Anderson
* Curso: K1051
* Fecha: 21-05-2015
* Versión: 1.0.0
* Programa para ordener y encontrar el mayor numero entre un conjunto de numeros dados 
*/


#include <iomanip>
#include <iostream>
using namespace std;


//PROTOTIPOS DE FUNCIONES
void ordenarArreglo ( int arreglo[] , int size_arreglo );		// prototipo de la funcion - ordenarArrglo 



int main () {

	int size_arreglo;  
	int input;
	
	cout << "\n";
	cout << "\t\t   *** ORDENAMIENTO DE UN ARREGLO *** " << endl;
	cout << "\t\t ==================================================\n" << endl;
	cout << "Ingrese el tamanio de elementos del conjunto que quiere ordenar: ";
	cin >> size_arreglo;
	cout << endl;
	
	int arreglo[size_arreglo];
	
	for ( int i = 0 ; i < size_arreglo  ; i++ ){
		
			cout << "Ingrese el " << i+1 << " numero: ";
			cin >> input; 
			arreglo [i] = input;
	
	} 
	
	cout << "\nArreglo desordenado:\n";
	
	for ( int i = 0; i < size_arreglo; i++ ) {
		
		cout << setw( 5 ) << arreglo[ i ];
		
	}
	
	
	ordenarArreglo ( arreglo, size_arreglo );
	
	
	cout << "\n\nArreglo ordenado en forma ascendente:\n";
	
   for ( int i = 0; i < size_arreglo; i++ ) {
   	
   	cout << setw( 5 ) << arreglo[ i ];
   	
	}
      
   cout << "\n\nMayor numero ingresado:\n";
   cout << setw ( 5 ) <<arreglo[ size_arreglo - 1 ];
	

}  //Fin funcion main.


void ordenarArreglo ( int arreglo[] , int size_arreglo ) 		// Ordenamiento de un arreglo mediante el ordenamiento por inserción
{
	
	int insertar;
	
	for ( int siguiente = 1; siguiente < size_arreglo; siguiente++ ) {
		
      insertar = arreglo[ siguiente ]; 
     	int moveItem = siguiente; 
	       
      while ( ( moveItem > 0 ) && ( arreglo[ moveItem - 1 ] > insertar ) ) {
      	
         arreglo[ moveItem ] = arreglo[ moveItem - 1 ];
         moveItem--;
         
      } 
   
      arreglo[ moveItem ] = insertar; 
      
   } 
   
} //Fin funcion ordenarArreglo




 
