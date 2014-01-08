/*
 *  Preparador: José Abraham (abrahamjoc@gmail.com)
 *  Diciembre 2013
 *  Asignatura: Sistemas Operativos (WINDOWS)
 *
 *  Tema XIV.2: Hilos o Procesos Ligeros en Lenguaje C
 *
 *      Muchas veces sucede que deseamos tener un programa que pueda
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
 *      1. Crear un nuevo proceso a través de fork() que bifurca un
 *         proceso haciendo una réplica igual que el proceso padre que lo
 *         crea, pero sin poder compartir recursos en memoria RAM para
 *         comunicarse entre sí y dependiendo de quien sea cada cosa
 *         realizar ciertas tareas especificas asignadas por su PID.
 *
 *      2. Crear un proceso de un proceso padre, siendo esté una pequeña
 *  	   parte del mismo, en donde los mismos pueden compartir recursos
 *         en memoria RAM a través de las variables globales que se
 *         declaren en nuestro programa y su tarea asignada sea una función
 *         del mismo.
 *
 *   La opción dos(2) será la que trabajemos en esté tema, a esa técnica
 *   se le conoce como ejecución de hilos o procesos ligeros.
 *
 *   En WINDOWS las librerías que permiten el control del manejo de hilos
 *   se conocen como  <windows.h> y <process.h>  que significa "Process"
 *   en ingles y viene de la traducción de Procesos.
 *
 *  Tópicos:
 *  - cocurrencia con hilo ó proceso ligero (WINDOWS)
 *  - declaración de función núcleo en hilo ó proceso ligero (WINDOWS)
 */

#include <windows.h>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


/// Variable para control concurrencia
int finConcurrencia = 0;


/// Prototipos de Función
void funcionNucleoHilo(void *arg);


int main()
{
		// cadena para pase de parámetros como argumentos al hilo
	char nombreProceso[255];


	/**   _beginthread: Significa Comenzar Hilo en ingles, que viene de
	 *    la traducción de BEGIN THREAD, está función inicia un hilo ó
	 *    proceso ligero con la función asignada.
	 */

		// asociando hilo a función y pasandole argumentos
	strcpy(nombreProceso, "Hilo");
	_beginthread(funcionNucleoHilo, 0, (void*)nombreProceso);


	printf("Demostrando concurrencia de proceso...\n\n");


		// la función main tendrá 10 iteraciones
	for ( int i=0; i<10; i++ )
	{
			// esperar 1 segundo y medio
		Sleep(1500);

			// mostrar mensaje de main
		printf("Main: Procesando... Iteracion %d.\n", i);
	}

		// esperar a que termine el hilo
	while ( !finConcurrencia );

		// mostrar cuando termine sincronización
	printf("FIN\n");

	return 0;
}


/// Función asociada a la ejecución del hilo
void funcionNucleoHilo(void *arg)
{
		// asigno semilla en tiempo
	srand(time(NULL));

		// recibo los parámetros recibidos
	char *nombre = (char*) arg;

		// hacer 10 iteraciones en concurrencia
	for ( int i=0; i<10; i++ )
	{
			// esperar aleatoriamente de 0 a 4 segundos
		Sleep(rand()%5*1000);

			// mostrar mensaje de hilo de proceso
		printf("Proceso:[ %s ] Procesando... Iteracion %d.\n", nombre, i);
	}

		// termino concurrencia
	finConcurrencia = 1;
}
