#ifndef pilha_h
#define pilha_h

#include "lista.h"

typedef Lista Pilha; // Pilha é uma Lista

// Inicializa a pilha e retorna se foi possível ou não
int PilhaInicia(Pilha *pPilha);

// Retorna se a pilha está vazia
int PilhaEhVazia(Pilha *pPilha);

// Insere um item na pilha
int PilhaPush(Pilha *pPilha, Item item);

// Retira um item da pilha
int PilhaPop(Pilha *pPilha, Item *item);

// Remove e libera memória de cada elemento de uma pilha
void PilhaEsvazia(Pilha *pPilha);

#endif
