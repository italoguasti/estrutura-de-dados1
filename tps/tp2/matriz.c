#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

// Função para alocar uma matriz esparsa
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

// Função para alocar uma matriz esparsa
MatrizEsparsa *alocarMatrizEsparsa(int ordem)
{
    MatrizEsparsa *matriz = (MatrizEsparsa *)malloc(sizeof(MatrizEsparsa));
    if (matriz == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para MatrizEsparsa.\n");
        exit(1);
    }

    matriz->ordem = ordem;
    matriz->linhas = (Celula **)malloc(ordem * sizeof(Celula *));
    matriz->colunas = (Celula **)malloc(ordem * sizeof(Celula *));

    if (matriz->linhas == NULL || matriz->colunas == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para linhas ou colunas.\n");
        exit(1);
    }

    // Inicializa as listas de linhas e colunas com NULL
    for (int i = 0; i < ordem; i++)
    {
        matriz->linhas[i] = NULL;
        matriz->colunas[i] = NULL;
    }

    return matriz;
}

// Função para desalocar uma matriz esparsa
void desalocarMatrizEsparsa(MatrizEsparsa *matriz)
{
    for (int i = 0; i < matriz->ordem; i++)
    {
        Celula *atual = matriz->linhas[i];
        while (atual != NULL)
        {
            Celula *prox = atual->proxLinha;
            free(atual);
            atual = prox;
        }
    }
    free(matriz->linhas);
    free(matriz->colunas);
    free(matriz);
}

// Função para inserir um elemento na matriz esparsa
void inserirCelula(MatrizEsparsa *matriz, int linha, int coluna)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    if (nova == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para Celula.\n");
        exit(1);
    }

    nova->linha = linha;
    nova->coluna = coluna;
    nova->proxLinha = NULL;
    nova->proxColuna = NULL;

    // Insere na lista de linhas
    nova->proxLinha = matriz->linhas[linha];
    matriz->linhas[linha] = nova;

    // Insere na lista de colunas
    nova->proxColuna = matriz->colunas[coluna];
    matriz->colunas[coluna] = nova;
}

// Função para remover um elemento da matriz esparsa
void removerCelula(MatrizEsparsa *matriz, int linha, int coluna)
{
    Celula *prev = NULL;
    Celula *atual = matriz->linhas[linha];

    while (atual != NULL && (atual->coluna != coluna))
    {
        prev = atual;
        atual = atual->proxLinha;
    }
    if (atual == NULL)
        return;

    if (prev == NULL)
    {
        matriz->linhas[linha] = atual->proxLinha;
    }
    else
    {
        prev->proxLinha = atual->proxLinha;
    }

    prev = NULL;
    atual = matriz->colunas[coluna];

    while (atual != NULL && (atual->linha != linha))
    {
        prev = atual;
        atual = atual->proxColuna;
    }

    if (atual == NULL)
        return;

    if (prev == NULL)
    {
        matriz->colunas[coluna] = atual->proxColuna;
    }
    else
    {
        prev->proxColuna = atual->proxColuna;
    }

    free(atual);
}

// Função para obter o valor de uma célula (0 ou 1)
int obterValorCelula(MatrizEsparsa *matriz, int linha, int coluna)
{
    Celula *atual = matriz->linhas[linha];
    while (atual != NULL)
    {
        if (atual->coluna == coluna)
        {
            return 1;
        }
        atual = atual->proxLinha;
    }
    return 0;
}

// Função para imprimir a matriz esparsa como uma matriz densa (com todos os valores)
void imprimirMatrizEsparsa(MatrizEsparsa *matriz)
{
    for (int i = 0; i < matriz->ordem; i++)
    {
        for (int j = 0; j < matriz->ordem; j++)
        {
            printf("%d ", obterValorCelula(matriz, i, j));
        }
        printf("\n");
    }
}