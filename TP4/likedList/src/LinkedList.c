#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this=(LinkedList*)malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
    	this->pFirstNode=NULL;
    	this->size=0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this !=NULL)
    {
    	returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int index;
	Node* nodeReturn=NULL;
	if(this!=NULL && nodeIndex >=0 && nodeIndex< ll_len(this))
	{
		nodeReturn=this->pFirstNode;
		for(index=0;index<nodeIndex;index++)
		{
			if(index==nodeIndex){
				break;
			}else{
				nodeReturn=nodeReturn->pNextNode;
			}
		}
	}
	return nodeReturn;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
	return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo=NULL;
    Node* anteriorNode=NULL;
    if(this != NULL && nodeIndex>=0 && nodeIndex <= ll_len(this))
    {
    	nuevoNodo=(Node*)malloc(sizeof(Node));
    	if(nuevoNodo!= NULL)
    	{
    		if(nodeIndex==0)
    		{
    			nuevoNodo->pNextNode=this->pFirstNode;
    			this->pFirstNode=nuevoNodo;
    			nuevoNodo->pElement=pElement;
    			this->size++;
    			returnAux=0;
    		}else{
    			anteriorNode=getNode(this,(nodeIndex-1));
    			if(anteriorNode!=NULL)
    			{
    				nuevoNodo->pNextNode=anteriorNode->pNextNode;
    				anteriorNode->pNextNode=nuevoNodo;
    				nuevoNodo->pElement=pElement;
    				this->size++;
    				returnAux=0;
    			}
    		}
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	if(!addNode(this,ll_len(this),pElement))
    	{
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* aux=NULL;
    if(this !=NULL && index>=0 &&index<ll_len(this))
    {
    	aux=getNode(this,index);
    	if(aux!=NULL)
    	{
    		returnAux=aux->pElement;
    	}
    }
    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* aux;
    if(this!=NULL && index >=0 && index< ll_len(this))
    {
    	aux=getNode(this, index);
    	if(aux!=NULL)
    	{
    		aux->pElement=pElement;
    		returnAux=0;
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodeAborrar = NULL;
    Node* pAnteriorNode=NULL;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
    	pNodeAborrar=getNode(this,index);
    	if(pNodeAborrar!=NULL)
    	{
    		if(index==0)
    		{
    			this->pFirstNode=pNodeAborrar->pNextNode;
    		}else
    		{
    			pAnteriorNode=getNode(this,(index-1));
    			if(pAnteriorNode!=NULL)
    			{
    				pAnteriorNode->pNextNode=pNodeAborrar->pNextNode;
    			}
    		}
    		free(pNodeAborrar);
    		pNodeAborrar=NULL;
    		this->size--;
    		returnAux=0;
    	}

    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;
    int i;
    if(this!=NULL)
    {
    	len=ll_len(this);
    	if(len>0)
    	{
    		for(i=len-1;i>=0;i--)
    		{
    			if(!(ll_remove(this,i)))
    			{
    				returnAux=0;
    			}
    		}
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL && !(ll_clear(this)))
    {
    	this=NULL;
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    if(this!=NULL)
    {
    	Node* pNode=NULL;
    	for(i=0;i<this->size;i++)
    	{
    		pNode=getNode(this,i);
    		if(pNode!=NULL && pNode->pElement==pElement)
    		{
    			pNode=getNode(this,i);
    			if(pNode!=NULL && pNode->pElement==pElement)
    			{
    				returnAux=i;
    				break;
    			}
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	if(this->size==0 && this->pFirstNode==NULL)
    	{
    		returnAux=1;
    	}else{
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && index>=0 && index<=this->size)
    {
    	if(!(addNode(this,index,pElement)))
    	{
    		returnAux=0;
    	}
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    Node* returnAux = NULL;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
    	returnAux=getNode(this,index);
    	if(returnAux!=NULL)
    	{
    		returnAux=returnAux->pElement;
    		ll_remove(this, index);
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    if(this!=NULL)
    {
    	returnAux=0;
    	Node* pNode=NULL;
    	for(i=0;i<this->size;i++)
    	{
    		pNode=getNode(this,i);
    		if(pNode!=NULL && pNode->pElement==pElement)
			{
				returnAux=1;
				break;
			}
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int contador=0;
    int i;
    if(this!=NULL && this2!=NULL)
    {
    	for(i=0;i<this2->size;i++)
    	{
    		Node *pNode=NULL;
    		pNode=getNode(this2,i);
    		if(pNode!=NULL && ll_contains(this, pNode->pElement))
    		{
    			contador++;
    		}
    	}
    	if(contador==this2->size)
    	{
    		returnAux=1;
    	}
    	else
    	{
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    if(this!=NULL && from>=0 && from<this->size && to>from && to<=this->size)
    {
    	cloneArray=ll_newLinkedList();
    	Node* pNode=NULL;
    	for(i=from;i<to;i++)
    	{
    		if((pNode=getNode(this,i))!=NULL)
    		{
    			addNode(cloneArray,i-from,pNode->pElement);
    		}
    	}

    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)
    {
    	if((cloneArray=ll_newLinkedList())!=NULL)
    	{
    		cloneArray=ll_subList(this,0,this->size);
    	}
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux =-1;
	int i;
	int flagSwap = 1;
	int criteria;
	void* pElement;
	void* pElement2;

	if (this != NULL && pFunc != NULL && (order == 0 || order == 1))
	{
		while (flagSwap)
		{
			flagSwap = 0;
			for (i = 0; i < ll_len(this)- 1; i++)
			{
				pElement = ll_get(this,i);
				pElement2 = ll_get(this,i+1);
				criteria = pFunc(pElement,pElement2);
				if ((order == 1 && criteria == 1) ||
					(order == 0 && criteria == -1))
				{
					ll_set(this,i,pElement2);
					ll_set(this,i+1,pElement);
					flagSwap = 1;
				}
			}
		}
		returnAux = 0;
	}
    return returnAux;

}

