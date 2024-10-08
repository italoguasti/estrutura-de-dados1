#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Função para iniciar a árvore AVL */
void inicia(No **ppRaiz)
{
    *ppRaiz = NULL;
}

/* Função para liberar memória da árvore AVL */
void libera(No **ppRaiz)
{
    if (*ppRaiz != NULL)
    {
        libera(&((*ppRaiz)->pEsq));
        libera(&((*ppRaiz)->pDir));
        free(*ppRaiz);
        *ppRaiz = NULL;
    }
}

/* Função para inserir um nó na árvore AVL */
bool insere(No **ppRaiz, Item x)
{
    if (*ppRaiz == NULL)
    {
        *ppRaiz = criaNo(x);
        return true;
    }

    RELACAO comparacao = compara(x, (*ppRaiz)->item);

    if (comparacao == MENOR)
    {
        if (insere(&((*ppRaiz)->pEsq), x))
        {
            if (Balanceamento(ppRaiz))
                return false;
        }
    }
    else if (comparacao == MAIOR)
    {
        if (insere(&((*ppRaiz)->pDir), x))
        {
            if (Balanceamento(ppRaiz))
                return false;
        }
    }
    else
    {
        (*ppRaiz)->cont++; // Incrementa a contagem de ocorrências da palavra
        return false;      // Se a palavra já existe, não insere novamente
    }

    return true;
}

/* Função para criar um novo nó na árvore */
No *criaNo(Item x)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    strcpy(novo->item.chave, x.chave);
    novo->cont = 1;
    novo->pEsq = NULL;
    novo->pDir = NULL;
    return novo;
}

/* Função para percorrer a árvore em ordem alfabética (in-order traversal) */
void caminhamento(No *pNo)
{
    if (pNo != NULL)
    {
        caminhamento(pNo->pEsq);
        printf("%s %d\n", pNo->item.chave, pNo->cont);
        caminhamento(pNo->pDir);
    }
}

/* Função para comparar duas palavras */
RELACAO compara(const Item item1, const Item item2)
{
    int response = strcmp(item1.chave, item2.chave);
    if (response < 0)
        return MENOR;
    else if (response > 0)
        return MAIOR;
    return IGUAL;
}

/* Função para calcular o fator de balanceamento */
int FB(No *pRaiz)
{
    if (pRaiz == NULL)
        return 0;
    return altura(pRaiz->pEsq) - altura(pRaiz->pDir);
}

/* Função para calcular a altura de um nó */
int altura(No *pRaiz)
{
    if (pRaiz == NULL)
        return 0;
    int alturaEsq = altura(pRaiz->pEsq);
    int alturaDir = altura(pRaiz->pDir);
    return (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
}

/* Rotação simples à esquerda */
void RSE(No **ppRaiz)
{
    No *aux = (*ppRaiz)->pDir;
    (*ppRaiz)->pDir = aux->pEsq;
    aux->pEsq = *ppRaiz;
    *ppRaiz = aux;
}

/* Rotação simples à direita */
void RSD(No **ppRaiz)
{
    No *aux = (*ppRaiz)->pEsq;
    (*ppRaiz)->pEsq = aux->pDir;
    aux->pDir = *ppRaiz;
    *ppRaiz = aux;
}

/* Função para balancear à esquerda */
int BalancaEsquerda(No **ppRaiz)
{
    if (FB((*ppRaiz)->pEsq) > 0)
    {
        RSD(ppRaiz);
        return 1;
    }
    else if (FB((*ppRaiz)->pEsq) < 0)
    {
        RSE(&((*ppRaiz)->pEsq));
        RSD(ppRaiz);
        return 1;
    }
    return 0;
}

/* Função para balancear à direita */
int BalancaDireita(No **ppRaiz)
{
    if (FB((*ppRaiz)->pDir) < 0)
    {
        RSE(ppRaiz);
        return 1;
    }
    else if (FB((*ppRaiz)->pDir) > 0)
    {
        RSD(&((*ppRaiz)->pDir));
        RSE(ppRaiz);
        return 1;
    }
    return 0;
}

/* Função para balancear um nó */
int Balanceamento(No **ppRaiz)
{
    int fb = FB(*ppRaiz);
    if (fb > 1)
    {
        return BalancaEsquerda(ppRaiz);
    }
    else if (fb < -1)
    {
        return BalancaDireita(ppRaiz);
    }
    return 0;
}