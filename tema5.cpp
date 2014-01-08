/*
 *  Preparador: José Abraham (abrahamjoc@gmail.com)
 *  Diciembre 2013
 *  Asignatura: Programación 2
 *  
 *  Tema V: Funciones y Procedimientos en Lenguaje C
 * 	
 *      En la programación iterativa se hace mucho más entendible los
 *  bloques de códigos cuando se programa utilizando la filosofía de divide
 *  y venceras.
 * 
 *  Las funciones y procedimientos hacen uso de esta forma de analizar y
 *  pensar, realizando anidamiento de bloques de código que son referenciados
 *  por un nombre que pueden o no retornar algo.
 * 
 *  Tópicos:
 *  - procedimientos y funciones
 */
 
#include <stdio.h>

// normalmente en los archivos de compilación de C, la función main() se
// encuentra al final del .c ó .cpp y todas las demás funciones se encuentran
// encima de esté, pero para ejemplo práctico y conocimiento general, hablaremos
// de lo que se conoce como prototipo de funciones.

	/**   Prototipos de Funciones ó Procedimientos: estos se utilizan para
	 *    referenciar que existen funciones y/ó procedimientos por debajo
	 *    de la función main() estos son accesibles solo a través de este
	 *    prototipo, si no de otra manera el compilador no entiende que
	 *    existe esa función declarada a la que deseo invocar.
	 * 
	 *    Estructura:
	 * 		
	 * 		tipo o void nombre ( argumentos ) ;
	 **/
	 
void estoEsUnProcedimiento(char cad[255]);

int  estoEsUnaFuncion(int num);

		
		// hemos declarado dos prototipos
		
		
int main()
{
	printf("Llamando a PROCEDIMIENTO:\n   ");
	
	estoEsUnProcedimiento((char*)"HOLA MUNDO");
	
	
	printf("\n\nLlamando a FUNCION:\n   ");
	
		// declarando n
	int n = 0;
	
	n = estoEsUnaFuncion(7);
	
	printf("\n\nBloque Main():\n   ");
	
	printf("Imprimiendo lo que retorno la funcion  n = %d", n);
	
	return 0;
}


	/**   Procedimientos: los procedimientos son básicamente una función
	 *    que no devuelve nada. inician por un  void  el cual significa
	 *    en ingles NADA, y va acompañado de su nombre y argumentos este
	 *    ejecuta y bloque de instrucciones y terminal al final del bloque
	 *    o cuando se le indique con un  return;  .
	 * 
	 *    Estructura:
	 * 		
	 * 		void nombre ( argumentos ) ;
	 **/

void estoEsUnProcedimiento(char cad[255])
{
	printf("Soy un procedimiento y imprimo la cadena que me envian, y es %s", cad);
	
		// notese que este  return  evita que se imprima la cadena de abajo,
		// porque mando a retornar en esta parte de las instrucciones, muy
		// útil cuando se cumple una condición y deseas finalizar este 
		// bloque de instrucción.
	return;
	
		// esto nunca se llega a ver
	printf("FINAL DE PROCEDIMIENTO\n");
}


	/**   Funciones: las funciones son básicamente un procedimiento que
	 *    nos devuelve algo, queda definido como un tipo después del
	 *    procesamiento que establece el el bloque de código.
	 * 
	 * 	  Deben finalizar colocando un  return (mismo tipo función) en el
	 *    momento en que se desea finalizar la función.
	 * 
	 *    Estructura:
	 * 		
	 * 		tipo nombre ( argumentos ) ;
	 **/

int estoEsUnaFuncion(int num)
{
	printf("Soy una función que recibe un numero y recibi  %d", num);
	
		// retornará numero multiplicado por 3
	return num*3;
}
