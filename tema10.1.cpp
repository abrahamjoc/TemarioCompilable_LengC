/*
 *  Preparador: José Abraham (abrahamjoc@gmail.com)
 *  Diciembre 2013
 *  Asignatura: Programación 2
 *  
 *  Tema X.1: Listas Enlazadas en Lenguaje C
 * 	
 *      En Ciencias de la Computación una Lista Enlazada es una de las
 *  estructuras de datos más fundamentales que existen, estas son usadas
 *  para implementar otras estructuras de datos que guardan a su vez datos
 *  arbitrarios y de referencias a otras estructuras.
 *  
 *  Dicho de otro modo, son una secuencia de NODOS enlazados entre sí,
 *  de manera dinámica que permiten guardar información especifica y
 *  almacenar direcciones de ¿cuál? son los siguientes NODO's de un
 *  determinado tipo.
 * 
 *  Tópicos:
 *  - typedef struct nodo { datos } NODO;
 *  - esListaVacia
 *  - insertarElemLista
 *  - imprimirLista
 *  - eliminarElemLista
 *  - buscarNodoLista
 *  - vaciarLista
 */
 
#include <stdio.h>
#include <stdlib.h>

	/**   Typedef Struc NODO: Para definir de manera clara y sencilla
	 *    la estructura que contendra un NODO de la lista.
	 * 
	 * 
	 *    Estructura:
	 *    
	 * 	  typedef struct nodo {
	 * 	  	
	 * 			tipo variable1;
	 * 			tipo varibale2;
	 * 			 ...  ...  ...
	 * 			tipo variableN;
	 * 
	 * 			struct nodo *sig;
	 *        } NODO;
	**/
	
typedef struct nodo {
	
	int dato;
	
	struct nodo *sig;
	
}NODO;


/// Prototipos de Función
void esListaVacia(NODO *lista);
void imprimirLista(NODO *lista);
NODO* insertarElemLista(NODO* lista, int elem);
NODO* eliminarElemLista(NODO* lista, int elem);
int buscarNodoLista(NODO* lista, int elem);
NODO* vaciarLista(NODO *lista);


int main()
{
		// para manejar una lista, se debe declarar una variable de
		// tipo apuntador NODO y asignarle NULL, esto con la intención
		// de que no quede aputando a basura que pueda estar en memoria
	
	NODO *lista = NULL;
	
		// demostrando que la lista esta vacia, es decir apunta a NULL
	printf("¿La Lista esta? : "); esListaVacia(lista);
	
	
	
		// insertando elementos en la lista
	lista = insertarElemLista(lista,3);
	lista = insertarElemLista(lista,5);
	lista = insertarElemLista(lista,8);
	lista = insertarElemLista(lista,3);
	lista = insertarElemLista(lista,9);
	lista = insertarElemLista(lista,3);
	lista = insertarElemLista(lista,7);
	
		// imprimiendo lo que se esta haciendo
	printf("\nSe insertaron algunos elementos en la LISTA\n");
	
		// demostrando que la lista NO esta vacia
	printf("¿La Lista esta? : "); esListaVacia(lista);
	
		// imprimir nodos de la lista
	imprimirLista(lista);
	
	
	
		// imprimiendo lo que se esta haciendo
	printf("\nEliminando los NODO's que contengan el elemento  3  en la LISTA\n");
	
		// eliminando los NODO's que contengan 3
	lista = eliminarElemLista(lista,3);
	
		// imprimir nodos de la lista para ver la modificación
	imprimirLista(lista);
	
	
	
		// imprimiendo lo que se esta haciendo
	printf("\nBuscando NODO con elemento 9\n");
	
		// buscar NODO con elemento 9
	printf("¿Elemento 9 en NODO? : %d\n", buscarNodoLista(lista,9));
	
	
	
		// vaciando toda la lista
	lista = vaciarLista(lista);
	
		// imprimiendo lo que se esta haciendo
	printf("\nVaciando LISTA\n");
	
		// imprimir nodos de la lista
	imprimirLista(lista);
	
	
	
	return 0;
}


/// ¿Está la lista vacía?
void esListaVacia(NODO *lista)
{
		// si lista no apunta a NULL, entonces existe
	if ( lista )
	
		printf("NO vacia\n");
	
	else
	
		printf("VACIA\n");
}


/// Insertar elemento en lista, retornando lista modificada
NODO* insertarElemLista(NODO* lista, int elem)
{
		// nunca se debe trabajar con el apuntador principal de la lista,
		// eso nos permite nunca perder la referencia de inicio de nuestra
		// lista, para eso declararemos un apuntador auxiliar
	NODO *aux = lista;
	
		// seguidamente declaramos el nodo nuevo y reservando la memoria
		// necesaria para su creación
	NODO *nuevo = (NODO*)malloc(sizeof(NODO));
	
		// inicializamos el contenido del nodo
	nuevo->dato = elem;
	nuevo->sig  = NULL;
	
		// si lista tiene nodos
	if ( lista )
	{
			// mientras auxiliar tenga siguiente nodo
		while ( aux->sig )
				// moverme al siguiente nodo
			aux = aux->sig;
			
			// en el último nodo -> siguiente se pone a apuntar al nuevo nodo
		aux->sig = nuevo;
	}
	else
			// en caso contrario, el primer nodo es el nuevo nodo creado
		lista = nuevo;
	
		// retornamos lista modificada
	return lista;
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


/// Eliminar todos los NODO's de un elemento en la lista
NODO* eliminarElemLista(NODO* lista, int elem)
{		
		// si lista existe, procesemos
	if ( lista )
	{
			// declaramos apuntador con el que procesaremos la lista
		NODO *auxant = lista;
		NODO *aux    = lista->sig;
		
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
				
					// NODO sera el siguiente del anterior
				aux = auxant->sig;
			}
			else
			{
					// en caso contrario, debemos mover los apuntadores
				auxant = auxant->sig;
				aux    = aux->sig;
			}
		}
		
			// volvemos a apuntar a cabecera, para evaluarla
		aux = lista;
		
			// si la cabecera contiene elemento
		if ( aux->dato == elem )
		{
				// movemos lista al siguiente nodo
			lista = lista->sig;
			
				// liberamos el NODO
			free(aux);
		}
	}
	
		// retornamos lista modificada
	return lista;
}


/// Busca primera ocurrencia de NODO que contenga el elemento indicado
int buscarNodoLista(NODO* lista, int elem)
{
		// declaramos apuntador con el que recorremos la lista
	NODO *aux = lista;
	
		// mientras NODO exista, contar buscando elemento
	for ( int i=1; aux!=NULL ; i++ )
	{
			// si dato en NODO contiene elemento
		if ( aux->dato == elem )
		
				// retornar posicion de NODO
			return i;
		
			// movernos al siguiente nodo
		aux = aux->sig;
	}
	
		// si recorrio toda la lista, y no encontro retornar -1
	return -1;
}


/// Liberar todos los NODO's de la lista
NODO* vaciarLista(NODO *lista)
{	
		// apuntador auxiliar para no perder la lista
	NODO *aux;
	
		// mientras NODO en lista exista
	while ( lista )
	{
			// auxiliar apunta a la cabecera de la lista
		aux = lista;
		
			// lista cabecera muevete al siguiente NODO
		lista = lista->sig;
		
			// libera NODO cabecera anterior
		free(aux);
	}
	
		// retorna lista modificada
	return lista;
}
