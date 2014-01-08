/*
 *  Preparador: José Abraham (abrahamjoc@gmail.com)
 *  Diciembre 2013
 *  Asignatura: Sistemas Operativos (LINUX)
 *
 *  Tema XIV.1: Hilos o Procesos Ligeros en Lenguaje C
 *
 * 		Muchas veces sucede que deseamos tener un programa que pueda
 *  hacer varias cosas al mismo tiempo, es decir que ciertos trozos de
 *  código puedan ser manejados paralelamente, para ello existe un
 *  fenómeno que en Ciencias de la Computación se conoce como concurrencia.
 *
 *  La concurrencia hemos dicho que permite poder hacer varias cosas a la
 *  vez, esto funciona cuando varios procesos de un mismo programa permiten
 *  exigir el recurso de ejecución de computo del procesador a través del
 *  algoritmo de planificación del Sistema Operativo, para lograr esto se
 *  pueden hacer dos cosas:
 *
 * 		1. Crear un nuevo proceso a través de fork() que bifurca un
 *         proceso haciendo una réplica igual que el proceso padre que lo
 *         crea, pero sin poder compartir recursos en memoria RAM para
 *         comunicarse entre sí y dependiendo de quien sea cada cosa
 *         realizar ciertas tareas especificas asignadas por su PID.
 *
 * 		2. Crear un proceso de un proceso padre, siendo esté una pequeña
 *  	   parte del mismo, en donde los mismos pueden compartir recursos
 *         en memoria RAM a través de las variables globales que se
 *         declaren en nuestro programa y su tarea asignada sea una función
 *         del mismo.
 *
 *   La opción dos(2) será la que trabajemos en esté tema, a esa técnica
 *   se le conoce como ejecución de hilos o procesos ligeros.
 *
 *   En UNIX la librería que permite el control del manejo de hilos se
 *   conoce como  <pthread.h>  que significa "Process THREAD" en ingles y
 *   viene de la traducción de Hilo de Procesos.
 *
 *
 * 		NOTA IMPORTANTE DE USO DE LIBRERIA:
 *
 *   Para que estás funciones puedan ser usadas en nuestro programa es
 *   necesario hacer modificaciones en las incursiones de compilación
 *   anexando la opción  -lpthread  para que linkee e incluya las librerias
 *   en nuestro archivo compilado.
 *
 *  Tópicos:
 *  - cocurrencia con hilo ó proceso ligero (LINUX)
 *  - declaración de función núcleo en hilo ó proceso ligero (LINUX)
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


/// Prototipos de Función
void* funcionNucleoHilo(void *arg);


int main()
{
	/**   Pthread_t: Significa Plantilla de Hilo de Proceso en ingles,
	 *    que viene de la traducción de Process THREAD Template, está
	 *    estructura gestiona la declaración de la variable de un hilo
	 *    o proceso ligero en nuestro programa.
	 */

		// declaración de hilo para ejecución concurrente
	pthread_t hilo;


	/**   Pthread_create: Significa Crear Hilo de Proceso en ingles,
	 *    que viene de la traducción de Process THREAD CREATE, está
	 *    función asocia el hilo a una función nucleo que debe tener
	 *    la siguiente estructura:
	 *
	 * 		void* nombreFunción ( void *arg ) ;
	 *
	 *
	 * 	  Estructura:
	 *
	 * 	pthread_create ( &hilo, NULL, nombreFunción, (void*) cad. arg.);
	 *
	 *
	 * 		NOTA: si no se desea pasar parámetros se pasa NULL en el
	 *            último argumento.
	 */

		// cadena para pase de parámetros como argumentos al hilo
	char nombreProceso[255];

		// asociando hilo a función y pasandole argumentos
	strcpy(nombreProceso, "Hilo");
	pthread_create(&hilo, NULL, funcionNucleoHilo, (void*)nombreProceso);


	printf("Demostrando concurrencia de proceso...\n\n");


		// la función main tendrá 10 iteraciones
	for ( int i=0; i<10; i++ )
	{
			// esperar 1 segundo
		sleep(2);

			// mostrar mensaje de main
		printf("Main: Procesando... Iteracion %d.\n", i);
	}


	/**   Pthread_join: Significa Unir Hilo de Proceso en ingles,
	 *    que viene de la traducción de Process THREAD JOIN, está
	 *    función inicia la ejecución del hilo siendo su código la
	 *    función previamente asociada con la función pthread_create,
	 *    y permite esperar a hilo.
	 *
	 * 	  Dependiendo de donde este sea colocado puede o no sincronizar
	 *    el proceso con la función principal main del programa.
	 *
	 * 	  Estructura:
	 *
	 * 		pthread_join ( &hilo, NULL ) ;
	 */

		// esperar por hilo antes de terminar programa
	pthread_join(hilo, NULL);

		// mostrar cuando termine sincronización
	printf("FIN\n");

	return 0;
}


/// Función asociada a la ejecución del hilo
void* funcionNucleoHilo(void *arg)
{
		// asigno semilla en tiempo
	srand(time(NULL));

		// recibo los parámetros recibidos
	char *nombre = (char*) arg;

		// hacer 10 iteraciones en concurrencia
	for ( int i=0; i<10; i++ )
	{
			// esperar aleatoriamente de 0 a 4 segundos
		sleep(rand()%5);

			// mostrar mensaje de hilo de proceso
		printf("Proceso:[ %s ] Procesando... Iteracion %d.\n", nombre, i);
	}

	return NULL;
}
