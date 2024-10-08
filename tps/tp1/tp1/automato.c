#include <stdio.h>
#include <stdlib.h>
#include "automato.h"

// Função para alocar o reticulado dinamicamente
AutomatoCelular *alocarReticulado(int ordem)
{
    AutomatoCelular *automato = (AutomatoCelular *)malloc(sizeof(AutomatoCelular));
    automato->ordem = ordem;
    automato->matriz = (int **)malloc(ordem * sizeof(int *));
    for (int i = 0; i < ordem; i++)
    {
        automato->matriz[i] = (int *)malloc(ordem * sizeof(int));
    }
    return automato;
}

// Função para desalocar o reticulado dinamicamente
void desalocarReticulado(AutomatoCelular *automato)
{
    for (int i = 0; i < automato->ordem; i++)
    {
        free(automato->matriz[i]);
    }
    free(automato->matriz);
    free(automato);
}

// Função para leitura do reticulado a partir do terminal
AutomatoCelular *leituraReticulado(int ordem)
{
    AutomatoCelular *automato = alocarReticulado(ordem);
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            scanf("%d", &automato->matriz[i][j]);
        }
    }
    return automato;
}

// Função para calcular os vizinhos vivos
int contarVizinhosVivos(AutomatoCelular *automato, int x, int y)
{
    int contagem = 0;
    int ordem = automato->ordem;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int ni = x + i;
            int nj = y + j;
            if (ni >= 0 && ni < ordem && nj >= 0 && nj < ordem)
            {
                contagem += automato->matriz[ni][nj];
            }
        }
    }
    return contagem;
}
/*
// Função para evoluir o reticulado por um número de gerações
void evoluirReticulado(AutomatoCelular *automato, int geracoes)
{
    int ordem = automato->ordem;
    for (int g = 0; g < geracoes; g++)
    {
        int *novaMatriz = (int *)malloc(ordem * sizeof(int *));
        for (int i = 0; i < ordem; i++)
        {
            novaMatriz[i] = (int *)malloc(ordem * sizeof(int));
            for (int j = 0; j < ordem; j++)
            {
                int vizinhosVivos = contarVizinhosVivos(automato, i, j);
                if (automato->matriz[i][j] == 1)
                {
                    novaMatriz[i][j] = (vizinhosVivos == 2 || vizinhosVivos == 3) ? 1 : 0;
                }
                else
                {
                    novaMatriz[i][j] = (vizinhosVivos == 3) ? 1 : 0;
                }
            }
        }
        for (int i = 0; i < ordem; i++)
        {
            free(automato->matriz[i]);
        }
        free(automato->matriz);
        automato->matriz = novaMatriz;
    }
}
*/

// Função para calcular a evolução de cada geração
void evolucaoReticulado(AutomatoCelular *automato, int **novaMatriz, int ordem, int i, int j)
{
    if (i == ordem)
    {
        return;
    }
    if (j == ordem)
    {
        evolucaoReticulado(automato, novaMatriz, ordem, i + 1, 0);
        return;
    }
    int vizinhosVivos = contarVizinhosVivos(automato, i, j);
    if (automato->matriz[i][j] == 1)
    {
        novaMatriz[i][j] = (vizinhosVivos == 2 || vizinhosVivos == 3) ? 1 : 0;
    }
    else
    {
        novaMatriz[i][j] = (vizinhosVivos == 3) ? 1 : 0;
    }
    evolucaoReticulado(automato, novaMatriz, ordem, i, j + 1);
}

// Função para fazer a passagem das gerações
void evoluirReticulado(AutomatoCelular *automato, int geracoes)
{
    if (geracoes == 0)
    {
        return;
    }
    int ordem = automato->ordem;
    int **novaMatriz = (int **)malloc(ordem * sizeof(int *)); 
    for (int i = 0; i < ordem; i++)
    {
        novaMatriz[i] = (int *)malloc(ordem * sizeof(int));
    }
    evolucaoReticulado(automato, novaMatriz, ordem, 0, 0);
    for (int i = 0; i < ordem; i++)
    {
        free(automato->matriz[i]);
    }
    free(automato->matriz);
    automato->matriz = novaMatriz;

    evoluirReticulado(automato, geracoes - 1);
}

// Função para imprimir o reticulado
void imprimeReticulado(AutomatoCelular *automato)
{
    for (int i = 0; i < automato->ordem; i++)
    {
        for (int j = 0; j < automato->ordem; j++)
        {
            printf("%d ", automato->matriz[i][j]);
        }
        printf("\n");
    }
}