#include "pilha.h"

// Inicia as variáveis da pilha
int PilhaInicia(Pilha *pPilha)
{
    return ListaInicia(pPilha);
}

// Retorna se a pilha está vazia
int PilhaEhVazia(Pilha *pPilha)
{
    return ListaEhVazia(pPilha);
}

// Insere um item na pilha
int PilhaPush(Pilha *pPilha, Item item)
{
    return ListaInserePrimeiro(pPilha, item);
}

// Retira um item da pilha
int PilhaPop(Pilha *pPilha, Item *pItem)
{
    return ListaRetiraPrimeiro(pPilha, pItem);
}

// Remove e libera memória de cada elemento de uma pilha
void PilhaEsvazia(Pilha *pPilha)
{
    ListaEsvazia(pPilha);
}
