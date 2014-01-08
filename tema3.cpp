/*
 *  Preparador: José Abraham (abrahamjoc@gmail.com)
 *  Noviembre 2013
 *  Asignatura: Programación 2
 *  
 *  Tema III: Ciclos Repetitivos en Lenguaje C
 * 
 *      En la programación es muy común hacer sentencias que casi siempre
 *   siguen un patrón que se repite, imaginense tener que hacer un patrón
 *   iteración a iteración, pero siempre modificando nosotros línea a línea
 *   las variables, sería una tarea muy tediosa y totalmente fastidiosa.
 *  
 *   Para resolver esto en el mundo de la programación aparece lo que se
 *   conoce como ciclos repetitivos , estos nos permiten realizar un
 *   conjunto de líneas de una misma expresión en pocas líneas con una 
 *   sintaxis bastante sencilla.
 * 
 *   Existen 3 tipos de ciclos repetitivos en Lenguaje C:
 *       > for 		  : repite con iteraciones fijas
 *       > while 	  : repite mientras condición sea verdad
 *       > do..while  : repite mientras condición sea falsa
 * 
 *  Tópicos: 
 *  - ciclo for
 *  - ciclo while
 *  - ciclo do..while
 *  - continue
 *  - break
 */
 
 #include <stdio.h>
 
 int main()
 {
		// usaremos para todos los ejemplos, imprimir numeros de 0..9
	 int i=0;
	 
	/**  Ciclo FOR: este ciclo permite realizar iteraciones fijas, es
	 *    decir es aconsejable que cuando se conozcan las iteraciones con
	 *    las que deseo repetir determinada acción usar este ciclo.
	 * 
	 * 	  En Leng.C la sintaxis de for es un poco peculiar, este tiene
	 * 	  varias secciones que hacen de este ciclo algo extraordinarimente
	 * 	  manejable.
	 * 
	 *    Estructura:
	 *    
	 *    for ( 'sección a'; 'sección b'; 'sección c' ) {
         *
         *                     sentencias;
         *    }
         * 
         *   sección a: se usa para inicializar y/ó ejecutar comandos antes 
         * 		de iniciar el ciclo.
         * 
         *   sección b: se usa para establecer la condición de no parada del
         * 		ciclo, es decir mientras sea verdad seguir repitiendo.
         * 
         *   sección c: se usa para contar y/ó ejecutar comandos después de
         * 		una iteración del ciclo.
         **/
	 printf("Ciclo For:\n");
	 
	 //  i inicializa en 0;  repetir mientras i sea menor que 10;  incrementa i
	 for ( i=0; i<10; i++ )
	 {
		 printf(" %d,", i);
	 }
	 
	 
	 printf("\n\n");
	/**   Ciclo WHILE: este ciclo permite realizar iteraciones mientras
	 *	  una condición sea verdadera, por ende saldrá cuando la condición
	 *    se vuelva falsa.
	 * 
	 *    Estructura:
	 *    
	 *    while ( condición ) {
         * 		
         *         sentencias;
         *    }
	 **/
	 printf("Ciclo While:\n"); 
	 	
		// inicializa en 0
	 i = 0;
	 
		// repetir mientras i sea menor que 10
	 while ( i<10 )
	 {
			// imprime e incrementa i
		printf(" %d,", i++);
	 }
	 
	 
	 printf("\n\n");
	/**   Ciclo DO..WHILE: este ciclo permite realizar iteraciones mientras
	 *	  una condición sea verdadera, por ende saldrá cuando la condición
	 *    se vuelva falsa.
	 * 
	 *    Otra particularidad de este ciclo es que se asegura de entrar
	 *    al menos una vez a iterar, lo que lo hace ideal para menús en 
	 *    nuestros programas.
	 * 
	 *    Estructura:
	 *    
	 *    do {
	 * 
         *        sentencias;
         * 
         *    } while ( condición );
	 **/
	 printf("Ciclo Do..While:\n"); i = 0;	// inicializa en 0
	 
	 // hacer
	 do { 
			// imprime e incrementa i
		 printf(" %d,", i++);
		
		// mientras i menor que 10 
	 } while ( i<10 );
		
	
	 printf("\n\n");
	/**  Continue: es una sentencia que se utiliza para dar continuidad
	 *	  obviando todas las demás instrucciones siguientes dentro de un
	 *    ciclo repetitivo.
	 * 
	 *    Es decir, llamando a la siguiente iteración, obviando las
	 *    siguientes líneas de ejecución dentro del ciclo.
	 **/
	 printf("Uso de continue:\n");
	 
		// para este ejemplo imprimiremos solo los numeros que sean pares
	for ( i=0; i<10; i++ )
	{
		if ( i%2 )
		{
			continue;
		}
		printf(" %d,", i);
	}
	
	
	printf("\n\n");
	/**  Break: es una sentencia que se utiliza para romper la
	 *	  continuidad de un ciclo, sacandolo definitivamente y siguiendo
	 *    con la ejecución normal del programa.
	 * 
	 *    Es decir, coloca la condición de continuidad en falso, y el
	 *    ciclo que se este usando sale de ejecución.
	 **/
	 printf("Uso de break:\n");
	 
		// para este ejemplo imprimiremos solo los numeros hasta el 5,
		// aun sabiendo de que la condición es imprimirlo hasta 10.
	for ( i=0; i<10; i++ )
	{
		if ( i==6 )
		{
			break;
		}
		printf(" %d,", i);
	}
	
	return 0;
 }
