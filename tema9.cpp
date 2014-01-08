/*
 *  Preparador: José Abraham (abrahamjoc@gmail.com)
 *  Diciembre 2013
 *  Asignatura: Programación 2
 *  
 *  Tema IX: Memoria Dinámica en Lenguaje C
 * 	
 *      Hasta ahora nos hemos dedicado a programar declarando variables
 *  de tamaño fijo haciendo de nuestro programa una ejecución con consumo
 *  de recursos finitos, imaginemos por un momento que para el manejo de
 *  los datos que queremos implementar el tamaño será definido en tiempo
 *  de ejecución por el usuario y no por nosotros. Si declaramos una
 *  variable de tamaño enorme por encima de lo que se esperaría siempre,
 *  estariamos haciendo un uso totalmente ineficiente de los recursos.
 * 		
 * 	Para resolver este dilema existe algo en Lenguaje C conocido como
 *  Memoria Dinámica, está consiste en crear y liberar variables en
 *  Memoria RAM durante la corrida de nuestro programa.
 * 
 *  Tópicos:
 *  - struct
 *  - typedef
 *  - malloc y free
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	/**   Struct: Significa Estructura en ingles que viene de la traducción
	 *    de Structure. Está palabra reservada sirve para poder crear
	 *    registros con variables de distintos tipos referenciandose a
	 *    través de una misma referencia.
	 *    
	 * 
	 *    Estructura:
	 *    
	 * 	  struct nombre {
	 * 	  	
	 * 			tipo variable1;
	 * 			tipo varibale2;
	 * 			 ...  ...  ...
	 * 			tipo variableN;
	 *        };
	 * 
	 * 
	 *   Su definición pasa a ser un tipo de dato declarable en cualquier
	 *   parte válida del código de ejecución, y este a su vez contendra
	 *   todos los datos que se declararon previamente en esa estructura.
	 * 
	 *   Para poder accesar a los datos de la estructura se utilizarán los
	 *   carácteres  .  y  ->  , que representan un acceso a dato.
	 *   
	 * 	 Se utiliza punto  .  cuando la variable es de tipo estática
	 * 
	 * 	 	estructura.elemento  ;
	 * 
	 *   Cuando se trate de memoria dinámica a través de apuntadores se
	 *   utiliza  ->  para diferenciarlo
	 * 
	 * 		estructura->elemento ;
	**/
	
	// definición de un registro ( que no es más que muchos datos
	// conteplados en una estructura de datos
struct registro {
	
	int  id;
	char nombre  [255];
	char apellido[255];
	char cedula  [ 12];
	
};


	/**   Typedef: Significa Definición de Tipo en ingles que viene de la
	 *    traducción de Type Definition. Está palabra reservada sirve para
	 *    poder nombrar tipos de datos de una manera tificada por nosotros,
	 *    estableciendo su referencia a través del nombre que le pongamos.
	 *    
	 * 
	 *    Estructura:
	 *    
	 * 	  typedef struct nombre TIPODEFINIDO;
	**/

	// definimos nuestro registro con un nombre más formal
typedef struct registro PERSONA;


int main()
{
	struct registro p1;
	
	PERSONA p2;
	
	
		// las dos formas arribas representan conjuntos de variables
		// definidas por la estructura registro, pero expresados
		// sintácticamente de manera diferente
		
		// NOTA: observese que su acceso es a través del carácter '.'
		
	
		// asignando datos de persona 1
	p1.id = 1;
	strcpy(p1.nombre,"Maria");
	strcpy(p1.apellido,"Perez");
	strcpy(p1.cedula,"18765676");
	
		// asignando datos de persona 2
	p2.id = 2;
	strcpy(p2.nombre,"Jose");
	strcpy(p2.apellido,"Rodriguez");
	strcpy(p2.cedula,"20567634");
	
	
	/**   Malloc: Significa Alocación de Memoria en ingles que viene de la
	 *    traducción de Memory ALLOCcation. Está palabra reservada sirve
	 *    para poder reservar en memoria un tamaño especifico de memoria,
	 *    y luego devolver un apuntador que contiene la dirección de en
	 *    donde fue reservado este espacio.
	 *    
	 * 
	 *    Estructura:
	 *    
	 * 	  variable = (TipoVariable*) malloc ( sizeof(TipoVariable) );
	 * 
	 * 
	 *      Nota: sizeof, devuelve el tamaño exacto que posee una estructura
	 *            definida de datos, siendo primitiva o compuesta.
	**/
	
		// imaginese que quiere crear de manera dinámica un registro de
		// tipo persona, para ello declararemos un apuntador de dirección
		// del tipo de dato que queremos manejar y allí trabajaremos con
		// las funciones que nos permiten reservar memoria.
				
				
		// declaramos apuntador
	PERSONA *p3;
	
	
		// pedimos reservar en memoria el tamaño de persona, que serían
		// todas las variables primitivas reservada a través de la
		// estructura PERSONA y esté devuelve la dirección de tipo PERSONA 
		// a su apuntador respectivo
	p3 = (PERSONA*) malloc ( sizeof(PERSONA) );
	
	
		// asignamos datos en las variables
	p3->id = 3;
	strcpy(p3->nombre,"Manuel");
	strcpy(p3->apellido,"Garcia");
	strcpy(p3->cedula,"17394754");
	
		// NOTA: observese que el acceso se hace a través de los
		// carácteres '->'
		
	
	printf("PERSONA 1  ( Declarada con struct ):\n");
	printf("p1 -> id      : %d\n", p1.id);
	printf("p1 -> nombre  : %s\n", p1.nombre);
	printf("p1 -> apellido: %s\n", p1.apellido);
	printf("p1 -> cedula  : %s\n", p1.cedula);
	printf("\n");
	printf("PERSONA 2  ( Declarada con typedef ):\n");
	printf("p2 -> id      : %d\n", p2.id);
	printf("p2 -> nombre  : %s\n", p2.nombre);
	printf("p2 -> apellido: %s\n", p2.apellido);
	printf("p2 -> cedula  : %s\n", p2.cedula);
	printf("\n");
	printf("PERSONA 3  ( Declarada con malloc ):\n");
	printf("p3 -> id      : %d\n", p3->id);
	printf("p3 -> nombre  : %s\n", p3->nombre);
	printf("p3 -> apellido: %s\n", p3->apellido);
	printf("p3 -> cedula  : %s\n", p3->cedula);
	
	
	/**   Free: Significa Liberar en ingles que viene de la traducción
	 *    de FREE. Está palabra reservada sirve para poder liberar en
	 *    memoria un tamaño especifico de memoria, el cual su contenedor
	 *    es un apuntador que contiene la dirección de en donde fue
	 *    reservado ese espacio.
	 *    
	 * 
	 *    Estructura:
	 *    
	 * 	  free ( TipoVariable* ) ;
	**/
	
		// imaginemos que por alguna razón ya no deseamos que ese espacio
		// de memoria que declaramos previamente se siga utilizando, y el
		// programa debe seguir corriendo.
		
		// esa situación representa la magia de poder utilizar la capacidad
		// de controlar los recursos por medio de memoria dinámica,
		// creando y eliminando según sea necesario.
		
	free(p3);
	
		// NOTA: observese que la única variable que puede ser liberada
		// es el apuntador PERSONA p3, las demás fueron declaradas de
		// manera estática y por tanto se liberan solo al final de la
		// ejecución de nuestro programa.
		
		
		// Trabajar con memoria dinámica representa el inicio del manejo
		// de estructuras teóricas más complejas como son Listas y Arboles.
		
	return 0;
}
