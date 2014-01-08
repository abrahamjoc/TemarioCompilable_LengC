/*
 *  Preparador: José Abraham (abrahamjoc@gmail.com)
 *  Noviembre 2013
 *  Asignatura: Programación 2
 *  
 *  Tema I: Introducción al Lenguaje C
 * 
 * 	Lenguaje C es lenguaje de programación de medio nivel, es decir
 * trabaja  a nivel de  Sistema Operativo  y  Hardware, fue  creado por 
 * Dennis Ritchie en 1972 como evolución del Lenguaje B de Ken Thompson.
 * 
 * 	Es sumamente versatil, y es el lenguaje más ampliamente utilizado
 * en el mundo para el desarrollo de proyectos, fue el padre del primer
 * kernel de linux y muchos de sus programas base estan escritos en él.
 * 
 *  Tópicos: 
 * 		- estructura básica en Leng.C
 * 		- tipo de datos
 * 		- asignación
 * 		- comandos scanf, printf
 */


/**	 #include  : Especifica que se desea incluir una libreria.
	 <stdio.h> : Librería nativa que significa STandard Input Output,
	             Entrada/Salida Estandar,  aqui  se  encuentran  los 
	             comandos - > scanf y printf.
 **/
#include <stdio.h>


/**   int   :  Significa que al terminar retornara un valor entero hacia
 *             la aplicación que lo llamo externamente.
 *   main() :  Nombre del bloque principal de programa, es decir en donde
 *             iniciara la ejecución de las primeras líneas de comando a
 *             ejecutar.
 **/
int main()
{
	/**  Los tipos de datos definidos más usados en lenguaje C son: **/
	int   entero;	   // -32767 - 32768
	char  caracter;    // abcdefg@#$
	float flotante;	   // 1.18e-38 - 1.18e-38, con coma flotante
	
	char  cadena[255] = "hola mundo\n"; 
		// Cadena, este es un arreglo de carácteres, de una dimensión
	
	
	/**  Asignacion en C, para asignar en C se utiliza el operador '='
	 *   el cual me permite colocar dentro de mis variables información
	 *   a priori, determinada por mi. Su formato de código es
	 * 
	 *  	variable = misma información de dato; 
	 * 
	 *   (el ';' en Leng.C es un separador de comandos, es decir podriamos
	 *   escribir muchos comandos en una misma línea y separarlos para que
	 *   se diferencien entre ellos a la hora de ejecutarlos cuando sean
	 *   compilados.)
	 **/
	 
		// asignando un entero simple
	 entero = 1234;
	 
		// un caracter se asigna entre comilla simple '%c'
	 caracter = '@';
	 
		// un flotante se asigna con parte entera y fraccion a través 
		// de un '.'
	 flotante = 3.14;
	 
		// las cadenas solo pueden ser inicializadas cuando estas son 
		// creadas, y se logra a traves de comilla doble ", esto con la 
		// intención de diferenciarse de un caracter, indicando que este
		// es un arreglo de caracteres.
		// existen caracteres especiales, los cuales los más usados son:
		// '\n': fin de linea     (siguienet linea)
		// '\t': tabulador        (imprime un espacio de avanzada TAB)
		// '\r': retorno de carro (emula un retorno de carro ENTER)
	/** char cadena[255] = "hola mundo\n"; **/
	
	
	/**  Para Imprimir y Leer se utilizan las funciones printf y scanf,
	 *   la  'f'  en los  comandos significa formatted (formato), estos
	 *   se  utilizan para establecer  el esquema tanto de entrada como 
	 *   salida en los que interactuara mi programa con la pantalla y el
	 *   teclado definiendo sus tipos de datos.
	 * 
	 *   Los más usados son:
	 *   %i : integer  (entero)
	 *   %d : integer  (entero)
	 *   %c : caracter (caracter)
	 *   %f : float    (flotante)
	 *   %s : cadena de caracteres
	 **/
	
	/**  PRINT Formatted, imprimir formato, se usa para imprimir datos
	 *   por pantalla.
	 **/
	 printf("Esto es un entero  : %i\n", entero  );
	 printf("Esto es un caracter: %c\n", caracter);
	 printf("Esto es un flotante: %f\n", flotante);
	 printf("Esto es una cadena : %s\n", cadena  );
	 
	 
	/**  SCAN Formatted, escanear formato, se usa para leer datos del 
	 *   teclado y almacenarlos en las variables indicadas.
	 * 
	 *   como Lenguaje C trabaja a medio nivel, existe algo que se llama
	 *   direccionamiento de memoria, y como parametro se utiliza siempre
	 *   un '&' (ampersand) más la variable para indicarle al comando donde
	 *   esta la dirección de esa variable y poder modificar su contenido.
	 **/
	 printf("Int. valor entero  : ");   scanf("%i", &entero  );   getchar();
	 printf("Int. un caracter   : ");   scanf("%c", &caracter);   getchar();
	 printf("Int. valor flotante: ");   scanf("%f", &flotante);   getchar();
	 printf("Int. una cadena    : ");   scanf("%s", cadena   );   getchar();
			
			// notese que en cadena no se pasa '&', porque todo arreglo 
			// ya es implicitamente una direccion de memoria
			
			// cuando se lee una cadena con espacios es tomado solo la
			// primera sección y a partir del primer espacio lo demás
			// es omitido.
			
			// los getchar(), son utilizados para omitir los ENTER
			// entregados por el teclado en la lectura con "scanf"
		
		
	 /**  Imprimiendo en pantalla lo que leimos anteriormente **/
	 printf("\n");
	 printf("Esto es el entero   leido: %i\n", entero  );
	 printf("Esto es el caracter leido: %c\n", caracter);
	 printf("Esto es el flotante leido: %f\n", flotante);
	 printf("Esto es una cadena  leida: %s\n", cadena  );
	 
	 
	/**  Retorna una respuesta entera de salida, '0' significa en SO 
	 *   que el programa culmino sin problemas, en estado de normalidad. 
	 **/
	return 0;
}
