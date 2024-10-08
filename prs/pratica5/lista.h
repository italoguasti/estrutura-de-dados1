#ifndef lista_h
#define lista_h

#include <stdbool.h>

// MANTER COMO ESPECIFICADO
typedef struct
{
    char letra;
} Item;

// MANTER COMO ESPECIFICADO
typedef struct celula
{
    struct celula *pProx;
    Item item;
} Celula;

// MANTER COMO ESPECIFICADO
typedef struct
{
    Celula *pPrimeiro, *pUltimo;
} Lista;

// MANTER COMO ESPECIFICADO

// Inicializa a lista
void ListaInicia(Lista *pLista);
// Retorna se a lista está vazia
bool ListaEhVazia(Lista *pLista);
// Insere um item no final da lista
bool ListaInsereFinal(Lista *pLista, Item x);
// Retira o primeiro item da lista
bool ListaRetiraPrimeiro(Lista *pLista, Item *pX);
// Imprime os elementos da lista
void ListaImprime(Lista *pLista);
// Remove cada elemento de uma lista e libera a memória
void ListaEsvazia(Lista *pLista);
// Acrescenta o conteúdo de uma lista no início de outra, apenas manipulando ponteiros
void ListaInclude(Lista *pLista1, Lista *pLista2);
// Analisa a lista original e coloca os caracteres na lista resultado ou auxiliar
void resolve(Lista *original, Lista *resultado, Lista *auxiliar);

#endif
