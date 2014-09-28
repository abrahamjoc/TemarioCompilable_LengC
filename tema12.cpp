/* 
 *  Preparador: José Abraham (abrahamjoc@gmail.com)
 *  Diciembre 2013
 *  Asignatura: Programación 2
 *  
 *  Tema XII: Árboles Binarios en Lenguaje C
 * 	
 *      Dominando el tema manejo de estructuras dinámicas y recursividad
 *  podemos comenzar a hablar de estructuras que posean mayor grado de
 *  eficiencia mezclando ambas técnicas, una de ellas es conocida como
 *  árbol binario, el mismo consiste en una estructura que tiene un NODO
 *  central llamado Raíz, que a su vez posee dos apuntadores tipo NODO
 *  que se encuentran figurativamente a la DERECHA y a la IZQUIERDA.
 * 
 *  Estructuralmente un árbol binario es una lista de listas, se organiza
 *  con datos que por lo general llevan una administración de objetos que
 *  representan valores medios en las raices; los valores de menor peso
 *  se organizan en el lado izquierdo y los de mayor peso a la derecha.
 * 
 *  Su desplazamiento se hace de manera recursiva, a través de los modos
 * 
 * 		- PreOrden :      Raíz, Izquierda, Derecha.
 * 		- InOrden  : Izquierda,      Raíz, Derecha.
 * 		- PostOrden: Izquierda,   Derecha, Raíz.
 * 		
 *                                   /|R|\  
 *                                |I|     |D|
 *                               /   \   /   \
 *                              |I| |D| |I|  |D|
 *                              N N N N N N  N N
 * 
 *  Tópicos:
 *  - insertar en árbol binario
 *  - representar en pantalla un árbol binario
 *  - eliminar en árbol binario
 *  - recorrido en PreOrden
 *  - recorrido en InOrden
 *  - recorrido en PostOrden
 *  - buscar en árbol binario
 *  - contar nodos de un árbol
 *  - contar nodos padres de un árbol
 *  - contar nodos abuelos de un árbol
 *  - vaciar un árbol binario
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct nodo {
	
	int dato;
	
	struct nodo *izq;
	
	struct nodo *der;
	
}ARBOL;


/// Muestra gráficamente el árbol binario en pantalla
void verArbol(ARBOL *arbol, int nivel=0)
{
		// declaración de profundidad más alta en árbol
	static int profundidad = 0;
		
		// si hoja no existe
	if ( !arbol )
			// culmina recursividad
		return;
	
		// si está es la mayor profundidad
	if ( nivel > profundidad )
			// marcala
		profundidad = nivel;
	
		// continua recursividad por la derecha, expresando un nivel mayor
	verArbol(arbol->der, nivel+1);
	
		// dependiendo del nivel actual
	for ( int i=0; i<nivel; i++ )
			// imprimir espacios para dibujar los nodos
         printf("      ");
    
		// si nivel es 0, es el nodo raíz
    if ( !nivel )
    {		
		for ( int i=0; i<profundidad; i++ )
				// imprimir varios \n para poder nivel el dibujo en pantalla
			printf("\n");
			
			// imprime nodo raiz
		printf("R->%d\n",arbol->dato);
		
		for ( int i=0; i<profundidad/2; i++ )
				// imprimir varios \n para poder nivel el dibujo en pantalla
			printf("\n");
	}	
	else
			// imprimir hojas
		printf("%d\n",arbol->dato);
         
         // continua recursividad por la izquierda, expresando un nivel mayor
    verArbol(arbol->izq, nivel+1);
}


/// Prototipos de Función
void insertarElemArbol(ARBOL **arbol, int elem);
void eliminarElemArbol(ARBOL **arbol, int elem);
int buscarElemArbol(ARBOL *arbol, int elem);
void preOrdenArbol(ARBOL *arbol);
void inOrdenArbol(ARBOL *arbol);
void postOrdenArbol(ARBOL *arbol);
int nodosHijos(ARBOL *arbol);
int nodosPadres(ARBOL *arbol);
int nodosAbuelos(ARBOL *arbol);
void vaciarArbol(ARBOL **arbol);


int main()
{
		// declarando árbol binario
	ARBOL *arbol = NULL;	
	
	printf("Mostrando ARBOL inicial\n(nodo izquierdo más abajo, nodo derecho más arriba):\n\n");
	
		// creando árbol
		// Nota: observemos que se pasa la dirección de la lista, esto
		//       con la intención de modificarlo.
	insertarElemArbol(&arbol,14);
	insertarElemArbol(&arbol, 4);
	insertarElemArbol(&arbol, 3);
	insertarElemArbol(&arbol, 9);
	insertarElemArbol(&arbol, 7);
	insertarElemArbol(&arbol, 5);
	insertarElemArbol(&arbol,15);
	insertarElemArbol(&arbol,18);
	insertarElemArbol(&arbol,16);
	insertarElemArbol(&arbol,17);
	insertarElemArbol(&arbol,20);		
	
		// mostrando árbol en pantalla,
		// los nodos izquierdos van más abajos
		// los nodos derechos van más arriba
	verArbol(arbol);
	
	printf("\nMostrando ARBOL modificado por nodos eliminados\n(nodo izquierdo más abajo, nodo derecho más arriba):\n\n");
	
		// eliminando algunos nodos del árbol
	eliminarElemArbol(&arbol, 4);
	eliminarElemArbol(&arbol, 9);
	eliminarElemArbol(&arbol,20);
	
		// ver modificación del árbol
	verArbol(arbol);
	
	printf("\n\nRecorrido en PreOrden:\n");
	
		// mostrando recorrido en preOrden  - R I D
	preOrdenArbol(arbol);
	
	printf("\n\nRecorrido en InOrden:\n");
	
		// mostrando recorrido en inOrden   - I R D
	inOrdenArbol(arbol);
	
	printf("\n\nRecorrido en PostOrden:\n");
	
		// mostrando recorrido en postOrden - I D R
	postOrdenArbol(arbol);
	
	printf("\n\nBuscando algunos elementos:\n");
	
		// buscando elemento 17
	printf("[17] -> "); 
	( buscarElemArbol(arbol,17) == 1 ) ? 
		printf("Encontrado\n") : printf("NO Encontrado\n");
	
		// buscando elemento 31
	printf("[31] -> "); 
	( buscarElemArbol(arbol,31) == 1 ) ? 
		printf("Encontrado\n") : printf("NO Encontrado\n");
		
	printf("\nAlgunos ejercicios con Arboles:\n");
	
		// contando cantidad de nodos existentes
	printf("Nodos HIJOS  : %d\n",nodosHijos(arbol));
	
		// contando cantidad de nodos padres
	printf("Nodos PADRES : %d\n",nodosPadres(arbol));
	
		// contando cantidad de nodos abuelos
	printf("Nodos ABUELOS: %d\n",nodosAbuelos(arbol));
	
		// liberando arbol en memoria
	vaciarArbol(&arbol);
}


/// Insertar hoja en un árbol, si este elemento ya existe no se insertará
void insertarElemArbol(ARBOL **arbol, int elem)
{	
		// declaración de hoja, en forma de modificación de lista
	ARBOL *hoja = *arbol;
	
		// si hoja no existe
	if ( !hoja )
	{
			// crear nodo nuevo e inicializarlo
		ARBOL *nuevo = (ARBOL*)malloc(sizeof(ARBOL));
		nuevo->dato = elem;
		nuevo-> izq = NULL;
		nuevo-> der = NULL;
		
			// lista arbol poner apuntar al nodo nuevo
		*arbol = nuevo;
	}
	
		// si elemento a insertar menor que elemento de la hoja
	else if ( elem < hoja->dato )
			// continua la recursividad en la dirección del nodo izquierdo
		insertarElemArbol(&hoja->izq,elem);
	
		// si elemento a insertar mayor que elemento de la hoja
	else if ( elem > hoja->dato )
			// continua la recursividad en la dirección del nodo derecho
		insertarElemArbol(&hoja->der,elem);
	
		// si hoja existe y el dato no es mayor o menor
	else
			// entonces el elemento existe
		printf("Ya este elemento existe en el ÁRBOL.\n");
}


/// Elimina una hoja del árbol, si se trata de la RAÍZ le asigna el valor 0
ARBOL* eliminarElemArbol(ARBOL **arbol, int elem)
{	
		// declaración de hoja para modificar lista
	ARBOL *hoja = *arbol;
	
		// si hoja existe
	if ( hoja )
	{
			// declaramos nodos auxiliares de izquierda y derecha
		ARBOL *auxi, *auxd;
		
			// si dato hoja igual a elemento que queremos eliminar
		if ( hoja->dato == elem )
		{		
				// si ninguna de las hojas existe
			if ( !hoja->izq && !hoja->der )
			{
					// liberar hoja
				free(hoja);
				
					// apuntar hoja a NULL
				*arbol = NULL;
				
					// retornar NULL
				return NULL;
			}
			
				// si hoja izquierda no existe
			else if ( hoja->izq == NULL )
			{
					// marcar la hoja derecha
				auxd = hoja->der;
				
					// liberar hoja
				free(hoja);
				
					// retornar hoja derecha marcada
				return auxd;
			}
			
				// si hoja derecha no existe
			else if ( hoja->der == NULL )
			{
					// marcar la hoja izquierda
				auxi = hoja->izq;
				
					// liberar hoja
				free(hoja);
				
					// retornar hoja izquierda marcada
				return auxi;
			}
			
				// en caso contrario tiene hijos izquierdo y derecho
			else
			{
					// marcar hijo derecho
				auxd = hoja->der;
				
					// marcar hijo izquierdo en el derecho
				auxi = hoja->der;
				
					// mientras exista hijo izquierdo, en hijo derecho marcado
				while ( auxi->izq )
						// moverme al hijo más izquierdo
					auxi = auxi->izq;
				
					// marcar auxiliar más izquierdo con el hijo izquierdo actual
				auxi->izq = hoja->izq;
					
					// liberar hoja
				free(hoja);
				
					// retornar hijo derecho marcado
				return auxd;
			}
		}
		
			// si dato de la hoja menor que elemento buscado
		if ( hoja->dato < elem)
				// se debe reestructurar el nodo derecho
			hoja->der = eliminarElemArbol(&hoja->der,elem);
			// en caso contrario
		else
				// se debe reestructurar el nodo izquierdo
			hoja->izq = eliminarElemArbol(&hoja->izq,elem);
	}
}


/// Busqueda eficiente de un elemento en el árbol, para ello se debe ubicar
/// si es mayor o menor, así identificamos hacia donde debemos movernos
int buscarElemArbol(ARBOL *arbol, int elem)
{
		// si hoja existe
	if ( arbol )
	{
			// si este elemento se encuentra en este NODO
		if ( elem == arbol->dato)
				// retornar encontrado
			return 1;
		
			// si elemento menor que el de este NODO
		if ( elem < arbol->dato )
				// continuar la recursividad por la izquierda
			return buscarElemArbol(arbol->izq,elem);
		
			// en caso contrario
		else
				// continuar la recursividad por la derecha
			return buscarElemArbol(arbol->der,elem);
	}
	
		// retornar no encontrado
	return 0;
}


/// Recorrido de árbol en forma de Raíz,Izquierda,Derecha
void preOrdenArbol(ARBOL *arbol)
{
		// si hoja existe
	if ( arbol )
			// mostrar en pantalla
		printf(" [ %d ] ", arbol->dato);
	
		// si hoja izquierda existe
	if ( arbol->izq )
			// sigue recursividad por la hoja izquierda
		preOrdenArbol(arbol->izq);
		
		// si hoja derecha existe
	if ( arbol->der )
			// sigue recursividad por la hoja derecha
		preOrdenArbol(arbol->der);;
}


/// Recorrido de árbol en forma de Izquierda,Raíz,Derecha
void inOrdenArbol(ARBOL *arbol)
{
		// si hoja izquierda existe
	if ( arbol->izq )
			// sigue recursividad por la hoja izquierda
		inOrdenArbol(arbol->izq);
		
		// si hoja existe
	if ( arbol )
			// mostrar en pantalla
		printf(" [ %d ] ", arbol->dato);
		
		// si hoja derecha existe
	if ( arbol->der )
			// sigue recursividad por la hoja derecha
		inOrdenArbol(arbol->der);
}


/// Recorrido de árbol en forma de Izquierda,Derecha,Raíz
void postOrdenArbol(ARBOL *arbol)
{
		// si hoja izquierda existe
	if ( arbol->izq )
			// sigue recursividad por la hoja izquierda
		postOrdenArbol(arbol->izq);
		
		// si hoja derecha existe
	if ( arbol->der )
			// sigue recursividad por la hoja derecha
		postOrdenArbol(arbol->der);
		
		// si hoja existe
	if ( arbol )
			// mostrar en pantalla
		printf(" [ %d ] ", arbol->dato);
}


/// Identificar cuántos nodos tiene un árbol
int nodosHijos(ARBOL *arbol)
{
		// si nodo existe
	if ( arbol )
	
			// seguir la recursividad por ambos hijos, contando nodo
		return 1 + nodosHijos(arbol->izq) + nodosHijos(arbol->der);
		
		// si no existe nodo, culminar recursividad no contando el nodo
	return 0;
}


/// Identificar cuántos nodos padres tiene un árbol
int nodosPadres(ARBOL *arbol)
{
		// si nodo existe
	if ( arbol )
	{
			// si tiene hijo por la izquierda y por la derecha
		if ( arbol->izq && arbol->der )
		
				// continua recursividad por ambos lados contando un padre
			return 1 + nodosPadres(arbol->izq) + nodosPadres(arbol->der);
			
			// si tiene hijo por la izquierdo pero no por la derecha
		if ( arbol->izq && !arbol->der )
				
				// continua la recursividad por la izquierda contando un padre
			return 1 + nodosPadres(arbol->izq);
			
			// si tiene hijo por la derecha pero no por la izquierda
		if ( !arbol->izq && arbol->der )
				
				// continua la recursividad por la derecha contando un padre
			return 1 + nodosPadres(arbol->der);
	}
	
		// si no ocurre ninguna de las anteriores es un nodo que no es padre
	return 0;
}


/// Identificar cuántos nodos abuelos tiene un árbol
int nodosAbuelos(ARBOL *arbol)
{
		// si nodo existe
	if ( arbol )
	{
			// si tiene hijo en la izquierda y la derecha
		if ( arbol->izq && arbol->der )
		
				// si tiene nieto por la izquierda o la derecha
			if ( arbol->izq->izq || arbol->izq->der || arbol->der->izq || arbol->der->der )
			
					// continuar la recursividad por la izquierda y la derecha contando que es abuelo
				return 1 + nodosAbuelos(arbol->izq) + nodosAbuelos(arbol->der);
		
			// si tiene hijo en la izquierda pero no en la derecha
		if ( arbol->izq && !arbol->der )
		
				// si tiene nieto por la izquierda
			if ( arbol->izq->izq || arbol->izq->der )
			
					// continuar la recursividad por la izquierda contando que es abuelo
				return 1 + nodosAbuelos(arbol->izq);
				
			// si tiene hijo en la derecha pero no en la izquierda
		if ( !arbol->izq && arbol->der )
		
				// si tiene nieto por la derecha
			if ( arbol->der->izq || arbol->der->der )
			
					// continuar recursividad por la derecha contando que es abuelo
				return 1 + nodosAbuelos(arbol->der);
	}
	
		// si ninguna de las anteriores es un nodo que no es abuelo
	return 0;
}


/// Liberar en Memoria RAM todos las hojas del árbol
void vaciarArbol(ARBOL **arbol)
{	
		// declarando hoja para manipulación del árbol
	ARBOL *hoja = *arbol;
	
		// si hoja existe
	if ( hoja )
	{
			// continuar recursividad por la izquierda
		vaciarArbol(&hoja->izq);
		
			// continuar recursividad por la derecha
		vaciarArbol(&hoja->der);
		
			// liberar hoja
		free(hoja);
			
			// apuntar hoja a NULL
		*arbol = NULL;
	}
}
