/*
 *  Preparador: José Abraham (abrahamjoc@gmail.com)
 *  Noviembre 2013
 *  Asignatura: Programación 2
 *  
 *  Tema IV: Estructuras Condicionales en Lenguaje C
 * 	
 * 		El cerebro de una persona por su desarrollo biológico material,
 *  permite realizar miles de millones de operaciones matemáticas y lógicas,
 *  que dan como resultado la toma de decisiones según patrones identificados.
 * 
 *  En la programación para hacer uso de la toma de decisiones se utiliza
 *  lo que se conoce como estructuras condicionales, que no son más que
 *  simples estructuras que permiten según una condición preguntada ejecutar
 *  una acción determinada.
 * 
 *  Tópicos:
 * 
 *  - if..else : si algo hacer en caso contrario
 * 
 *  - switch   : según caso hacer
 * 
 *  - operador ternario : 
 * 			(caso especial explicado más adelante)
 */
 
 #include <stdio.h>
 
 int main()
 {	 
	/**   If..Else: es una sentencia que permite realizar acciones según una
	 *    condición preguntada, permitiendo que en caso de ser cierto se
	 *    tome una acción para cuando sea verdedara (positiva) ó falsa
	 *    (negativa).
	 * 
	 *    Estructura:
	 *    
	 *    if ( condición ) {
     * 		
     * 			sentencias si condición
     * 			verdadera;
     * 	  }
     * 	  else {
	 *		
	 * 			sentencias si condición	
	 * 			falsa;
	 *    }
	 * 
	 **/
	 
		// para este ejemplo usaremos un ejercicio para definir quien es el mayor de dos números
	 int a, b;
	 
	 printf("Introduzca número A:\n"); scanf("%d",&a);
	 printf("Introduzca número B:\n"); scanf("%d",&b);
	 
	 if ( a > b )
	 {
		 printf("El número A es MAYOR que B\n");
	 }
	 else if ( a < b )
	 {
		 printf("El número A es MENOR que A\n");
	 }
	 else
	 {
		 printf("El número A es IGUAl que B\n");
	 }
	 
			// con otro else if, se pueden anidar varios IF, haciendo
			// más eficiente la validaciones de condicionales, ya que al
			// entrar en alguno de primero obvia los demás.

	 
	 printf("\n\n"); getchar();
	 /**  Case: es una sentencia tiene que ver con el control de casos
	 *    que se puedan presentar en una variable, muy utilizado por lo
	 *    general en menús y/ó procesamiento de información explicita.
	 * 
	 *    Estructura:
	 *    
	 *    switch ( variable ) {
     * 		
     * 			case opción1: sentencias;
     * 						  break;
     *
     *          case opción2: sentencias;
     * 					 	  break;
     * 
     * 			case opciónN: sentencias;
     * 					 	  break;
     * 
     * 			default: sentencias;
     * 
     * 				// está opción tiene que ver cuando ninguna de las
     *              // propuestas anteriores es verdadera
     * 	  }
	 * 
	 **/
	 
		// para este ejemplo usaremos un ejercicio que define la seleción de un menú
	 char opc = ' ';
	 
	 printf("Seleccione una opción S/N:\n"); scanf("%c", &opc);
	 
	 switch ( opc ) {
		 
		 case 's' : printf("Usted seleccionó la opción S\n");
				    break;
		 
		 case 'S' : printf("Usted seleccionó la opción S\n");
				    break;
		 
		 case 'n' : printf("Usted seleccionó la opción N\n");
					break;
					
		 case 'N' : printf("Usted seleccionó la opción N\n");
					break;
					
		 default  :  printf("No ha seleccionado una opción válida.\n");
	 }
	 
	 
	 printf("\n\n"); getchar();
	 /**  Operador Ternario '?': el operador ternario, es un operador
	 *    que facilita el uso de un if abreviado, ejecutando una acción
	 *    si es verdadera o falsa según sea su caso.
	 * 
	 *    Estructura:
	 *    
	 *    ( condición ) ? sentenciaVerdadera : sentenciaFalsa;
     * 
     * 				// está opción sólo sirve para el compilador g++
     *              // es decir sólo funciona en C++. 
     * 				// (archivos con extensión .cpp)
	 * 
	 **/
	 
	 (  true ) ? printf("Es VERDAD\n") : printf("Es FALSO\n");
	 
	 ( false ) ? printf("Es VERDAD\n") : printf("Es FALSO\n");
	 
		// notese como una misma instrucción con diferentes respuestas
		// de condiciones ejecutan instrucciones según sea el caso de 
		// desición si es verdadero o falso.
	 
	 return 0;
 }
