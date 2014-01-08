/*
 *  Preparador: José Abraham (abrahamjoc@gmail.com)
 *  Diciembre 2013
 *  Asignatura: Programación 2
 *  
 *  Tema VII: Manejo de Cadenas <String.h> en Lenguaje C
 * 	
 *      La programación es una tarea que se realiza para automatizar
 *  procesos mediante el diseño e implementación de un algoritmo, durante
 *  ese proceso utilizamos datos que estadísticamentes en algún momento
 *  involucran el uso de palabras, estás se reprensentan como estructuras 
 *  conocidas como cadena de carácteres.
 * 
 *  En lenguaje C existen librerias que permiten el manejo de cadenas de
 *  una manera bastante sencilla, funciones que son estandar y que son
 *  ampliamente utilizadas.
 * 
 *  Tópicos:
 *  - cadenas ( arreglo de carácteres )
 *  - manejo de funciones de librería <string.h>
 */

#include <stdio.h>
#include <string.h>

int main()
{
	/**   Cadenas: una cadena no es más que un arreglo de caracteres que
	 *    permite simbolizar abstractamente el uso de palabras.
	 * 
	 *    Manejo de Cadenas: existe una librería estandar muy ampliamente
	 *    usada en lenguaje C, llamada  < string.h > que contiene muchas
	 *    funciones probadas y testeadas, que resultan muy útiles al
	 *    plantearnos realizar ciertas cosas cuando programamos.
	 * 
	 * 
	 *    Estructura:
	 *    
	 * 		char nombre[tam];	// es decir es un vector de caracteres
	 **/
	 
	 char cadena1[255];
	 char cadena2[255];
	 char cadena3[255];
			// aqui tenemos declaradas tres cadenas de tamaño de 255
	
	
	/**  strcpy: función que permite copiar una cadena a otra cadena,
	 *   muy útil cuando se trata de inicializar cadenas.
	 * 
	 * 	 Significa:
	 * 		 STRing CoPY (copiar cadena)
	 * 
	 * 	 Estructura:
	 * 
	 * 		strcpy ( cadena destino, cadena origen );
	 **/
	
	strcpy(cadena1, "Hola");
	strcpy(cadena2, "Mundo");
	strcpy(cadena3, "Programacion");
	
	printf("%s", "Usando Función STRCPY:  [Resultados]\n");
	printf("           cadena 1  :  %s\n", cadena1);
	printf("           cadena 2  :  %s\n", cadena2);
	printf("           cadena 3  :  %s\n", cadena3);
	
	
	printf("\n");
	/**  strcat: función que permite concatenar una cadena a otra cadena,
	 *   muy útil cuando se trata de unir cadenas.
	 * 
	 * 	 Significa:
	 * 		 STRing conCATenate (concatenar cadena)
	 * 
	 * 	 Estructura:
	 * 
	 * 		strcat ( cadena destino, cadena origen );
	 **/
	
	strcat(cadena1, cadena2);
	strcat(cadena1, " me gusta mucho la ");
	strcat(cadena1, cadena3);
	
	printf("%s", "Usando Función STRCAT:  [Resultados]\n");
	printf("           cadena 1  :  %s\n", cadena1);
	printf("           cadena 2  :  %s\n", cadena2);
	printf("           cadena 3  :  %s\n", cadena3);
	
	
	printf("\n");
	/**  strcmp: función que permite comparar dos cadenas, devuelve estados
	 *   dependiendo de como esten las cadenas.
	 * 
	 *   Por orden alfabético
	 * 		-1: si cadena1 < cadena2
	 * 		 0: si cadena1 = cadena2
	 * 		 1: si cadena1 > cadena2
	 * 
	 * 	 Significa:
	 * 		 STRing CoMPare (comparar cadenas)
	 * 
	 * 	 Estructura:
	 * 
	 * 		strcmp ( cadena 1, cadena 2 );
	 **/
		
	printf("%s", "Usando Función STRCMP:  [Resultados]\n");
	
	printf("Int. Cadena 1 : "); scanf("%s", cadena1);
	printf("Int. Cadena 2 : "); scanf("%s", cadena2);
	printf("\n");
	printf("           cadena 1  :  %s\n", cadena1);
	printf("           cadena 2  :  %s\n", cadena2);
	
	if ( strcmp(cadena1,cadena2) == 0 )
	
		printf("\n Las cadenas son IGUALES  (C1 = C2)\n");
	
	else if ( strcmp(cadena1,cadena2) == 1 )
	
		printf("\n Cadena 1 es MAYOR QUE Cadena 2  (C1 > C2)\n");
		
	else
	
		printf("\n Cadena 1 es MENOR QUE Cadena 2  (C1 < C2)\n");
		
		
        // nota: prueba  cad1 = "n"  y  cad2 = "mundo", observa el comportamiento
		
	return 0;
}
