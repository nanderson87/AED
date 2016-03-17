/*
* TP#3 Juego de Preguntas  
* Nombre: Nicolás Anderson
* Curso: K1051
* Fecha: 04-05-2015
* Versión: 1.0.0
* Programa de Juego de Preguntas
*/


#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string> 
#include <limits>   

// DEFINE FUNCION clearPantalla SEGUN SO ( WINDOWS o LINUX )
#ifdef WIN32 
#define clearPantalla() system("cls"); 
#else 
#define clearPantalla() system("clear"); 
#endif 
 
 
using namespace std;

//PROTOTIPOS DE FUNCIONES
void menuPrincipal();		// prototipo de la función - Menu Principal
void menuCategoria();		// prototipo de la función - Sub Menu Seleccion de Categorias
void cuestTiposDeDatos();		// prototipo de la función - Cuestionario Tipos de Datos C++
void cuestOperadores();		// prototipo de la función - Cuestionario Operadores de c++
void cuestProcedenciaDeOperadores();		// prototipo de la función - Cuestionario Procedencia de Operadores C++
void cuestConjuntoDeCaracteresASCII();		// prototipo de la función - Cuestionario Conjunto de Caracteres ASCII
void cuestBibleotecaEstandar();		// prototipo de la función - Cuestionario Bibleoteca Estandar C++
void cuestConceptosBasicosAED();		// prototipo de la función - Cuestionario Conceptos Basicos Algoritmo y Estructura de Datos (AED)
void puntuacion( bool sale);		// prototipo de la función - Sub Menu Puntuacion y Estadisticas
void comoJugar();		// prototipo de la función - Sub Menu Como Jugar
void reglas();		// prototipo de la función - Sub Menu Reglas
void acercaDe();		// prototipo de la función -  Sub Menu Acerca De
void excepcion ( int nro_excepcion );		// prototipo de la función - Manejo de Excepciones en el programa
void controlPuntuacion (int id_categoria, bool entro_categ, bool acerto, bool reset_puntos );		// prototipo de la función - Manejo de la puntuacion en el programa
void mezclarOrdenPreguntas();		// prototipo de la funcion - Mezclar el orden de la aparicion de las preguntas en las diferentes categorias
void mezclarOrdenRespuestas();		//prototipo de la funcion - Mezcalar las respuestas de las diferentes preguntas 
void finDelJuego(bool gano);

//VARIABLES CONSTANTES
const int TAMANIOPREGUNTAS = 10;		//Tamañio de preguntas por categoria
const int TAMANIORESPUESTAS = 3;		// Tamañio de respuestas por pregunta

//VARIABLES GLOBALES
int orden_preguntas[TAMANIOPREGUNTAS];			//Arreglo donde se guardaran aleatoriamente el orden de las preguntas para cada categoría 
int orden_respuestas[TAMANIORESPUESTAS]; 		//Arreglo donde se guardaran aleatoriamente el orden de las posibles respuesta para cada pregunta
bool acerto;											
bool reset_puntos;
bool sale = false;
bool gano = false;

// *** contadores e inicialización*** 
int cont_aciertos_tiposdedatoscpp = 0;		//Contador de aciertos categoría Tipos de Datos C++ 
int cont_vjugadas_tiposdedatoscpp = 0;		//Contador de veces jugadas categoría Tipos de Datos C++
int cont_aciertos_operadorescpp = 0;		//Contador de aciertos categoría Operadores C++
int cont_vjugadas_operadorescpp = 0;		//Contador de veces jugadas categoría Operadores C++ 
int cont_aciertos_procoperadorescpp = 0;		//Contador de aciertos categoría Procedencia de Operadores C++
int cont_vjugadas_procoperadorescpp = 0;		//Contador de veces jugadas categoría Procedencia de Operadores C++
int cont_aciertos_ccaractascii = 0;		//Contador de aciertos categoría Conjunto de Caracteres ASCII
int cont_vjugadas_ccaractascii = 0;		//Contador de veces jugadas categoría Conjunto de Caracteres ASCII
int cont_aciertos_bibestandarcpp = 0;		//Contador de aciertos categoría Bibleoteca Estandar C+++
int cont_vjugadas_bibestandarcpp = 0;	//Contador de veces jugadas categoría Bibleoteca Estandar C+++
int cont_aciertos_concpbasaed = 0;		//Contador de aciertos categoría Conceptos Basicos Algoritmo y Estructura de Datos (AED)
int cont_vjugadas_concpbasaed = 0;		//Contador de veces jugadas categoría Conceptos Basicos Algoritmo y Estructura de Datos (AED)
int cont_aciertos_total = 0;		//Contador de aciertos total 
int cont_naciertos_total = 0;		//Contador de desaciertos total 



//-----------------------
//-----------------------


int main() {

	menuPrincipal();
		
} // fin  de la funcion main.


void menuPrincipal() {
 
	clearPantalla();
	int input;
	
	cout << "\n";
	cout << "\t\t\t *** JUEGO DE PREGUNTAS *** " << endl;
	cout << "\t\t ==========================================\n" << endl;
	cout << "> Pon a prueba tus conocimiento sobre el lenguaje de programacion C++" << endl;
	cout << "y sobre la materia Algoritmo y Estructura de Datos (AED).\n\n\n\n" << endl;
	cout << "[1]. Seleccionar categoria de preguntas" << endl;
	cout << "[2]. Ver puntuacion y estadisticas" << endl;
	cout << "[3]. Como jugar?" << endl;
	cout << "[4]. Reglas" << endl;
	cout << "[5]. Acerca de Juego de Preguntas" << endl;
	cout << "\n\n";
	cout << "[9]. Salir\n";
	
	for ( int i = 0 ; i < 7 ; i ++ ) {
		
		cout << "\n";

	}
	
	cout << "Ingrese el numero menu y presionando intro: ";
	cin >> input;
	
	switch ( input ) {
		
		case 1:
			menuCategoria();
			break;
		
		case 2:
			sale = false;
			puntuacion( sale );
			break;
		
		case 3:
			comoJugar();
			break;
		
		case 4:
			reglas();
			break;
		
		case 5:
			acercaDe();
			break;
			
		case 9:
			finDelJuego( gano );
			break;
		
		default:
			excepcion( 1 );
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			cin.clear();
			menuPrincipal();
			break;

	} //Fin switch

} //Fin funcion menuPrincipal


void menuCategoria() { 
	
	clearPantalla();
	int input;
	bool gano;
	
	if ( cont_aciertos_total == (TAMANIOPREGUNTAS * 6) ) {
		
		gano = true;
		finDelJuego( gano ) ;
		
	} else {
		
		cout << "\n";
		cout << "SELECCIONE UNA CATEGORIA" << endl;
		cout << "===================================\n\n\n\n\n" << endl;
	
		if ( cont_aciertos_tiposdedatoscpp > 0 ) {
			
			if ( cont_aciertos_tiposdedatoscpp == TAMANIOPREGUNTAS ) {
				
				cout << "[1]. Tipos de datos C++ \t --> [Puntaje: " << cont_aciertos_tiposdedatoscpp << "/" << TAMANIOPREGUNTAS << "] (COMPLETA!)" << endl;
				
			} else {
				
				cout << "[1]. Tipos de datos C++ \t --> [Puntaje: " << cont_aciertos_tiposdedatoscpp << "/" << TAMANIOPREGUNTAS << "]" << endl;
				
			}
	
		} else {
			
			cout << "[1]. Tipos de datos C++" << endl;
			
		}
		
		if ( cont_aciertos_operadorescpp > 0 ) {
			
			if ( cont_aciertos_operadorescpp == TAMANIOPREGUNTAS ) {
				
				cout << "[2]. Operadores C++ \t --> [Puntaje: " << cont_aciertos_operadorescpp << "/" << TAMANIOPREGUNTAS << "] (COMPLETA!)" << endl;
				
			} else {
				
				cout << "[2]. Operadores C++ \t --> [Puntaje: " << cont_aciertos_operadorescpp << "/" << TAMANIOPREGUNTAS << "]" << endl;
				
			}
	
		} else {
			
			cout << "[2]. Operadores C++" << endl;
			
		}
	
		if ( cont_aciertos_procoperadorescpp > 0 ) {
			
			if ( cont_aciertos_procoperadorescpp == TAMANIOPREGUNTAS ) {
				
				cout << "[3]. Precedencia de operadores C++ \t --> [Puntaje: " << cont_aciertos_procoperadorescpp << "/" << TAMANIOPREGUNTAS << "] (COMPLETA!)" << endl;
				
			} else {
				
				cout << "[3]. Precedencia de operadores C++ \t --> [Puntaje: " << cont_aciertos_procoperadorescpp << "/" << TAMANIOPREGUNTAS << "]" << endl;
				
			}
	
		} else {
			
			cout << "[3]. Precedencia de operadores C++" << endl;
			
		}
	
		if ( cont_aciertos_ccaractascii > 0 ) {
			
			if ( cont_aciertos_ccaractascii == TAMANIOPREGUNTAS ) {
				
				cout << "[4]. Conjunto de Caracteres ASCII \t --> [Puntaje: " << cont_aciertos_ccaractascii << "/" << TAMANIOPREGUNTAS << "] (COMPLETA!)" << endl;
				
			} else {
				
				cout << "[4]. Conjunto de Caracteres ASCII \t --> [Puntaje: " << cont_aciertos_ccaractascii << "/" << TAMANIOPREGUNTAS << "]" << endl;
				
			}
	
		} else {
			
			cout << "[4]. Conjunto de Caracteres ASCII" << endl;
			
		}
	
		if ( cont_aciertos_bibestandarcpp > 0 ) {
			
			if ( cont_aciertos_bibestandarcpp == TAMANIOPREGUNTAS ) {
				
				cout << "[5]. Bibleoteca estandar de C++ \t --> [Puntaje: " << cont_aciertos_bibestandarcpp << "/" << TAMANIOPREGUNTAS << "] (COMPLETA!)" << endl;
				
			} else {
				
				cout << "[5]. Bibleoteca estandar de C++ \t --> [Puntaje: " << cont_aciertos_bibestandarcpp << "/" << TAMANIOPREGUNTAS << "]" << endl;
				
			}
	
		} else {
			
			cout << "[5]. Bibleoteca estandar de C++" << endl;
			
		}
	
		if ( cont_aciertos_concpbasaed > 0 ) {
			
			if ( cont_aciertos_concpbasaed == TAMANIOPREGUNTAS ) {
				
				cout << "[6]. Conceptos Basicos AED \t --> [Puntaje: " << cont_aciertos_concpbasaed << "/" << TAMANIOPREGUNTAS << "] (COMPLETA!)" << endl;
				
			} else {
				
				cout << "[6]. Conceptos Basicos AED \t --> [Puntaje: " << cont_aciertos_concpbasaed << "/" << TAMANIOPREGUNTAS << "]" << endl;
				
			}
	
		} else {
			
			cout << "[6]. Conceptos Basicos AED" << endl;
			
		}
	
		cout << "\n\n";
		cout << "[8]. Atras" << endl; 
		cout << "[9]. Salir" << endl;
		
		for ( int i = 0 ; i < 6 ; i ++ ) {
			
			cout << "\n";
			
		}
		
		cout << "Seleccione la categoria ingresando el numero: ";
		cin >> input;
		
		switch (input) {
			
			
			case 1:
				if ( cont_aciertos_tiposdedatoscpp == TAMANIOPREGUNTAS ) {
				   
				   excepcion ( 2 );
					menuCategoria();
				
				} else {
					
					if ( cont_aciertos_tiposdedatoscpp > 0 ) {
						
						controlPuntuacion (1, true, false, true );
						excepcion ( 3 );
						mezclarOrdenPreguntas();
						cuestTiposDeDatos();
						
					} else {
						
						controlPuntuacion ( 1, true, false, false );
						mezclarOrdenPreguntas();
						cuestTiposDeDatos();
					
					}
					
				}
				break;
			
			case 2:
				if ( cont_aciertos_operadorescpp == TAMANIOPREGUNTAS ) {
				   
				   excepcion ( 2 );
					menuCategoria();
				
				} else {
					
					if ( cont_aciertos_operadorescpp > 0 ) {
						
						controlPuntuacion ( 2, true, false, true );
						excepcion ( 3 );
						mezclarOrdenPreguntas();
						cuestOperadores();
						
					} else {
						
						controlPuntuacion ( 2, true, false, false );
						mezclarOrdenPreguntas();
						cuestOperadores();
					
					}
					
				}
				
				break;
				
			case 3:
				if ( cont_aciertos_procoperadorescpp == TAMANIOPREGUNTAS ) {
				   
				   excepcion ( 2 );
					menuCategoria();
				
				} else {
					
					if ( cont_aciertos_procoperadorescpp > 0 ) {
						
						controlPuntuacion ( 3, true, false, true );
						excepcion ( 3 );
						mezclarOrdenPreguntas();
						cuestProcedenciaDeOperadores();
						
					} else {
						
						controlPuntuacion ( 3, true, false, false );
						mezclarOrdenPreguntas();
						cuestProcedenciaDeOperadores();
					
					}
					
				}
				
				break;
	
				
			case 4:
				if ( cont_aciertos_ccaractascii == TAMANIOPREGUNTAS ) {
				   
				   excepcion ( 2 );
					menuCategoria();
				
				} else {
					
					if ( cont_aciertos_ccaractascii > 0 ) {
						
						controlPuntuacion ( 4, true, false, true );
						excepcion ( 3 );
						mezclarOrdenPreguntas();
						cuestConjuntoDeCaracteresASCII();
						
					} else {
						
						controlPuntuacion ( 4, true, false, false );
						mezclarOrdenPreguntas();
						cuestConjuntoDeCaracteresASCII();
					
					}
					
				}
				
				break;
				
			case 5:
				if ( cont_aciertos_bibestandarcpp == TAMANIOPREGUNTAS ) {
				   
				   excepcion ( 2 );
					menuCategoria();
				
				} else {
					
					if ( cont_aciertos_bibestandarcpp > 0 ) {
						
						controlPuntuacion ( 5, true, false, true );
						excepcion ( 3 );
						mezclarOrdenPreguntas();
						cuestBibleotecaEstandar();
						
					} else {
						
						controlPuntuacion ( 5, true, false, false );
						mezclarOrdenPreguntas();
						cuestBibleotecaEstandar();
					
					}
					
				}
				
				break;
			
			case 6:
				if ( cont_aciertos_concpbasaed == TAMANIOPREGUNTAS ) {
				   
				   excepcion ( 2 );
					menuCategoria();
				
				} else {
					
					if ( cont_aciertos_concpbasaed > 0 ) {
						
						controlPuntuacion ( 6, true, false, true );
						excepcion ( 3 );
						mezclarOrdenPreguntas();
						cuestConceptosBasicosAED();
						
					} else {
						
						controlPuntuacion ( 6, true, false, false );
						mezclarOrdenPreguntas();
						cuestConceptosBasicosAED();
					
					}
					
				}
				
				break;
			
			case 8:
				menuPrincipal();
				break;
			
			case 9:
				gano = false;
				finDelJuego( gano ) ;
				break;
			
			default:
				excepcion( 1 );
				cin.ignore( std::numeric_limits<streamsize>::max(),'\n' );
				cin.clear();
				menuCategoria();
				break;
	
		} //Fin switch interno

		
	} // Fin else 
	
	
} //FIn de la funcion menuCategoria


void cuestTiposDeDatos() {

	int respuesta_correcta;
	int input;
	char tecla;
	
	for ( int i = 0 ; i < TAMANIOPREGUNTAS ; i++ ) {
				
		switch ( orden_preguntas[i] ) {
			
			case 1:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: TIPOS DE DATOS C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes NO es un tipo de dato en C++?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. entero" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. char" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. float" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 1, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 1, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 2:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: TIPOS DE DATOS C++ " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes NO es un tipo de dato en C++?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. triple" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. int" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. double" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 1, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 1, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
				
			case 3:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: TIPOS DE DATOS C++ " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que operacion NO esta relacionado con el tipo de dato \"bool\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. >=" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. =" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. &&" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion (1, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 1, false, false, false );
					cout << "\nINCORRECTO" << endl;
					
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore( std::numeric_limits<streamsize>::max(),'\n' );
				cin.get();
				break;
				
			case 4:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: TIPOS DE DATOS C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que operacion NO esta relacionada con el tipo de dato \"char\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch (orden_respuestas[j]) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. *" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. +" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. ==" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) 
				{
					controlPuntuacion ( 1, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 1, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
			
			case 5:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: TIPOS DE DATOS C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que valores representa el tipo de dato \"int\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Numeros enteros" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Numeros reales" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Caracteres" << endl;
					 		break;
					 		
					 }
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 1, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 1, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 6:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: TIPOS DE DATOS C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que valores representa el tipo de dato \"string\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					switch ( orden_respuestas[j] ) {
					 	
						case 1:
					 		cout << "[" << j+1 << "]. Cadena de caracteres" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Valores logicos" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Numeros reales" << endl;
					 		break;
					 		
				  }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) 
				{
					controlPuntuacion ( 1, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 1, false, false, false );
					cout << "\nINCORRECTO" << endl;
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 7:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: TIPOS DE DATOS C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que valores representa el tipo de dato \"long\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {

					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Numeros reales" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Numeros enteros" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Numeros naturales con el cero" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 1, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 1, false, false, false );
					cout << "\nINCORRECTO" << endl;
					
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
				
			case 8:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: TIPOS DE DATOS C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que operacion esta relacionado con el tipo de dato \"bool\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. !" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. /" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. %" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 1, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 1, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
			
			case 9:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: TIPOS DE DATOS C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que operacion NO esta relacionado con el tipo de dato \"int\"?\n" << endl;
				mezclarOrdenRespuestas();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. ||" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. ==" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. %" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 1, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 1, false, false, false );
					cout << "\nINCORRECTO" << endl;
					
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 10:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: TIPOS DE DATOS C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes es un tipo de dato en C++?\n" << endl;
				mezclarOrdenRespuestas();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch (orden_respuestas[j]) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. float" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. real" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. booleano" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de la opcion: ";
				cin >> input;
				
				if ( input == respuesta_correcta) {
					
					controlPuntuacion ( 1, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 1, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
				
				
		} // Fin del switch
			
	} // Fin del For
	
	menuCategoria();

} //Fin de la funcion cuesTiposDeDatos


void cuestOperadores() {
	
	int respuesta_correcta;
	int input;
	char tecla;
	
	for ( int i = 0 ; i < TAMANIOPREGUNTAS ; i++ ) {
				
		switch ( orden_preguntas[i] ) {
			
			case 1:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes es el operador de \"asginacion\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. =" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. ==" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. +" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 2, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 2, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 2:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que tipo de operador es \"&&\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. AND logico" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. OR logico" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Negacion logica unaria" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 2, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 2, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
				
			case 3:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que tipo de operador es \"%\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Modulo" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Division" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Multiplicacion" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 2, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 2, false, false, false );
					cout << "\nINCORRECTO" << endl;
					
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore( std::numeric_limits<streamsize>::max(),'\n' );
				cin.get();
				break;
				
			case 4:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual es la asociatividad del operador \"!=\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch (orden_respuestas[j]) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Izquierda a derecha" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Derecha a izquierda" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Izquierda a izquierda" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) 
				{
					controlPuntuacion ( 2, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 2, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
			
			case 5:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que tipo de operador es \"==\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Igual que" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Asignacion" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. No es igual que" << endl;
					 		break;
					 		
					 }
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 2, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 2, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 6:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes operadores es UNARIO?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					switch ( orden_respuestas[j] ) {
					 	
						case 1:
					 		cout << "[" << j+1 << "]. !" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. =" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. >" << endl;
					 		break;
					 		
				  }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) 
				{
					controlPuntuacion ( 2, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 2, false, false, false );
					cout << "\nINCORRECTO" << endl;
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 7:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes operadores es TERNARIO?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {

					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. ?:" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. +=" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. ++" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 2, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 2, false, false, false );
					cout << "\nINCORRECTO" << endl;
					
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
				
			case 8:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes es el operador \"OR logico\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. ||" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. &&" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. *=" << endl;
					 		break;
					 		
					 } 
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 2, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 2, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
			
			case 9:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes NO es un operador de \"asignacion\"?\n" << endl;
				mezclarOrdenRespuestas();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. ==" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. *=" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. =" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 2, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 2, false, false, false );
					cout << "\nINCORRECTO" << endl;
					
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 10:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes NO es un operador de \"relacion\"?\n" << endl;
				mezclarOrdenRespuestas();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch (orden_respuestas[j]) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. >>" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. =>" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. <" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de la opcion: ";
				cin >> input;
				
				if ( input == respuesta_correcta) {
					
					controlPuntuacion (2, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 2, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
				
				
		} // Fin del switch
			
	} // Fin del For
	
	menuCategoria();
	
} // Fin funcion cuestOperadores


void cuestProcedenciaDeOperadores () {

	int respuesta_correcta;
	int input;
	char tecla;
	
//	cout << "\n";
//	cout << "CATEGORIA: PROCEDENCIA DE OPERADORES C++" << endl;
//	cout << "===================================\n\n" << endl;
	
	for ( int i = 0 ; i < TAMANIOPREGUNTAS ; i++ ) {
				
		switch ( orden_preguntas[i] ) {
			
			case 1:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: PROCEDENCIA DE OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que predencia tiene el operador \"()\" respecto del operador \"/\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Mayor" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Menor" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Igual" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 3, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 3, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 2:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: PROCEDENCIA DE OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que predencia tiene el operador \"*\" respecto del operador \"/\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Igual" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Mayor" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Menor" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 3, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 3, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
				
			case 3:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: PROCEDENCIA DE OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que predencia tiene el operador \"+\" respecto del operador \"-\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Igual" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Menor" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Mayor" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 3, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 3, false, false, false );
					cout << "\nINCORRECTO" << endl;
					
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore( std::numeric_limits<streamsize>::max(),'\n' );
				cin.get();
				break;
				
			case 4:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: PROCEDENCIA DE OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que predencia tiene el operador \"!\" respecto del operador \"&&\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch (orden_respuestas[j]) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Mayor" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Menor" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Igual" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) 
				{
					controlPuntuacion ( 3, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 3, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
			
			case 5:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: PROCEDENCIA DE OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que predencia tiene el operador \"=\" respecto del operador \"==\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Menor" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Mayor" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Igual" << endl;
					 		break;
					 		
					 }
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 3, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 3, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 6:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: PROCEDENCIA DE OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que predencia tiene el operador \"*=\" respecto del operador \"+=\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					switch ( orden_respuestas[j] ) {
					 	
						case 1:
					 		cout << "[" << j+1 << "]. Igual" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Mayor" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Menor" << endl;
					 		break;
					 		
				  }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) 
				{
					controlPuntuacion ( 3, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 3, false, false, false );
					cout << "\nINCORRECTO" << endl;
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 7:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: PROCEDENCIA DE OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que predencia tiene el operador \"||\" respecto del operador \"+=\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {

					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Mayor" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Menor" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Igual" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 3, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 3, false, false, false );
					cout << "\nINCORRECTO" << endl;
					
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
				
			case 8:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: PROCEDENCIA DE OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes operadores es el de MAYOR precendencia?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. ==" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. ||" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. =" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 3, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 3, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
			
			case 9:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: PROCEDENCIA DE OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes operadores es el de MENOR precedencia?\n" << endl;
				mezclarOrdenRespuestas();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. =" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. &&" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. %" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 3, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 3, false, false, false );
					cout << "\nINCORRECTO" << endl;
					
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 10:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: PROCEDENCIA DE OPERADORES C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que predencia tiene el operador \"%\" respecto del operador \">\"?\n" << endl;
				mezclarOrdenRespuestas();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch (orden_respuestas[j]) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Mayor" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Igual" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Menor" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de la opcion: ";
				cin >> input;
				
				if ( input == respuesta_correcta) {
					
					controlPuntuacion (3, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 3, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
				
				
		} // Fin del switch
			
	} // Fin del For
	
	menuCategoria();

} // Fin funcion cuestProcedenciaDeOperadores


void cuestConjuntoDeCaracteresASCII() {
	
	int respuesta_correcta;
	int input;
	char tecla;
	
//	cout << "\n";
//	cout << "CATEGORIA: PROCEDENCIA DE OPERADORES C++" << endl;
//	cout << "===================================\n\n" << endl;
	
	for ( int i = 0 ; i < TAMANIOPREGUNTAS ; i++ ) {
				
		switch ( orden_preguntas[i] ) {
			
			case 1:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONJUNTO DE CARACTERES ASCII  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que numero decimal representa el codigo de caracter \"F\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. 70" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. 18" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. 31" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 4, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 4, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 2:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONJUNTO DE CARACTERES ASCII  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que numero decimal representa el codigo de caracter \"1\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. 49" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. 120" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. 69" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 4, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 4, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
				
			case 3:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONJUNTO DE CARACTERES ASCII  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que codigo de caracter representa el numero decimal \"50\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. 2" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. q" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. +" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 4, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 4, false, false, false );
					cout << "\nINCORRECTO" << endl;
					
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore( std::numeric_limits<streamsize>::max(),'\n' );
				cin.get();
				break;
				
			case 4:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONJUNTO DE CARACTERES ASCII  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que numero decimal representa el codigo de caracter \"A\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch (orden_respuestas[j]) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. 65" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. 00" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. 75" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) 
				{
					controlPuntuacion ( 4, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 4, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
			
			case 5:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONJUNTO DE CARACTERES ASCII  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que numero decimal representa el codigo de caracter \"(\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. 40" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. 80" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. 20" << endl;
					 		break;
					 		
					 }
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 4, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 4, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 6:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONJUNTO DE CARACTERES ASCII  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que numero decimal representa el codigo de caracter \"W\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					switch ( orden_respuestas[j] ) {
					 	
						case 1:
					 		cout << "[" << j+1 << "]. 87" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. 22" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. 102" << endl;
					 		break;
					 		
				  }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) 
				{
					controlPuntuacion ( 4, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 4, false, false, false );
					cout << "\nINCORRECTO" << endl;
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 7:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONJUNTO DE CARACTERES ASCII  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que codigo de caracter representa el numero decimal \"121\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {

					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. y" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Y" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Z" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 4, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 4, false, false, false );
					cout << "\nINCORRECTO" << endl;
					
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
				
			case 8:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONJUNTO DE CARACTERES ASCII  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que codigo de caracter representa el numero decimal \"61\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. =" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. <" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. ?" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 4, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 4, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
			
			case 9:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONJUNTO DE CARACTERES ASCII  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que numero decimal representa el codigo de caracter \"m\"?\n" << endl;
				mezclarOrdenRespuestas();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. 109" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. 19" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. 93" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 4, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 4, false, false, false );
					cout << "\nINCORRECTO" << endl;
					
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 10:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONJUNTO DE CARACTERES ASCII  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que numero decimal representa el codigo de caracter \"sp (espacio/space)\"?\n" << endl;
				mezclarOrdenRespuestas();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch (orden_respuestas[j]) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. 32" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. 30" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. 31" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de la opcion: ";
				cin >> input;
				
				if ( input == respuesta_correcta) {
					
					controlPuntuacion ( 4, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 4, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
				
				
		} // Fin del switch
			
	} // Fin del For
	
	menuCategoria();

} // Fin funcion cuestConjuntoDeCaracteresASCII


void cuestBibleotecaEstandar() {
	
	int respuesta_correcta;
	int input;
	char tecla;
	
	for ( int i = 0 ; i < TAMANIOPREGUNTAS ; i++ ) {
				
		switch ( orden_preguntas[i] ) {
			
			case 1:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: BIBLEOTECA ESTANDAR DE C++ [BEC++]  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que explicacion define de mejor manera el archivo de encabezado \"iostream\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Contiene prototipos de funcion para las funciones de entrada y salida estandar" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Contiene prototipos de funcion y tipos para manipular fecha y hora" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Contiene macros e informacion para agregar diagnosticos que ayudan en la depuracion" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 5, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 5, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 2:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: BIBLEOTECA ESTANDAR DE C++ [BEC++] " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes es un archivo de encabezado de la BEC++?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. iostream" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. timeclock" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. stadio" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 5, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 5, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
				
			case 3:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: BIBLEOTECA ESTANDAR DE C++ [BEC++] " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes es un archivo de encabezado de la BEC++?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. limits" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. strang" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. funcionmath" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion (5, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 5, false, false, false );
					cout << "\nINCORRECTO" << endl;
					
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore( std::numeric_limits<streamsize>::max(),'\n' );
				cin.get();
				break;
				
			case 4:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: BIBLEOTECA ESTANDAR DE C++ [BEC++]  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que definicion define de mejor manera el archivo de encabezado \"string\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch (orden_respuestas[j]) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Contiene la definicion de la clase string de la bibleoteca estandar" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Contiene la definicion de la clase double de la bibleoteca estandar" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Contiene prototipos para funciones de graficacion" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) 
				{
					controlPuntuacion ( 5, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 5, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
			
			case 5:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: BIBLEOTECA ESTANDAR DE C++ [BEC++] " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que explicacion define de mejor manera el archivo de encabezado \"cmath\"?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Contiene prototipos de funcion de la bibleoteca de funciones matematicas" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Contiene prototipos de funcion para las funciones de entrada y salida estandar" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Contiene los limites del sistema para numeros enteros" << endl;
					 		break;
					 		
					 }
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 5, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 5, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 6:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: BIBLEOTECA ESTANDAR DE C++ [BEC++] " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes NO es un archivo de encabezado de la BEC++?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					switch ( orden_respuestas[j] ) {
					 	
						case 1:
					 		cout << "[" << j+1 << "]. cpointfloat" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. cmath" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. iostream" << endl;
					 		break;
					 		
				  }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) 
				{
					controlPuntuacion ( 5, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 5, false, false, false );
					cout << "\nINCORRECTO" << endl;
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 7:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: BIBLEOTECA ESTANDAR DE C++ [BEC++] " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes NO es un archivo de encabezado de la BSC++?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {

					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. flagexception" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. cfloat" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. string" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 5, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 5, false, false, false );
					cout << "\nINCORRECTO" << endl;
					
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
				
			case 8:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: BIBLEOTECA ESTANDAR DE C++ [BEC++] " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes es un archivo de encabezado de la BSC++?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. cassert" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. assert.ong" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. bibloassert" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 5, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 5, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
			
			case 9:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: BIBLEOTECA ESTANDAR DE C++ [BEC++] " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes es un archivo de encabezado de la BSC++?\n" << endl;
				mezclarOrdenRespuestas();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. ctime" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. cclockclock" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. inutility" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 5, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 5, false, false, false );
					cout << "\nINCORRECTO" << endl;
					
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 10:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: BIBLEOTECA ESTANDAR DE C++  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Que explicacion define de mejor manera el archivo de encabezado \"fstream\"?\n" << endl;
				mezclarOrdenRespuestas();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch (orden_respuestas[j]) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Contiene prototipos para funciones que realizan entredas desde archivos en disco" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Contiene la definicion de la clase string de la bibleoteca estandar" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Contiene prototipos de funcion de la bibleoteca de funciones matematicas" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de la opcion: ";
				cin >> input;
				
				if ( input == respuesta_correcta) {
					
					controlPuntuacion ( 5, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 5, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
				
				
		} // Fin del switch
			
	} // Fin del For
	
	menuCategoria();
	
} // Fin funcion cuestBibleotecaEstandar


void cuestConceptosBasicosAED () {
	
	int respuesta_correcta;
	int input;
	char tecla;
	
	for ( int i = 0 ; i < TAMANIOPREGUNTAS ; i++ ) {
				
		switch ( orden_preguntas[i] ) {
			
			case 1:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONCEPTOS BASICOS AED  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cuales es el orden correcto de las fases que se atraviesan generalmente para crear y ejecutar una aplicacion de C++?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Editor,Preprocesador, Compilador, Enlazador, Cargador, CPU" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Editor, Compilador, Preprocesador, Enlazador, Cargador, CPU" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Preprocesador, Editor, Compilador , Enlazador, CPU, Cargador" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 6, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 6, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 2:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONCEPTOS BASICOS AED " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes NO es un diagrama valido para representar graficamente un Algoritmo o Programa?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Diagrama de Thompson" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Diagrama de Flujo" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Diagrama de Nassi-Shneiderman" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 6, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 6, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
				
			case 3:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONCEPTOS BASICOS AED " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Segun lo propuesto por Bohm-Jacopini, cuales son las 3 intrucciones de control para escribir cualquier programa?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Secuencia, Decision, Iteracion" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Algoritmo, Decision, Iteracion" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Secuencia, Iteracion, Demostracion" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 6, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 6, false, false, false );
					cout << "\nINCORRECTO" << endl;
					
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore( std::numeric_limits<streamsize>::max(),'\n' );
				cin.get();
				break;
				
			case 4:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONCEPTOS BASICOS AED  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Quien describio en 1945 una arquitectura de computadora basada en los componentes: Unidad de Control, Unidad Algoritmica/Logica, Unidad de Memoria, Unidad de Entrada y Salida?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch (orden_respuestas[j]) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. von Neumann" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Nassi-Shneiderman" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Bohm-Jacopini" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) 
				{
					controlPuntuacion ( 6, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 6, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
			
			case 5:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONCEPTOS BASICOS AED  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de los siguientes es un lenguaje de Alto Nivel de programacion?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. C++" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Pseudocodigo" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Diagrama Chapin" << endl;
					 		break;
					 		
					 }
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 6, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 6, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 6:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONCEPTOS BASICOS AED  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de las siguientes NO es una sentencia de Iteracion?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					switch ( orden_respuestas[j] ) {
					 	
						case 1:
					 		cout << "[" << j+1 << "]. if else" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. while" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. for" << endl;
					 		break;
					 		
				  }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) 
				{
					controlPuntuacion ( 6, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 6, false, false, false );
					cout << "\nINCORRECTO" << endl;
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 7:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONCEPTOS BASICOS AED  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de las siguientes oraciones define de mejor manera un Algoritmo?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {

					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Especificacion rigurosa de la secuencia de pasos para alcanzar un resultado deseado en un tiempo finito" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Representacion de un objeto del mundo real medieante el cual se puede modelizar aspectos de un problema" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Informacion que deberia ser verdadera al cumplir el programa" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 6, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 6, false, false, false );
					cout << "\nINCORRECTO" << endl;
					
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
				
			case 8:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONCEPTOS BASICOS AED  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de las siguientes oraciones define de mejor manera una Precondicion?\n" << endl;
				mezclarOrdenRespuestas ();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Informacion conocida como verdadera antes de iniciar un programa" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Conjunto de instrucciones permitidas y definidas por sintacticas y su valor semantico" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. El acto de repetir un proceso con el objetivo de alcanzar una meta deseada" << endl;
					 		break;
					 		
					 } 
					 
				} 
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 6, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 6, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
			
			case 9:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONCEPTOS BASICOS AED  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de las siguientes oraciones define de mejor manera una Variable?\n" << endl;
				mezclarOrdenRespuestas();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch ( orden_respuestas[j] ) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Relacion nombre espacio de memoria que puede almacenar diferentes valores en funcion del tiempo" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Representacion de un objeto del mundo real mediante el cual se pueden modelizar aspectos de un problema." << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Linea de codigo en un lenguaje de programacion" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de respuesta: ";
				cin >> input;
				
				if ( input == respuesta_correcta ) {
					
					controlPuntuacion ( 6, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 6, false, false, false );
					cout << "\nINCORRECTO" << endl;
					
				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
		
			case 10:
				clearPantalla();
				cout << "\n";
				cout << "CATEGORIA: CONCEPTOS BASICOS AED  " << "( Pregunta: " << i +1  << "/" << TAMANIOPREGUNTAS << " )" << endl;
				cout << "============================================================\n" << endl;
				cout << "Cual de las siguientes oraciones define de mejor manera un Programa?\n" << endl;
				mezclarOrdenRespuestas();
				
				for ( int j = 0 ; j < TAMANIORESPUESTAS ; j++ ) {
					
					 switch (orden_respuestas[j]) {
					 	
					 	case 1:
					 		cout << "[" << j+1 << "]. Conjunto de intrucciones no activas almacenadas en un computador" << endl;
					 		respuesta_correcta = j+1;
					 		break;
					 	
					 	case 2:
					 		cout << "[" << j+1 << "]. Representacion esquematica de un algoritmo" << endl;
					 		break;
					 		
					 	case 3:
					 		cout << "[" << j+1 << "]. Intruccion de control que evalua el valor de un proposicion" << endl;
					 		break;
					 		
					 }
					 
				}
				
				cout << "\n\n";
				cout << "Seleccion el numero de la opcion: ";
				cin >> input;
				
				if ( input == respuesta_correcta) {
					
					controlPuntuacion ( 6, false, true, false );
					cout << "\nCORRECTO" << endl;
					 
				} else {
					
					controlPuntuacion ( 6, false, false, false );
					cout << "\nINCORRECTO" << endl;

				} 
	
				cout << "Presione intro para continuar con la siguientes pregunta...";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				cin.get();
				break;
				
				
		} // Fin del switch
			
	} // Fin del For
	
	menuCategoria();
	
} //FIN funcion cuestConceptosBasicosAED


void puntuacion( bool sale ) {
	

	clearPantalla();
	
	cout << "\n";
	cout << "PUNTUAJE, ESTADISTICAS & CALIFICACION" << endl;
	cout << "==================================================" << endl;
	cout << "*** Por Categoria *** " << endl;
	cout << "> Tipos de datos C++" << endl;
	cout << "Veces jugadas: " << cont_vjugadas_tiposdedatoscpp;
	cout << "  | Aciertos: " <<  cont_aciertos_tiposdedatoscpp;
	
	if ( TAMANIOPREGUNTAS - cont_aciertos_tiposdedatoscpp == TAMANIOPREGUNTAS ) {
		
		cout << "  | Desaciertos: 0" << endl;
		
	} else {
	
		cout << "  | Desaciertos: " << ( TAMANIOPREGUNTAS - cont_aciertos_tiposdedatoscpp ) << endl;
		
	}
	
	cout << "> Operadores C++" << endl;
	cout << "Veces jugadas: " << cont_vjugadas_operadorescpp;
	cout << "  | Aciertos: " <<  cont_aciertos_operadorescpp;
	
	if ( TAMANIOPREGUNTAS - cont_aciertos_operadorescpp == TAMANIOPREGUNTAS ) {
		
		cout << "  | Desaciertos: 0" << endl;
		
	} else {
	
		cout << "  | Desaciertos: " << ( TAMANIOPREGUNTAS - cont_aciertos_operadorescpp ) << endl;
		
	}
	
	cout << "> Precedencia de operadores C++" << endl;
	cout << "Veces jugadas: " << cont_vjugadas_procoperadorescpp;
	cout << "  | Aciertos: " <<  cont_aciertos_procoperadorescpp;
	
	if ( TAMANIOPREGUNTAS - cont_aciertos_procoperadorescpp == TAMANIOPREGUNTAS ) {
		
		cout << "  | Desaciertos: 0" << endl;
		
	} else {
	
		cout << "  | Desaciertos: " << ( TAMANIOPREGUNTAS - cont_aciertos_procoperadorescpp ) << endl;
		
	}
	
	cout << "> Conjunto de Caracteres ASCII" << endl;
	cout << "Veces jugadas: " << cont_vjugadas_ccaractascii;
	cout << "  | Aciertos: " <<  cont_aciertos_ccaractascii;
	
	if ( TAMANIOPREGUNTAS - cont_aciertos_ccaractascii == TAMANIOPREGUNTAS ) {
		
		cout << "  | Desaciertos: 0" << endl;
		
	} else {
	
		cout << "  | Desaciertos: " << ( TAMANIOPREGUNTAS - cont_aciertos_ccaractascii ) << endl;
		
	}

	cout << "> Bibleoteca estandar de C++" << endl;
	cout << "Veces jugadas: " << cont_vjugadas_bibestandarcpp;
	cout << "  | Aciertos: " <<  cont_aciertos_bibestandarcpp;
	
	if ( TAMANIOPREGUNTAS - cont_aciertos_bibestandarcpp == TAMANIOPREGUNTAS ) {
		
		cout << "  | Desaciertos: 0" << endl;
		
	} else {
	
		cout << "  | Desaciertos: " << ( TAMANIOPREGUNTAS - cont_aciertos_bibestandarcpp ) << endl;
		
	}

	cout << "> Conceptos Basicos AED" << endl;
	cout << "Veces jugadas: " << cont_vjugadas_concpbasaed;
	cout << "  | Aciertos: " <<  cont_aciertos_concpbasaed;
	
	if ( TAMANIOPREGUNTAS - cont_aciertos_concpbasaed == TAMANIOPREGUNTAS ) {
		
		cout << "  | Desaciertos: 0" << endl;
		
	} else {
	
		cout << "  | Desaciertos: " << ( TAMANIOPREGUNTAS - cont_aciertos_concpbasaed ) << endl;
		
	}

	cout << "\n";
	cout << "*** Totales *** " << endl;
	cout << "Total de aciertos: " << cont_aciertos_total << endl;
	cout << "Total de desaciertos: " << cont_naciertos_total << endl;
	cout << "\n";
	if ( ( cont_aciertos_total == 0 ) && ( cont_naciertos_total == 0 ) ) {
		
		cout << "Nivel: Ups, Usted todavia no juego!";
		
	} else {
		
		cout << "Nivel: ";

		if ( ( ( ( cont_aciertos_total / 6 ) / 2 ) >= 0 ) && ( ( ( cont_aciertos_total / 6 ) / 2 ) <= 1 )  ) {
			
			cout << "Bajo | Estrellas: ";
			
		}
		
		if ( ( ( ( cont_aciertos_total / 6 ) / 2 ) > 1 ) && ( ( ( cont_aciertos_total / 6 ) / 2 ) <= 2 )  ) {
			
			cout << "Regular | Estrellas: ";
			
		}
		
		if ( ( ( ( cont_aciertos_total / 6 ) / 2 ) > 2 ) && ( ( ( cont_aciertos_total / 6 ) / 2 ) <= 3 )  ) {
			
			cout << "Bueno | Estrellas: ";
			
		}
	
		if ( ( ( ( cont_aciertos_total / 6 ) / 2 ) > 3 ) && ( ( ( cont_aciertos_total / 6 ) / 2 ) < 5 )  ) {
			
			cout << "Muy Bueno | Estrellas: ";
			
		}
		
		if ( ( ( cont_aciertos_total / 6 ) / 2 ) == 5 ) {
			
			cout << "Excelente | Estrellas: ";
		
		}
		
		for ( int i = 0 ; i <= ( ( cont_aciertos_total / 6 ) / 2 ) ; i++ ) {
			
			if (i < 5) {
			
				cout << "*";
					
			}
			
		}
		
		cout << endl;
		
	}
	
	if ( sale == true ) {
		
		cout << "\n";
		cout << "Presione intro para cerrar el juego... ";
		cin.get();	
		
	} else {
		
		cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
		cout << "\n\n";
		cout << "Presione intro para volver al Menu Principal... ";
		cin.get();
		menuPrincipal();
		
		
	}
	
	
} //Fin funcion puntuacion


void comoJugar (){
	
	clearPantalla();
	
	cout << "\n";
	cout << "COMO JUGAR - JUEGO DE PREGUNTAS" << endl;
	cout << "==================================================" << endl;
	cout << "\n\n";
	cout << "1) En el Menu Principal ingrese a la seleccion de catgorias." << endl;
	cout << "2) Seleccione una de las categorias disponibles." << endl;
	cout << "3) Conteste las preguntas que ofrece la categoria." << endl;
	cout << "4) Cada respuesta correcta implicara la suma de un punto." << endl;
	
		for ( int i = 0 ; i < 15 ; i ++) {
		
		cout << "\n";
		
	}
	
	cout << "Presione intro para volver al Menu Principal... ";
	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
	cin.get();
	menuPrincipal();
	
} // Fin funcion comoJugar


void reglas (){
	
	clearPantalla();
	
	cout << "\n";
	cout << "REGLAS - JUEGO DE PREGUNTAS" << endl;
	cout << "==================================================\n\n" << endl;
	cout << "> Objetivo del Juego" << endl;
	cout << "\t * El objetivo del juego es contestar correctamente todas las preguntas de las diferentes categorias.\n" << endl;
	cout << "> Puntaje" << endl;
	cout << "\t * Cada respuesta acertada implicara la suma de un punto." << endl;
	cout << "\t * Si se decide volver a seleccioanr una categoria en la que se tiene puntaje se reseteara los puntos para esa categoria" << endl;
	cout << "\t * Si se respondieron correctamente todos las preguntas de una categoria, la misma estara completa y no se podra volver a jugar.\n" << endl;
	cout << "> Fin del juego" << endl;
	cout << "\t * El juego finalizara al responder correctamente las preguntas de todas las categorias." << endl;
	
		for ( int i = 0 ; i < 4 ; i ++) {
		
		cout << "\n";
		
	}
	
	cout << "Presione intro para volver al Menu Principal... ";
	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
	cin.get();
	menuPrincipal();
	
} // Fin funcion reglas


void acercaDe () {
	
	string version = "1.0.0";		// Version del Programa 
	string date_release= "04-05-2015";		// Fecha de la liberacion de la version
	string autor= "Nicolas Anderson";		// Autor del programa
	string autor_mail = "nicolas.anderson87@yahoo.com";		// Contacto del Autor.
	
	clearPantalla();
	
	cout << "\n";
	cout << "ACERCA DE - JUEGO DE PREGUNTAS" << endl;
	cout << "==================================================\n\n" << endl;
	cout << "> Version: " << version << endl;
	cout << "> Ultima Modificacion: " << date_release << endl;
	cout << "> Autor: " << autor << endl;
	cout << "> Informacion de Contacto: " << autor_mail << endl;
	
	for ( int i = 0 ; i < 15 ; i ++) {
		
		cout << "\n";
		
	}
	
	cout << "Presione intro para volver al Menu Principal... ";
	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
	cin.get();
	menuPrincipal();

} // Fin funcion acercaDe


void mezclarOrdenPreguntas (){
	
	int index=0;
	bool usado[TAMANIOPREGUNTAS];
	int cant_preguntas[TAMANIOPREGUNTAS];
	srand ( time ( NULL ) );
	
	for ( int i=0; i < TAMANIOPREGUNTAS ; i++){

		usado[i]=false;
	
	} // Fin del For
   
   for (int j =0 ; j < TAMANIOPREGUNTAS ; j++) {
		
		cant_preguntas[j] = j+1;			
		
	} //Fin For
	
	
	for (int i=0 ; i < TAMANIOPREGUNTAS; i++){
		
    	do{
    		
        	index = (rand() % TAMANIOPREGUNTAS);
        	
   	} while (usado[index]);
    	
		orden_preguntas[index] = cant_preguntas[i];
    	usado[index]=true;

	}  // Fin del For
	
} // Fin de la funcion mezclarOrdenPreguntas


void mezclarOrdenRespuestas(){
	
	int index=0;
	bool usado[TAMANIORESPUESTAS];
	int cant_respuestas[TAMANIORESPUESTAS];
	srand ( time ( NULL ) );
	
	for (int i=0; i < TAMANIORESPUESTAS; i++){

		usado[i]=false;

	} // Fin For
    	
	for (int j =0 ; j < TAMANIORESPUESTAS ; j++) {
		
		cant_respuestas[j] = j+1;			
		
	} //Fin For

	for ( int k=0 ; k < TAMANIORESPUESTAS ; k++ ){
		
    	do{
		 
		 index = (rand() % TAMANIORESPUESTAS);
        	
   	} while (usado[index]);
    	
		orden_respuestas[index] = cant_respuestas[k];
    	usado[index]=true;

	} //Fin For
	
} // Fin funcion mezclarOrdenPreguntas


void controlPuntuacion (int id_categoria, bool entro_categ, bool acerto, bool reset_puntos ){
	
	
	switch (id_categoria) {
				
				case 1:		//Categoría Tipos de datos C++
					if (entro_categ == true) {
						
						cont_vjugadas_tiposdedatoscpp++;
						
					}
					
					if ( ( acerto == true ) && ( reset_puntos == false ) ) {
						
						cont_aciertos_total++;
						cont_aciertos_tiposdedatoscpp++;
						
						
					}
						
					if ( ( acerto == false ) && ( reset_puntos == false ) && ( entro_categ == false ) ) {
						
						cont_naciertos_total++;
						
					}
					
					if ( reset_puntos == true ) {
						
						cont_aciertos_total = (cont_aciertos_total -  cont_aciertos_tiposdedatoscpp );
						cont_naciertos_total = (cont_naciertos_total - (TAMANIOPREGUNTAS - cont_aciertos_tiposdedatoscpp));
						cont_aciertos_tiposdedatoscpp = 0;
						
					}	
					

					break;
		
				case 2:		//Categoría Operadores C++
					if (entro_categ == true) {
						
						cont_vjugadas_operadorescpp++;
						
					}
					
					if ( ( acerto == true ) && ( reset_puntos == false ) ) {
						
						cont_aciertos_total++;
						cont_aciertos_operadorescpp++;
						
						
					}
						
					if ( ( acerto == false ) && ( reset_puntos == false ) && ( entro_categ == false ) ) {
						
						cont_naciertos_total++;
						
					}
					
					if ( reset_puntos == true ) {
						
						cont_aciertos_total = (cont_aciertos_total -  cont_aciertos_operadorescpp );
						cont_naciertos_total = (cont_naciertos_total - (TAMANIOPREGUNTAS - cont_aciertos_operadorescpp));
						cont_aciertos_operadorescpp = 0;
						
					}	
					
					break;
		
				case 3:		//Categoría Precedencia de operadores C++
					if (entro_categ == true) {
						
						cont_vjugadas_procoperadorescpp++;
						
					}
					
					if ( ( acerto == true ) && ( reset_puntos == false ) ) {
						
						cont_aciertos_total++;
						cont_aciertos_procoperadorescpp++;
						
						
					}
						
					if ( ( acerto == false ) && ( reset_puntos == false ) && ( entro_categ == false ) ) {
						
						cont_naciertos_total++;
						
					}
					
					if ( reset_puntos == true ) {
						
						cont_aciertos_total = (cont_aciertos_total -  cont_aciertos_procoperadorescpp );
						cont_naciertos_total = (cont_naciertos_total - (TAMANIOPREGUNTAS - cont_aciertos_procoperadorescpp));
						cont_aciertos_procoperadorescpp = 0;
						
					}
					
					break;
			
				case 4:		//Categoría Conjunto de Caracteres ASCII
					if (entro_categ == true) {
						
						cont_vjugadas_ccaractascii++;
						
					}
					
					if ( ( acerto == true ) && ( reset_puntos == false ) ) {
						
						cont_aciertos_total++;
						cont_aciertos_ccaractascii++;
						
						
					}
						
					if ( ( acerto == false ) && ( reset_puntos == false ) && ( entro_categ == false ) ) {
						
						cont_naciertos_total++;
						
					}
					
					if ( reset_puntos == true ) {
						
						cont_aciertos_total = (cont_aciertos_total -  cont_aciertos_ccaractascii );
						cont_naciertos_total = (cont_naciertos_total - (TAMANIOPREGUNTAS - cont_aciertos_ccaractascii));
						cont_aciertos_ccaractascii = 0;
						
					}
					
					break;
			
				case 5:		//Categoría Bibleoteca estandar de C++
					if (entro_categ == true) {
						
						cont_vjugadas_bibestandarcpp++;
						
					}
					
					if ( ( acerto == true ) && ( reset_puntos == false ) ) {
						
						cont_aciertos_total++;
						cont_aciertos_bibestandarcpp++;
						
						
					}
						
					if ( ( acerto == false ) && ( reset_puntos == false ) && ( entro_categ == false ) ) {
						
						cont_naciertos_total++;
						
					}
					
					if ( reset_puntos == true ) {
						
						cont_aciertos_total = (cont_aciertos_total -  cont_aciertos_bibestandarcpp );
						cont_naciertos_total = (cont_naciertos_total - (TAMANIOPREGUNTAS - cont_aciertos_bibestandarcpp));
						cont_aciertos_bibestandarcpp = 0;
						
					}
					
					break;
		
				case 6:		//Categorái Conceptos Basicos AED
					if (entro_categ == true) {
						
						cont_vjugadas_concpbasaed++;
						
					}
					
					if ( ( acerto == true ) && ( reset_puntos == false ) ) {
						
						cont_aciertos_total++;
						cont_aciertos_concpbasaed++;
						
						
					}
						
					if ( ( acerto == false ) && ( reset_puntos == false ) && ( entro_categ == false ) ) {
						
						cont_naciertos_total++;
						
					}
					
					if ( reset_puntos == true ) {
						
						cont_aciertos_total = (cont_aciertos_total -  cont_aciertos_concpbasaed );
						cont_naciertos_total = (cont_naciertos_total - (TAMANIOPREGUNTAS - cont_aciertos_concpbasaed));
						cont_aciertos_concpbasaed = 0;
						
					}
					
					break;
			
	}
	
} // Fin funcion controlpuntuacion


void excepcion ( int nro_excepcion ) {
	

	clearPantalla();

	
	switch ( nro_excepcion ) {
		
		case 1:		//Ingreso de opcion incorrecta
			cout << "Error: La opcion ingresada por teclada no es la esperada." << endl;
			cout << "Presione intro para volver al juego...";
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			cin.get();
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			break;
		
		case 2:		//Ingreso a una Categoria Completa
			cout << "Error: La categoria a la que intenta ingresar ya fue completada." << endl;
			cout << "Presione intro para volver al juego...";
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			cin.get();
			break;
			
		case 3:		//Reset de puntos para la categoria
			cout << "Advertencia: Se procedio a restartear los puntos para esta categoria." << endl;
			cout << "Tambien los puntos que tenia para esta categoria se restaron de su puntuacion total del juego.\n" << endl;
			cout << "Presione intro para continuar con el juego...";
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			cin.get();
			break;
		
		case 4:		//Mensaje de Gano el Juego
			cout << "\a\a\a";
			cout << "EN HORA BUENA, USTED COMPLETO EL JUEGO JUEGO!!!\n\n";
 			cout << "Presione intro para ver su puntuacion final y salir del juego...";
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			cin.get();
			break;
			
		case 5:		//Mensaje de Salida del Juego sin completarlo
			cout << "A DECIDO ABANDONAR EL JUEGO SIN COMPLETARLO\n\n";
 			cout << "Presione intro para ver su puntuacion final y salir del juego...";
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			cin.get();
			break;
	
	}
	
} // Fin funcion excepcion
 
 
 void finDelJuego( bool gano ) {
 
	clearPantalla();
 	
 	if (gano == true ) {
 		
 		excepcion ( 4 );
		sale = true;
		puntuacion ( sale );
		
	 } else {
	 	
		excepcion ( 5 );
		sale = true;
		puntuacion ( sale ) ;
	 	
	 }

 } // Fin funcion finDelJuego
