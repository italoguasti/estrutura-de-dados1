#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para criar a árvore BST
void criar(No **no)
{
    *no = NULL;
}

void destruir(No **no)
{
    if (*no != NULL)
    {
        destruir(&(*no)->esq);
        destruir(&(*no)->dir);
        free(*no);
        *no = NULL;
    }
}

// Função auxiliar para criar um novo nó
No *criar_no(Item item)
{
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL)
    {
        printf("Erro ao alocar memória\n");
        return NULL;
    }
    novo_no->itens[0] = item;
    novo_no->n = 1;
    novo_no->esq = novo_no->dir = NULL;
    return novo_no;
}

// Função para inserir um preço na árvore
bool inserir(No **no, Item item)
{
    if (*no == NULL)
    {
        *no = criar_no(item);
        return true;
    }

    if (item.preco < (*no)->itens[0].preco)
    {
        return inserir(&(*no)->esq, item);
    }
    else if (item.preco > (*no)->itens[0].preco)
    {
        return inserir(&(*no)->dir, item);
    }
    else
    { // Preço igual, verifica se há espaço para adicionar
        if ((*no)->n < 10)
        {
            (*no)->itens[(*no)->n] = item;
            (*no)->n++;
            return true;
        }
        else
        {
            printf("Preço %d já atingiu o limite de 10 itens.\n", item.preco);
            return false;
        }
    }
}

void imprimeNo(No *no)
{
    printf("%d ( ", no->itens[0].preco);
    for (int i = 0; i < no->n; i++)
    {
        printf("[%s|%s] ", no->itens[i].cultura, no->itens[i].fazenda);
    }
    printf(")\n");
}

void imprimeIn(No *no, int a, int b)
{
    if (no == NULL)
        return;

    if (no->itens[0].preco >= a)
    {
        imprimeIn(no->esq, a, b);
    }

    if (no->itens[0].preco >= a && no->itens[0].preco <= b)
    {
        imprimeNo(no);
    }

    if (no->itens[0].preco <= b)
    {
        imprimeIn(no->dir, a, b);
    }
}

void imprimePre(No *no, int a, int b)
{
    if (no == NULL)
        return;

    if (no->itens[0].preco >= a && no->itens[0].preco <= b)
    {
        imprimeNo(no);
    }

    if (no->itens[0].preco >= a)
    {
        imprimePre(no->esq, a, b);
    }

    if (no->itens[0].preco <= b)
    {
        imprimePre(no->dir, a, b);
    }
}

void imprimePos(No *no, int a, int b)
{
    if (no == NULL)
        return;

    if (no->itens[0].preco >= a)
    {
        imprimePos(no->esq, a, b);
    }

    if (no->itens[0].preco <= b)
    {
        imprimePos(no->dir, a, b);
    }

    if (no->itens[0].preco >= a && no->itens[0].preco <= b)
    {
        imprimeNo(no);
    }
}
