/*
 *  Preparador: José Abraham (abrahamjoc@gmail.com)
 *  Diciembre 2013
 *  Asignatura: Programación 2
 *  
 *  Tema VIII: Apuntadores en Lenguaje C
 * 	
 *      Cuando se trata de programar deseando tener el control de flujo 
 *  de los recursos del hardware de nuestro equipo, en Lenguaje C existe
 *  algo llamado apuntadores, los mismos son utilizados para la comunicación
 *  de mi programa con recursos físicos, el SO autogestiona un enlace
 *  a estos recursos que bien pueden ser:
 * 		
 * 		- Memoria RAM (Variables, Estructuras y Funciones de mi programa)
 * 		- Disco Duro  (Archivos)
 * 		- Puertos	  (Paralelo, Serial, USB, etc.)
 * 
 * 		- Sistema Operativo
 * 				 ( son una variante de disco, pero a través de las )
 * 				 ( estructuras programadas internamente en el SO.  )
 * 
 * 
 *  Existen cómo una transición del manejo de recursos en una sintaxis mucho
 *  más sencilla que la de Lenguaje Ensamblador (Lenguaje Máquina), que
 *  era su lenguaje padre antecesor.
 * 
 *  Su función básicamente consiste en que el programa se comunica con el SO,
 *  y esté autogestiona un acceso al archivo descriptor del recurso exigido,
 *  conteniendo la información que va permitir su acceso.
 * 
 *  Su estructura se caracteriza por tener una referencia de dirección y así
 *  mismo contener la dirección de otro lugar, que bien podriamos verlo
 *  como referenciación y desreferenciación, entendiendo de que lo último
 *  significa el contenido de lo que se apunta.
 *  
 *  Tópicos:
 *  - apuntadores a variables
 */

#include <stdio.h>

int main()
{
	/**   Apuntadores: los apuntadores son una parte fundamental de Leng.C,
	 *    los mismos le dan una versatilidad y flexibilidad impresionantes.
	 *    
	 *    De manera sencilla un apuntador es una variable que contiene la 
	 *    dirección en memoria de otra variable.
	 * 
	 * 	  El operador unario  &  devuelve la dirección de memoria de una 
	 *    variable.
	 * 
	 * 	  El operador de indirección o desreferencia  *  devuelve el 
	 *    "contenido de un objeto apuntado por un apuntador".
	 * 
	 * 
	 *    Estructura:
	 *    
	 * 	  tipo *nombre;
	 * 	  
	 *                           .---------.---------.
	 *                           |  dirF*  |  dirA&  |
	 *                           '---------'---------'
	 *   
	 *    dirección Física          :  *  : dirección que posee en M.RAM.
	 *    dirección Apuntada	:  &  : dirección apuntada  en M.RAM.
	 * 
	 * 
	 * 		Nota: puede pasar que un apuntador apunte a otro apuntador,
	 *  	y esto se conoce como referencia de referencia, esto se usa
	 * 		usualmente cuando se necesita acceder a otra capa de llamada
	 *      de funciones que necesiten modificar directamente un dato que 
	 *      es variable y este quede modificado al retornar la función.
	 * 
	 * 	    Ejemplo:
	 * 
	 * 		tipo **nombre;
	 * 			// doble apuntador, dirección de una dirección
	 * 
	 * 		tipo ***nombre;
	 * 			// triple apuntador, dirección de una dir. de una dir.
	 * 
	 * 		y así sucesivamente cuantos apuntadores para referenciar 
	 *      direcciones	se necesiten.
	**/
	printf("Usando apuntadores a VARIABLE:\n");
		
		// para este ejemplo trabajaremos con variables enteras, y hasta
		// con 4 referencias de direcciones, cambiando la variable a.
		
	int a;      // entero simple
	int *b;     // dirección a entero
	int **c;    // dirección a direccción de entero
	int ***d;   // doble dirección a dirección de entero
	int ****e;  // tripe dirección a dirección de entero
	
	
		// asignaremos dato a la variable A usando las demás referencias
	
	
	a = 1;                                          // imprimiendo a
	printf("variable a vale : %d\n", a);


// referencia: *b = &a
	b = &a;
	*b = 2;                                         // imprimiendo *b
	printf("variable a vale : %d\n", a);


// referencia: **c = &*b
	c = &b;
	**c = 3;                                        // imprimiendo **c
	printf("variable a vale : %d\n", a);


// referencia: ***d = &**c
	d = &c;
	***d = 4;                                       // imprimiendo ***d
	printf("variable a vale : %d\n", a);


// referencia: ****e = &***d
	e = &d;
	****e = 5;                                      // imprimiendo ****e
	printf("variable a vale : %d\n", a);


		// notese que a medida que se sube de capa de dirección, se
		// incrementa un * en cada apuntador para hacer referencia, y
		// se hace necesario completar con un & para apuntar a la 
		// dirección de una dirección, que a su vez puede seguir
		// apuntando a otras direcciones.


	return 0;
}
