#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

// Inicia as variáveis da lista
int ListaInicia(Lista *pLista)
{
    pLista->primeiro = (TCelula *)malloc(sizeof(TCelula));
    if (pLista->primeiro == NULL)
        return 0;
    pLista->primeiro->prox = NULL;
    pLista->ultimo = pLista->primeiro;
    return 1;
}

// Retorna se a lista está vazia
int ListaEhVazia(Lista *pLista)
{
    return (pLista->primeiro == pLista->ultimo);
}

// Insere um item no início da lista
int ListaInserePrimeiro(Lista *pLista, Item item)
{
    TCelula *nova = (TCelula *)malloc(sizeof(TCelula));
    if (nova == NULL)
        return 0;
    nova->item = item;
    nova->prox = pLista->primeiro->prox;
    pLista->primeiro->prox = nova;
    if (nova->prox == NULL)
    {
        pLista->ultimo = nova;
    }
    return 1;
}

// Retira o primeiro item da lista
int ListaRetiraPrimeiro(Lista *pLista, Item *pItem)
{
    if (ListaEhVazia(pLista))
        return 0;
    TCelula *pAux = pLista->primeiro->prox;
    *pItem = pAux->item;
    pLista->primeiro->prox = pAux->prox;
    if (pLista->primeiro->prox == NULL)
    {
        pLista->ultimo = pLista->primeiro;
    }
    free(pAux);
    return 1;
}

// Imprime os elementos da lista
void ListaImprime(Lista *pLista)
{
    TCelula *pAux = pLista->primeiro->prox;
    while (pAux != NULL)
    {
        printf("%c ", pAux->item);
        pAux = pAux->prox;
    }
    printf("\n");
}

// Remove cada elemento de uma lista e libera a memória
void ListaEsvazia(Lista *pLista)
{
    Item dummy;
    while (!ListaEhVazia(pLista))
    {
        ListaRetiraPrimeiro(pLista, &dummy);
    }
}
