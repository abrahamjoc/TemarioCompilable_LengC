/*
 *  Preparador: José Abraham (abrahamjoc@gmail.com)
 *  Diciembre 2013
 *  Asignatura: Programación 2
 *  
 *  Tema VI: Arreglos (Memoria Estática) en Lenguaje C
 * 	
 *      Es muy popular escuchar en el mundo de la programación aquello
 *  que conocemos como Vectores y Matrices, términos que no son del todo
 *  erroneos, pero tampoco técnicamente existen dentro de las estructuras
 *  que gestiona el sistema operativo (SO) dentro de la Memoria RAM.
 * 
 *  Los mismos nacieron con la intención de poder ayudar a los aprendices
 *  a tener noción en su abstración de que son arreglos de una y dos 
 *  dimensiones respectivamente.
 * 
 *  Cabe destacar que los bloques de un arreglos en Memoria Ram son
 *  totalmente continuos, y estos dependeran del tamaño y cuantas 
 *  dimensiones tenga.
 * 
 *  Tópicos:
 *  - arreglos
 */

#include <stdio.h>

int main()
{
	/**   Arreglos: los arreglos son estructuras secuenciales en memoria
	 *    referenciadas de un mismo tipo en una cantidad finita que estan
	 *    definidas proporcionalmente a la cantidad de dimensiones y unidades
	 *    de las mismas que se definan.
	 * 
	 *    Estas se definen a través de los símbolos [ ] y dentro se coloca
	 *    la cantidad de unidades que tendrá.
	 * 
	 *    Estructura:
	 *                                    // esto es:
	 * 	  tipo nombre [tam]           // un vector
	 * 	  tipo nombre [tam][tam]      // una matriz
	 * 	  tipo nombre [tam][tam][tam] // un arreglo de 3 dimensiones
	 * 	  
	 * 	  y así sucesivamente tantas dimensiones se necesiten
	 **/
	 
	 int   arreglo_1dim[20];         
		// vector de enteros de 20 posiciones
	 
	 char  arreglo_2dim[20][20];     
		// matriz de carácter de 20x20 posiciones
		
	 float arreglo_3dim[20][20][20];
		// arreglo de flotantes 3 dimensiones de 20x20x20 posiciones
	 
	 
		// y así sucesivamente [] tantas dimensiones se necesiten
		
	 
	/**   Se sabe que que los arreglos poseen elementos finitos lo que 
	  *   quiere decir que para recorrerlos se deben anidar tantos for 
	  *   como dimensiones tengan y realizar un acceso que puede ser de 
	  *   escritura ó lectura.
	  */
	 
		// inicializaremos los arreglos ya declarados, a esto lo conocemos 
		// como acceso de escritura para asignar estado inicial
	
	 for ( int i=0; i<20; i++ )
	 {	 
		 arreglo_1dim[i] = 0;
		 
		 for ( int j=0; j<20; j++ ) 
		 {
			 arreglo_2dim[i][j] = ' ';
			 
			 for (int k = 0; k<20 ; k++)
			 {
				 arreglo_3dim[i][j][k] = 0.0;
			 }			 
		 }
	 }
	 
	 
		// asignación a priori, con esto asignamos a una casilla de un arreglo
		// un valor deseado, esto se hace de la siguiente manera:
		// 
		// 		nombre[posición] = dato.
		
	 arreglo_1dim[9] = 5;   arreglo_1dim[4] = 8;   arreglo_1dim[10] = 3;
	 
	 arreglo_2dim[4][9] = 'A'; arreglo_2dim[3][17] = 'Z'; arreglo_2dim[5][15] = 'G';
	 
	 
	 
		// imprimiendo los arreglos ya declarados, a esto lo conocemos
		// como acceso de lectura para mostrar en pantalla, 
		// NOTA: se hace más entendible si se hace por separado
	 
	 printf("\n"); printf("Imprimiendo arreglo de 1 dimensión (vector):\n");
	 
	 printf("Pos: ");
	 for ( int i=0; i<20; i++ )
	 {
		 printf(" %d,", i);
	 }
	 printf("\nValor");
	 
	 for ( int i=0; i<20; i++ )
	 {
		 if ( i < 10 )
		 
			printf(" %d,", arreglo_1dim[i]);
		
		 else
		 
			printf("  %d,", arreglo_1dim[i]);
	 }
			// notese los lugares donde se asignó números distintos de 0
	 
	 
	 printf("\n\n"); printf("Imprimiendo arreglo de 2 dimensiones (matriz):\n");
	 
	 printf("Pos: ");
	 for ( int i=0; i<20; i++ )
	 {
		 printf(" %d,", i);
	 }
	 printf("\nVal ");
	 
	 for ( int i=0; i<20; i++ )
	 {
		 printf("%d", i);
		 
		 for ( int j=0; j<20; j++)
		 {
			 if ( j < 10 )
			 
				printf(" %c,", arreglo_2dim[i][j]);
				
			 else
			 
				printf("  %c,", arreglo_2dim[i][j]);
		 }
		 
		 printf("\n    ");
		 
		 if ( i > 8 )
			
			printf("\b");
	 }
			// notese los lugares donde se asignó letras
	 
	 return 0;
}
