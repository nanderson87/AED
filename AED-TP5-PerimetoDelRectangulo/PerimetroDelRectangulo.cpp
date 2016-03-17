/*
* TP#5 Perimetro del rectangulo  
* Nombre: Nicolás Anderson
* Curso: K1051
* Fecha: 11-05-2015
* Versión: 1.0.0
* Programa para calcular el perimetro de un rectangulo a partir de la utilización de funciones
*/


#include <iostream>
#include <cstring> 


// DEFINE FUNCION clearPantalla SEGUN SO ( WINDOWS o LINUX )
#ifdef WIN32 
#define clearPantalla() system("cls"); 
#else 
#define clearPantalla() system("clear"); 
#endif 
 

using namespace std;


//PROTOTIPOS DE FUNCIONES
double getNumeroPositivo();		// prototipo de la función - getNumeroPositivo
double getPerimetroRectangulo( double altura, double base );		// prototipo de la función - getPerimetro
bool compararDistancias( double altura , double base );		// prototipo de la funcion - compararDistancia 
int controlRespuestaUsuario ( char input_usuario , string pregunta );		// prototipo de la función - controlRespuestaUsuario
void excepcion( int id_excepcion );		// prototipo de la función - excepcion



int main( ) {
	
	int h = 0;
	int b = 0;
	bool sale = false;
	int cant_calculos = 0;
	char input;
	
	while ( sale == false ) {
		
		clearPantalla();
		cout << "\n";
		cout << "\t\t   *** CALCULO DEL PERIMETRO DE UN RECTANGULO *** " << endl;
		cout << "\t\t ==================================================\n" << endl;
		cout << "1. Ingrese la altura del rectangulo en cm: ";
		h = getNumeroPositivo();
		cout << "2. Ingrese la base del rectangulo en cm: ";
		b = getNumeroPositivo();
		cout << "\n\n--------------------------------------" << endl; 
		cout << "--------------------------------------" << endl;
		cout << "* Distancia altura: " << h << " cm" << endl;
		cout << "* Distancia base: " << b << " cm" << endl;
		cout << "> Perimetro del rectanagulo[P = 2*(b+h)]: " << getPerimetroRectangulo ( h, b ) << " cm" << endl; 
	
		if ( compararDistancias( h, b ) ) {
			
			cout << "Obs.: Ingreso un caso particular de rectangulo, el \"cuadrado\"." << endl;
					
		}
		
		cout << "--------------------------------------" << endl; 
		cout << "--------------------------------------\n\n" << endl;
		

		cant_calculos++;
		cout << "\n\n";
		
		cout << "Desea calcular otro perimetro [Y/N]?: ";
		cin >> input ;
		switch ( controlRespuestaUsuario ( input , "Desea calcular otro perimetro [Y/N]?: " ) ) {
			
			case 1:
				sale = false;
				break;
				
			case 2:
				sale = true;
				break;
			
		}
		
	}
	
	clearPantalla();
	cout << ">> Resumen " << endl;
	cout << "Total de perimetros calculados: " << cant_calculos << "\n\n" << endl;	
	
} // fin  de la funcion main.


double getNumeroPositivo() {

	double num;
	cin >> num;
	
	
	while ( num <= 0 )  {
		
		excepcion( 1 );
		cout << "Ingrese nuevamente la distancia: ";
		cin >> num;
	
	} 
	
	return num;
	
} // Fin de la funcion getNumeroPositivo


double getPerimetroRectangulo ( double altura, double base ) {
	
	double perimetro;
	perimetro = 2 * ( altura + base );    
	return perimetro;


} // Fin de la funcion getPerimetroRectangulo 


bool compararDistancias( double altura , double base ) {
	
	if ( altura == base ) {
		
		return true;
		
	} else {
		
		return false;
	}
	

} // Fin compararDistancias


int controlRespuestaUsuario ( char input_usuario , string pregunta ) {
	
	while ( ( input_usuario != 'Y' ) && ( input_usuario != 'y' ) && ( input_usuario != 'N' ) && ( input_usuario != 'n' ) ) {
		

		excepcion ( 2 );
		cout << pregunta;
		cin >> input_usuario;
		
	}
	
	if ( input_usuario == 'Y' ) {
		
		return 1;
	
	}
	
	if ( input_usuario == 'y' ) {
		
		return 1;
	
	}
		
	if ( input_usuario == 'N' ) {
		
		return 2;
	
	}
	
	if ( input_usuario == 'n' ) {
		
		return 2;
	
	}

} // Fin funcion controlRespuestaUsuario


void excepcion ( int id_excepcion ) {
	
	
	switch ( id_excepcion ) {
		
		case 1:		//Valor de distancia incorrecta
			cout << "\n";
			cout << "Cod.Ref: " << id_excepcion  << endl;
			cout << "Desc.Excepcion: El valor de la distancia ingresada no es valido.\n" << endl;
			cout << "Ayuda: Las distancias son valores numericos reales no negativos. En este caso, tambien, deben ser mayores al valor cero\n\n" << endl; 
			break;
		
		case 2:		//Respuesta del usuario no incorrecta
			cout << "\n";
			cout << "Cod.Ref: " << id_excepcion << endl;
			cout << "Desc.Excepcion: El valor de respuesta ingresado no es el esperado.\n" << endl;
			cout << "Ayuda: Se esperaban los valores 'N' o 'Y'.\n\n" << endl; 			
			break;
	
	}

} // Fin funcion excepcio
