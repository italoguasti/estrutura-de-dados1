#ifndef ARVORE_H
#define ARVORE_H

#include <stdbool.h>

typedef struct
{
    int preco;
    char cultura[21];
    char fazenda[51];
} Item;

typedef struct no
{
    Item itens[10]; // No pode ter até 10 itens com o mesmo preço
    int n;          // Número de itens no nó
    struct no *esq; // Subárvore esquerda
    struct no *dir; // Subárvore direita
} No;

void criar(No **no);
void destruir(No **no);
bool inserir(No **no, Item item);
void imprimeIn(No *no, int a, int b);
void imprimePre(No *no, int a, int b);
void imprimePos(No *no, int a, int b);

#endif // ARVORE_H