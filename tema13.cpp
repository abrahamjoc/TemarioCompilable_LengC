/*
 *  Preparador: José Abraham (abrahamjoc@gmail.com)
 *  Diciembre 2013
 *  Asignatura: Programación 2
 *  
 *  Tema XIII: Manejo de Archivos de Texto y Binarios en Lenguaje C
 * 	
 *      En todos los anteriores temas nos dedicamos a aprender a dominar
 *  la declaración y procesamiento de datos en tiempo de ejecución de
 *  nuestro programa.
 *  
 *  El problema principal que ahora tenemos es que toda la información es
 *  retenida siempre en Memoria RAM (memoria volátil), y al culminar la
 *  corrida del programa los datos desaparecen.
 * 
 *  La solución a este problema es trabajar con ficheros, mejor conocidos
 *  como archivos, estos consisten en almacenar la información en medios
 *  de almacenamiento estándar que tengan la capacidad de poseer memoria
 *  no volátil, casi siempre discos mágneticos o memorias flash.
 * 
 *  Un fichero se define como la comunicación de un stream en nuestro
 *  programa que interactua con un buffer en memoria RAM que a su vez
 *  este se comunica con el dispositivo de almacenamiento.
 * 
 *  Una descripción gráfica podría ser así:
 * 
 *      ... Memoria RAM ..........         ... Disp. Almacenamiento ..
 *  |   ________      ________   |     |     ___________________     |
 *  |  | stream |--->| buffer |--|-----|--->| Fichero ó Archivo |    |
 *  |   --------      --------   |     |     -------------------     |
 *  '............................'     '.............................'
 * 
 *       stream: es el flujo en nuestro programa que gestiona la lectura
 *               o escritura sobre el archivo.
 * 
 *       buffer: es la dirección asignada que apunta al sector donde se
 *               procesa la información en disco, el tipo de operación
 *               que hagamos dependerá de cómo manejemos el stream.
 * 
 *      fichero: es finalmente la información almacenada en disco, está
 *               dirección es referencia en el buffer, para que el SO que
 *               gestiona nuestro proceso tenga una idea de hacia donde
 *               escribe o lee en los sectores del medio de almacenamiento.
 * 
 * 
 *  Estructura:
 * 
 *  	Para trabajar con ficheros en Leng. C se deben seguir los
 *  siguientes pasos:
 * 
 *  FILE *file;
 * 
 *  file = fopen("dirección del archivo (incluyendo nombre)", "modo") ;
 * 
 *  	manejamos archivo con las funciones para manejo de ficheros...
 * 
 *  fclose(file);
 * 
 * 
 *  	Los modos de acceso tienen que ver con la definción con que tipo
 *  de archivos trabajaremos, esos tipos son de texto ó binarios.
 * 
 * 
 * 	Tipo Texto: estos ficheros están compuestos por texto plano, es decir
 *                  cadenas de carácteres que son leibles enteramente por
 *                  editores de texto convencionales.
 * 
 * 		Sus modos de acceso son:
 * 
 *                  - r : lectura   (  read  )
 *                  - w : escritura (  write )
 *                  - a : agregar   ( append )
 *                  - rw: lectura y escritura
 * 
 * 
 *  Tipo Binario: estos ficheros estan compuestos por almacenar información
 *                en forma binaria, es decir se almacena las estructuras
 *                tal cúal se encuentran en memoria, no son legibles por
 *                editores de texto convencionales.
 * 
 * 		Sus modos de acceso son los mismos que el de texto, pero
 *  terminando en el carácter  'b'  .
 * 
 *                  -rb : lectura binaria   (   read binary )
 *                  -rw : escritura binaria (  write binary )
 *                  -ab : agregar binaria   ( append binary )
 *                  -rwb: lectura y escritura binaria
 * 
 *  Tópicos:
 * 
 *  - escribir en fichero de texto
 *       > fprintf
 *       > fputs
 *       > fputc
 * 
 *  - leer en fichero de texto
 *       > fscanf
 *       > fgets
 *       > fgetc
 * 
 *  - escribir en fichero binario
 *       > fwrite
 *  
 *  - leer en fichero binario
 *       > fread
 */
 
#include <stdio.h>
#include <string.h>

int main()
{
	/** Remove: Significa remover en ingles, y es una función que nos
	 *          permite eliminar ficheros en disco.
	 * 
	 *  Estructura:
	 * 
	 *  	remove("dirección de fichero en disco") ;
	 */
	
		// eliminamos los archivos de la práctica si existen para empezar
		// desde cero.
		
	remove("archivo.txt"); remove("archivo.bin");
	
		// NOTA: para objeto de esté tema trabajaremos con un archivo de
		//       tipo TEXTO y otro de tipo BINARIO.
		
	
	/**   FILE * : Es una estructura estándar definida que se utiliza para
	 *             apuntar a direcciones de ficheros en dispositivos.
	 * 
	 * 	  Esté controla el flujo de Entrada/Salida hacia la dirección que
	 *    declaremos.
	 * 
	 *    Fopen : Significa abrir archivo en ingles que viene de la 
	 *    traducción de File OPEN. Está palabra reservada sirve para poder
	 *    pedir la dirección de un fichero en un medio físico. Si no puede
	 *    abrirlo el apuntador devolvido es NULL.
	 * 
	 *    Estructura:
	 * 
	 * 	  	FILE *file = fopen("dirección fichero", "modo") ;
	 */
	
		// declarando apuntador tipo FILE (archivo) para manejar flujo E/S
	FILE *file;
	
		// abriendo archivo de texto
		// su dirección es la carpeta local
		// su nombre es archivo.txt
		// en modo de escritura, es decir sólo podremos escribir en él
	file = fopen("archivo.txt","w");


	/**   Para escribir en el archivo se utilizan varias funciones que han
	 *    sido desarrolladas de manera estándar para eso.
	 * 
	 * 
	 * 		Fprintf: Significa imprimir en archivo adelante en ingles que
	 *      viene de la traducción de File PRINT Forward su estructura,
	 *      permite un formato de salida muy al estilo del printf.
	 * 
	 * 			- fprintf ( FILE*, "formato de salida", variables ) ;
	 * 
	 * 
	 * 		Fputs  : Significa poner cadena en archivo en ingles que viene
	 *      de la traducción de File PUT String, aca se escribe en el
	 *      archivo una cadena explicitamente.
	 * 
	 *	 		- fputs ( char*, FILE* ) ;
	 * 
	 * 
	 * 		Fputc  : Significa poner carácter en archivo en ingles que
	 *      viene de la traducción de File PUT Caracter, aca se escribe
	 *      en el archivo un carácter explicitamente.
	 * 
	 *                      - fputc ( (int)char , FILE* ) ;
	 */

		// escribiendo una cadena y un entero bajo formato
	fprintf(file, "Escrito en %s de %d\n", "Diciembre", 2013);
	
		// se puede escribir sólo cadenas de carácteres
	fputs("Tema de Ficheros o Archivos en Lenguaje C\n", file);
	
		// escribiendo carácter a carácter Jose A.
	fputc('J',file); fputc('o',file); fputc('s',file); fputc('e',file); 
	fputc(' ',file); fputc('A',file); fputc('.',file); fputc('\n',file);
	
	printf("Se escribió en archivo datos de texto, revisa el archivo.txt\n");
	
	
	/**   Fflush : Signfica sofocar archivo en ingles que viene de la
	 *    traducción de File FLUSH, está palabra reservada sirve para
	 *    pujar cualquier dato que se encuentre en el buffer gestionado
	 *    en memoria RAM hacia el fichero, asegurandose de que todo dato
	 *    que halla quedado pendiente por operar se escriba de manera
	 *    inmediata. Retorna 0 si el stream ha sido despejado con éxito,
	 *    en caso contrario retorna EOF.
	 * 
	 *    Muy útil cuando utilizamos algoritmos donde no podemos cerrar
	 *    el archivo para terminar de escribir el flujo.
	 * 
	 * 			fflush ( FILE* ) ;
	 */
	 
		// asegurandome de que todo el buffer sea escrito
	fflush(file);
	
	
	/**   Fclose : Significa cerrar archivo en ingles que viene de la
	 *    traducción de File CLOSE, está palabra reservada sirve para
	 *    despejar un archivo y luego cerrar la conexión de nuestro
	 *    programa con ese archivo.
	 */
	
		// cerrando archivo de texto
	fclose(file);
	
	
	printf("\n\nSe leyó del archivo.txt: \n");
	
		// abriendo archivo de texto en modo lectura
	file = fopen("archivo.txt","r");
	
	
	/**   Para leer del archivo se utilizan varias funciones que han
	 *    sido desarrolladas de manera estándar tambien para eso.
	 * 
	 * 
	 * 		Fscanf: Significa escanear en archivo adelante en ingles que
	 *      viene de la traducción de File SCAN Forward su estructura,
	 *      permite un formato de entrada muy al estilo de scanf.
	 * 
	 * 			- fscanf ( FILE*, "formato de entrada", variables ) ;
	 * 
	 * 
	 * 		Fgets  : Significa obtener cadena de archivo en ingles que
	 *      viene de la traducción de File GET String, aca se lee del
	 *      archivo una cadena explicitamente y es retornado a la cadena
	 *      que sea pasada por parámetro.
	 * 
	 *	 		- fgets ( char*, número máximo de carácteres, FILE* ) ;
	 * 
	 * 
	 * 		Fgetc  : Significa obtener carácter de archivo en ingles que
	 *      viene de la traducción de File GET Caracter, aca se lee del
	 *      archivo un carácter explicitamente y es retornado por la
	 *      función.
	 * 
	 *                      - (int)char fgetc ( FILE* ) ;
	 */
	
		// declarando cadena para lectura
	char cadena[255] = "";
	
		// declarando numero para lectura
	int dato;
	
															// fscanf
	printf("\nfscanf:   ");
	
		// leyendo las primeras palabras que representan
	for ( int i=0; i<4; i++ )
	{
			// obtengo cadenas, que se separán por espacios ' '
		fscanf(file, "%s", cadena);
		
			// muestro lo leído
		printf("%s ", cadena);
	}
	
		// se que estoy posicionado en 2013 y lo leo como número
	fscanf(file, "%d", &dato);
	
		// muestro lo leído
	printf("%d\n\n", dato);
															
		// leyendo \n final de linea para poder usar fgets
	fgetc(file);
	
	
															// fgets
	printf(" fgets:   ");
	
		// leyendo la cantidad de carácteres de la 2da linea
	fgets(cadena, 100, file);
	
			// NOTA: observese que a pesar de que colocamos una cantidad
			//       exagerada, el fgets leerá hasta EOL ó EOF
			//		
			//     EOL: End Of Line ( Fin de Linea   representado por '\n' )
			//     EOF: End Of File ( Fin de Archivo representado por '\0' )
	
		// muestro lo leído
	printf("%s\n", cadena);
	printf("   Se intentó leer 100 caracteres, ");
	printf("pero se leyeron %d.\n\n", strlen(cadena));
	
	
															// fgetc
	printf(" fgetc:   ");
	
		// inicializar dato con primer carácter leido
		// mientras dato sea diferente de fin de archivo
		// continuar leyendo dato
	for ( dato=fgetc(file); dato!=EOF; dato=fgetc(file) )
			// imprimir carácter
		printf("%c", dato);
		
	
		// cerrando archivo de texto
	fclose(file);
	
	
	
		// abriendo archivo binario
		// su dirección es la carpeta local
		// su nombre es archivo.bin
		// en modo de escritura, es decir sólo podremos escribir en él
	file = fopen("archivo.bin","wb");
	
	
	/**   Fwrite : Signfica escribir a archivo en ingles que viene de la
	 *    traducción de File WRITE, está palabra reservada sirve para
	 *    escribir de manera binaria en cualquier fichero que halla sido
	 *    abierto en modo de stream binario. Esté almacena la información
	 *    de la forma en que se encuentra tal cual en memoria RAM.
	 *
	 * 
	 *    Estructura:
	 * 
	 * 	  fwrite ( var. escritura, tam. dato unitario, cant, FILE* ) ; 
	 */
	
		// hacer un ciclo de 10 iteraciones
	for ( int i=0; i<10; i++ )
			// almacenarlos en archivo binario
		fwrite(&i, sizeof(int), 1, file);
		
		// cerrando archivo binario
	fclose(file);
	
	printf("\n\n");
	printf("Se escribió en archivo datos binarios, revisar el archivo.bin\n");
	
	printf("\nSe leyó del archivo binario:\n\n");
	
		// abriendo archivo binario en modo lectura
	file = fopen("archivo.bin","rb");
	
	
	/**   Fread : Signfica leer de archivo en ingles que viene de la
	 *    traducción de File READ, está palabra reservada sirve para leer
	 *    de manera binaria en cualquier fichero que halla sido
	 *    abierto en modo de stream binario. Esté carga a una variable
	 *    en memoria RAM de la forma en que se encuentra tal cual antes,
	 *    siendo este reflejo de la información almacenada en dicho
	 *    fichero. La función devuelve el tamaño de la información leida,
	 *    si no lográ leer nada retorna 0.
	 *
	 * 
	 *    Estructura:
	 * 
	 * 	  size_t fread ( var. lectura, tam. dato unitario, cant, FILE* ) ; 
	 */
	 
	printf (" [ FORMA SECUENCIAL ] : ");
	 
		// declaración de entero para leer de archivo
	int n;
	
		// mientras devuelva lectura de enteros de archivo, seguir leyendo
	while ( fread(&n, sizeof(int), 1, file) )
			
			// mostrar lo leido
		printf("%d, ", n);
	
	
	/** Rewind: Significa rebobinar en ingles, y es una función que nos
	 *          permite retornar el puntero de archivo a la cabecera del
	 *          mismo, es decir devolvernos al inicio.
	 * 
	 *  Estructura:
	 * 
	 *  	rewind ( FILE* ) ;
	 */
	
		// moviendonos al inicio del archivo, para leerlo de nuevo
	rewind(file);
	
	
	printf ("\n [ FORMA  VECTORIAL ] : ");
	
		// declaración de vector de entero para leer de archivo
	int vn[10];
	
		// NOTA: como conocemos la cantidad de datos que queremos leer,
		//       hemos declarado un vector de enteros del tamaño justo
		//       y necesario para procesar la información.
	
	
		// cargando información en el vector de una sola vez
	fread(vn, sizeof(int), 10, file);
	
		// hacer 10 iteraciones, porque hicimos número finito de lectura
	for ( int i=0; i<10; i++ )
	
			// mostrar los números del vector números
		printf("%d, ", vn[i]);
	
	
		// cerrando archivo
	fclose(file);
	
	return 0;
}
