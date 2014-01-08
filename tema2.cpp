/*
 *  Preparador: José Abraham (abrahamjoc@gmail.com)
 *  Noviembre 2013
 *  Asignatura: Programación 2
 *  
 *  Tema II: Operadores en Lenguaje C
 * 
 *		Un procesador básicamente el trabajo que realiza  es comparar y
 *   hacer cálculos matemáticos de datos. Lenguaje C da instrucciones
 *   mediante operadores  que permiten interactuar con las variables
 *   de nuestro programa.
 * 
 *   Los operadores son usados bajo la siguiente sintaxis:
 * 	
 * 		variable1 (operador) variable2
 * 
 *   Existen 3 tipos de operadores en Lenguaje C:
 *       > Aritméticos : se utilizan para operaciones matemáticas
 *       > Lógicos     : se utilizan para comparar datos
 *       > Nivel Bits  : se utilizan para comparar datos a nivel de bits
 * 
 *  Tópicos: 
 *  - operadores aritméticos
 *  - operadores lógicos
 *  - operadores lógico-aritméticos
 *  - operadores de bits
 *  - acumuladores
 *  - contadores (incrementadores / decrementadores)
 */

#include <stdio.h>

int main()
{	 
	/**  Operadores Aritméticos: los operadores aritméticos en Leng. C
	 *   se utilizan para realizar operaciones matemáticas.
	 *
	 *   Los más usados son:
	 *
	 *      + : suma
	 * 	- : resta
	 * 	* : multiplicación
	 * 	/ : división 
	 *      % : módulo o resto de división
	**/
	printf("Esto es la     suma       de %d + %d = %d\n", 5, 3, 5+3);
	printf("Esto es la     resta      de %d - %d = %d\n", 5, 3, 5-3);
	printf("Esto es la multiplicación de %d * %d = %d\n", 5, 3, 5*3);
	printf("Esto es la    división    de %d / %d = %d\n", 5, 3, 5/3);
	printf("Esto es el módulo o resto de %d | %d = %d\n", 5, 3, 5%3);
	
	printf("Esto es división fracción de %f / %f = %f\n", 5.0, 3.0, 5.0/3.0);
		// nota: la división con fracción se deben hacer con flotantes
	
	
	printf("\n");
	/**  Operadores Lógicos: los operadores lógicos en Leng. C se 
	 *   utilizan para realizar operaciones de comparación de datos.
	 *   
	 *   Los más usados son:
	 *
	 * 		== : igualdad
	 * 		&& : y (analogía AND)
	 * 		|| : ó (analogía OR )
	 * 		!= : no igual a, distinto de
	**/
	
		// nota: debemos recordar que en C, no existen valores booleanos
		// por tanto verdero y falso, pasan a ser 1 y 0
		
	printf("verdadero == verdaro     : %d\n", 1==1);
	printf("  falso   ==  falso      : %d\n", 0==0);
	printf("verdadero ==  falso      : %d\n", 1==0);
	printf("  falso   == verdadero   : %d\n", 1==0);
	printf("\n");
	printf("verdadero && verdaro     : %d\n", 1&&1);
	printf("  falso   &&  falso      : %d\n", 0&&0);
	printf("verdadero &&  falso      : %d\n", 1&&0);
	printf("  falso   && verdadero   : %d\n", 1&&0);
	printf("\n");
	printf("verdadero || verdaro     : %d\n", 1||1);
	printf("  falso   ||  falso      : %d\n", 0||0);
	printf("verdadero ||  falso      : %d\n", 1||0);
	printf("  falso   || verdadero   : %d\n", 1||0);
	printf("\n");
	printf("verdadero != verdaro     : %d\n", 1!=1);
	printf("  falso   !=  falso      : %d\n", 0!=0);
	printf("verdadero !=  falso      : %d\n", 1!=0);
	printf("  falso   != verdadero   : %d\n", 1!=0);
	
	
	printf("\n");
	/**  Operadores Lógico-Aritméticos: los operadores lógico-aritméticos
	 *   en Leng. C se utilizan para realizar operaciones de comparación 
	 *   entre datos de tipo númericos.
	 *   
	 *   Los más usados son:
	 *
	 *     	 > : mayor que
	 * 	 < : menor que
	 * 	<= : menor o igual que
	 * 	>= : mayor o igual que
	**/
	printf("5 mayor que 3  ( 5 > 3 ) : %d\n",  5>3);
	printf("3 mayor que 5  ( 3 > 5 ) : %d\n",  3>5);
	printf("\n");
	printf("5 menor que 3  ( 5 < 3 ) : %d\n",  5<3);
	printf("3 menor que 5  ( 3 < 5 ) : %d\n",  3<5);
	printf("\n");
	printf("5 mayor-igual 3 ( 5>=3 ) : %d\n", 5>=3);
	printf("3 mayor-igual 5 ( 3>=5 ) : %d\n", 3>=5);
	printf("5 mayor-igual 5 ( 5<=5 ) : %d\n", 5>=5);
	printf("\n");
	printf("5 menor-igual 3 ( 5<=3 ) : %d\n", 5<=3);
	printf("3 menor-igual 5 ( 3<=5 ) : %d\n", 3<=5);
	printf("5 menor-igual 5 ( 5<=5 ) : %d\n", 5<=5);
	
	
	printf("\n");
	/**  Operadores de Bits: los operadores de bits en Leng. C se 
	 *   utilizan para realizar operaciones de comparación de los bits
	 *   que conforman sus datos.
	 *   
	 *   Estos son:
	 *
	 *   	! : negación
	 *     	& : y (analogía de AND)
	 * 	| : ó (analogía de OR )
	 *      ^ : ó exclusivo ( XOR )
	 * 
	 *  estos se diferencian de  && y ||  porque como dije antes se trabaja
	 *  a nivel binario.
	**/
	printf("verdadero negado         : %d\n",  !1 );
	printf("  falso   negado         : %d\n",  !0 );
	printf("\n");
	
		// nota: para efectos del ejemplo usaremos 'M'(77) y 'T'(84)
		// todo caracter tiene una representación decimal númerica, y
		// toda representación númerica tiene una expresión binaria.
		
	printf("  M(77)  &  T(84)        : %c(%d)\n", 'M'&'T', 'M'&'T');
		//  la operación que esta ocurriendo  01001101 & 
		//                                    01010100   = 01000100  D(68)
	
	printf("  M(77)  |  T(84)        : %c(%d)\n", 77|84, 77|84);
		//  la operación que esta ocurriendo  01001101 | 
		//                                    01010100   = 01011101  ](93)
		
	printf("  M(77)  ^  T(84)        : %c(%d)\n", 77^84, 77^84);
		//  la operación que esta ocurriendo  01001101 ^ 
		//  el resultado es un caracter esp.  01010100   = 00011001 EM(25)
		
	
	printf("\n");	
	/**  Acumuladores: los operadores acumuladores, son utilizados para
	 *   asignar el resultado de una variable que es igual a esa variable
	 *   mas una operación que pudiera ser aritmética ó lógica.
	 * 
	 *   Estos son:
	 *
	 * 	 [ Aritméticos ]
	 *     
	 * 		+= : acumular suma  	( var1 = var1 + valor )
	 *     		-= : acumular resta 	( var1 = var1 - valor )
	 * 	   	*= : acumular producto	( var1 = var1 * valor )
	 *     		/= : acumular división	( var1 = var1 / valor )
	 * 	   	%= : acumular módulo	( var1 = var1 % valor )
	 * 	
	 * 	 [   Lógicos   ]
	 *
	 * 		&= : acumulación AND	( var1 = var1 & valor )
	 * 		|= : acumulación OR	( var1 = var1 | valor )
	 *     		^= : acumulación OR Exc.( var1 = var1 ^ valor )
	**/
	int a=5, b=13; 
	printf("                    a=%d   , b=%d\n", a, b);
	
		// notese todo el recorrido de las variables en las operaciones
	printf("   a += b : %d   |  a=%d  , b=%d\n", a+=b, a, b);
	printf("   b -= a : %d   |  a=%d  , b=%d\n", b-=a, a, b);
	printf("   a *= b : %d  |  a=%d , b=%d\n",   a*=b, a, b);
	printf("   b /= a : %d   |  a=%d  , b=%d\n", a/=b, a, b);
	printf("   a(mod)= b : %d |  a=%d   , b=%d\n", a%=b, a, b);
	printf("\n");
	printf("   a &= b : %d\n", a&=b);
	printf("   a |= b : %d\n", a|=b);
	printf("   a ^= b : %d\n", a^=b);
	
	
	printf("\n");
	/**  Contadores: los operadores contadores, son utilizados para
	 *   incrementar o decrementar variables de uno en uno.
	 * 	 
	 * 	 Estos se pueden usar en forma de preOrden o postOrden.
	 * 
	 *   preOrden: 
	 * 			significa que 1ero se incrementa o decrementa la variable,
	 * 			y después hay ejecución de comando.
	 * 
	 *   postOrden:
	 * 			significa que 1ero hay ejecución de comando y luego
	 * 			se incrementa o decrementa la variable.
	 * 
	 *   Estos son:
	 *
	 * 	 	++: incrementa
	 * 		--: decrementa
	**/
	int i=9, j=4;
	printf("                     i=%d  , j=%d\n", i, j);
	
	
	printf("      i++ : %d", i++); printf("        i=%d , j=%d\n", i, j);
	printf("      j++ : %d", j++); printf("        i=%d , j=%d\n", i, j);
		// incremento en postOrden, notese que 1ero imprime y luego incrementa
	
		
	printf("      ++i : %d", ++i); printf("       i=%d , j=%d\n", i, j);
	printf("      ++j : %d", ++j); printf("        i=%d , j=%d\n", i, j);
		// incremento en preOrden, notese que 1ero incrementa y luego imprime
		
	
	printf("      i-- : %d", i--); printf("       i=%d , j=%d\n", i, j);
	printf("      j-- : %d", j--); printf("        i=%d , j=%d\n", i, j);
		// decremento en postOrden, notese que 1ero imprime y luego decrementa
	
		
	printf("      --i : %d", --i); printf("        i=%d  , j=%d\n", i, j);
	printf("      --j : %d", --j); printf("        i=%d  , j=%d\n", i, j);
		// decremento en preOrden, notese que 1ero decrementa y luego imprime
		
	return 0;
}
