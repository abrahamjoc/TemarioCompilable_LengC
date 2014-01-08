/*
 *  Preparador: José Abraham (abrahamjoc@gmail.com)
 *  Diciembre 2013
 *  Asignatura: Programación 2
 *  
 *  Tema XI: Recursividad en Lenguaje C
 * 	
 *      La recursividad es un fenómeno que se conoce en Ciencias de la
 *  Computación como un proceso que es capaz de ejecutar una serie de
 *  instrucciones de manera recurrente.
 * 
 *  En el caso de Lenguaje C, se trataría de una sección de código que
 *  bien podría ser un procedimiento o una función que se llame así misma
 *  una y otra vez, hasta que el desarrollador lo determine.
 * 		
 *  Existen dos formas de controlar la recursividad una es a través de
 *  una condición de parada y la otra es la contraparte que sería una
 *  condición de NO parada.
 *  
 *  Tópicos:
 *  - recursividad
 */

#include <stdio.h>


/// Prototipos de Función
void recursividad();
int invertirEnParametro(int num, int res);
int invertirSinParametro(int num);
int factorial(int num);


int main()
{
	
		// demostración sencilla de recursividad
	recursividad();
	
	
	printf("\n\n");
		// dos formas distintas para invertir números recursivamente
		// una con pase de parámetros para acumulación de resultado
		// y otra sin ella.
		
	printf("Invertir [ Forma 1 ]  1234 : %d\n",invertirEnParametro(1234,0));
	
	printf("Invertir [ Forma 2 ]  5678 : %d\n",invertirSinParametro(5678));
	
		// NOTA: observese dentro la funciones que una utiliza condición
		//       de parada y la otra usa una condición de NO parada.
		
	
	printf("\n");
		// ejercicio de factorial recursivo
	printf("Factorial(7) 1*2*3*4*5*6*7 : %d",factorial(7));
}


/// Procedimiento demostrativo recursivo
void recursividad()
{
		// declaracion de una variable estática entera
		// esto para asegurarse de que sea la misma variable en todo
		// el procedimiento
	static int i = 0;

		// condición de parada, cuando se hayan hecho 10 iteraciones
	if ( i == 9 )
			// culminar recursividad
		return;
		
		// rellenar espacios para ver en forma de escalera
	for ( int j=0; j<i; j++)
			// imprimir espacios
		printf("  ");
	
		// mostrar que es la iteracion número tal de la recursividad
	printf("Recursividad: %d\n", i++);
	
		// lamar a misma función
	recursividad();
}


/// Invertir un número recursivamente con entero acumulado en función
int invertirEnParametro(int num, int res)
{
		// si numero == 0
	if ( !num )
			// empezar a devolver resultado
		return res;
		
		// retorna lo que retorne la recursividad
		// pasandole el número más corto y acumulando el resultado en res
	return invertirEnParametro(num/10,(res*10)+(num%10));
}


/// Invertir un numero recursivamente con entero acumulado en variable
/// estática para dar más elegancia al código
int invertirSinParametro(int num)
{
		// variable estática donde se almacenará resultado
	static int res = 0;
	
		// si número existe
	if ( num )
	{
			// acumuló mi operación de inversión númerica
		res = (res*10) + (num%10);
	
			// continuo la recursividad pasando el número más corto
		invertirSinParametro(num/10);
	}
	
		// comienzo a devolver la recursividad con el resultado
	return res;
}


/// Factorial de un número recursivamente
int factorial(int num)
{
		// Si hemos llegado a 1
	if ( num == 1 )
			// retornar recursividad, 
			// devolviendo número neutro en la multiplicación
		return 1;
		
		// multiplicamos número actual y continuamos con la recusividad
		// pasando como parámetro el siguiente número menor
	return num * factorial(num-1);
}
