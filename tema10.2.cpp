/*
 *  Preparador: José Abraham (abrahamjoc@gmail.com)
 *  Diciembre 2013
 *  Asignatura: Programación 2
 *  
 *  Tema X.2: Listas Enlazadas Avanzadas en Lenguaje C
 * 	
 * 		Existen otras formas de manejar listas enlazadas, en este tema
 *  trabajaremos funciones más refinadas que pueden ayudar a entender y
 *  procesar mejor el manejo de las listas.
 * 
 *  Una de esas formas es trabajar listas con modificación de doble
 *  apuntador lo que permite tener una función más limpia desde el
 *  aspecto de no tener que retornar una lisa modificada a una variable
 *  que previamente fue pasada como parámetro.
 *  
 *  Tópicos:
 *  - insertarElemento ( Con ** apuntador definiendo al inicio o final )
 *  - eliminarElemento ( Con ** apuntador definiendo si es uno o todos )
 *  - vaciarElementos  ( Con ** apuntador )
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	
	int dato;
	
	struct nodo *sig;
	
}NODO;


///Prototipos de Función
void imprimirLista(NODO *lista);
void insertarElemLista(NODO **lista, int elem, int alFinal);
void eliminarElemLista(NODO** lista, int elem, int todos);
void vaciarLista(NODO **lista);


int main()
{
		// declaramos lista
	NODO *lista = NULL;
	
		// imprimimos lista, estará VACIA
	imprimirLista(lista);
	
		// agregamos algunos nodos al final
	insertarElemLista(&lista, 1, 1);
	insertarElemLista(&lista, 3, 1);
	insertarElemLista(&lista, 6, 1);
	imprimirLista(lista);
	
		// agregamos algunos nodos al inicio
	insertarElemLista(&lista, 3, 0);
	insertarElemLista(&lista, 7, 0);
	insertarElemLista(&lista, 3, 0);
	imprimirLista(lista);
	
		// eliminar NODO con 7
	eliminarElemLista(&lista, 7, 0);
	imprimirLista(lista);
	
		// eliminar primera ocurrencia de 3
	eliminarElemLista(&lista, 3, 0);
	imprimirLista(lista);
	
		// eliminar todos los NODOS con 3
	eliminarElemLista(&lista, 3, 1);
	imprimirLista(lista);
	
		// agregamos algunos nodos al final
	insertarElemLista(&lista, 4, 1);
	insertarElemLista(&lista, 5, 1);
	imprimirLista(lista);
	
		// liberar nodos lista
	vaciarLista(&lista);
	imprimirLista(lista);
}


/// Imprimir todos los nodos de la lista
void imprimirLista(NODO *lista)
{
		// declaramos apuntador con el que recorremos la lista
	NODO *aux = lista;

		// imprimimos en pantalla nombre de accion
	printf("LISTA -> ");
	
		// mientras NODO en lista exista
	while ( aux )
	{
			// imprimimos elemento del NODO
		printf("[ %d ] -> ", aux->dato);
		
			// nos movemos al siguiente NODO
		aux = aux->sig;
	}
	
		// imprimimos en pantalla que ya hemos recorrido todos los NODOS
	printf("NULL\n");
}


/// Insertar elemento en lista, determinando porque posición se anexa NODO
void insertarElemLista(NODO **lista, int elem, int alFinal)
{
		// NODO auxiliar apunta al contenido de la lista para modficarlo
	NODO *aux = *lista;
	
		// declaramos, creamos e inicializamos NODO nuevo
	NODO *nuevo = (NODO*)malloc(sizeof(NODO));
	nuevo->dato = elem;
	nuevo->sig  = NULL;
	
		// si contenido de lista tiene nodos
	if ( *lista )
	{
			// si es al final que hay que colocarlo
		if ( alFinal )
		{
				// mientras auxiliar tenga siguiente nodo
			while ( aux->sig )
					// moverme al siguiente nodo
				aux = aux->sig;
			
				// en el último nodo -> siguiente se pone a apuntar al nuevo nodo
			aux->sig = nuevo;
		}
		else
		{				
				// nuevo -> siguiente al primer nodo de la lista
			nuevo->sig = *lista;
			
				// lista apunta al nuevo nodo que ahora pasa a ser el primero
			*lista = nuevo;
		}
	}
	else
			// en caso contrario, el primer nodo es el nuevo nodo creado
		*lista = nuevo;
}


/// Eliminar NODO de un elemento en la lista
void eliminarElemLista(NODO** lista, int elem, int todos)
{
	NODO *auxlista = *lista;
	
		// si lista existe, procesemos
	if ( *lista )
	{
			// mientras cabecera contenga el elemento
		while ( auxlista->dato == elem )
		{
				// movemos lista al siguiente nodo
			*lista = auxlista->sig;
			
				// liberamos el NODO
			free(auxlista);
			
				// si no hay que borrar todos o al borra llegamos al final
			if ( !todos || !*lista )
					//retorna
				return;
				
				// inicializa auxlista
			auxlista = *lista;
		}
		
			// declaramos apuntador con el que procesaremos la lista
		NODO *auxant = auxlista;
		NODO *aux    = auxlista->sig;
		
			// mientras exista NODO SIG
		while ( aux )
		{
				// si dato del NODO contiene ELEMENTO
			if ( aux->dato == elem )
			{
					// auxiliar anterior lo movemos al NODO SIGUIENTE
				auxant->sig = aux->sig;
				
					// liberamos NODO
				free(aux);
				
					// si no hay que borrar todos
				if ( !todos )
						// retorna
					return;
					
				else
						// en caso contrario, NODO sera el siguiente del anterior
					aux = auxant->sig;
			}
			else
			{
					// en caso contrario, debemos mover los apuntadores
				auxant = auxant->sig;
				aux    = aux->sig;
			}
		}
	}
}


/// Liberar todos los NODO's de la lista
void vaciarLista(NODO **lista)
{	
		// apuntador auxiliar para no perder la lista
	NODO *aux, *auxlista = *lista;
	
		// mientras NODO en lista exista
	while ( auxlista )
	{
			// auxiliar apunta a la cabecera de la lista
		aux = auxlista;
		
			// lista cabecera muevete al siguiente NODO
		auxlista = auxlista->sig;
		
			// libera NODO cabecera anterior
		free(aux);
	}
	
		// borrados todos, lista debe apuntar a NULL
	*lista = NULL;
}
