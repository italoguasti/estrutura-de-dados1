#ifndef lista_h
#define lista_h

typedef char Item; // O Item é um char

typedef struct celula
{
    Item item;
    struct celula *prox;
} TCelula;

typedef struct
{
    TCelula *primeiro;
    TCelula *ultimo;
} Lista; // Lista é uma lista encadeada com cabeça

// Inicializa a lista e retorna se foi possível
int ListaInicia(Lista *pLista);

// Retorna se a lista está vazia
int ListaEhVazia(Lista *pLista);

// Insere um item no início da lista e retorna se a inserção ocorreu
int ListaInserePrimeiro(Lista *pLista, Item item);

// Retira o primeiro item da lista e retorna se foi possível ou não
int ListaRetiraPrimeiro(Lista *pLista, Item *pItem);

// Imprime os elementos da lista
void ListaImprime(Lista *pLista);

// Remove e libera memória de cada elemento de uma lista
void ListaEsvazia(Lista *pLista);

#endif
