#include <stdio.h>
#include <stdlib.h>
#include "automato.h"

// Função para alocar o reticulado
AutomatoCelular *alocarReticulado(int ordem)
{
    AutomatoCelular *automato = (AutomatoCelular *)malloc(sizeof(AutomatoCelular));
    if (automato == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para AutomatoCelular.\n");
        exit(1);
    }

    automato->matriz = alocarMatrizEsparsa(ordem);
    return automato;
}

// Função para desalocar o reticulado
void desalocarReticulado(AutomatoCelular *automato)
{
    desalocarMatrizEsparsa(automato->matriz);
    free(automato);
}

// Função para leitura do reticulado a partir do terminal
AutomatoCelular *leituraReticulado(int ordem)
{
    AutomatoCelular *automato = alocarReticulado(ordem);
    int valor;
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            scanf("%d", &valor);
            if (valor == 1)
            {
                inserirCelula(automato->matriz, i, j);
            }
        }
    }
    return automato;
}

// Função para contar vizinhos vivos
int contarVizinhosVivos(AutomatoCelular *automato, int linha, int coluna)
{
    int vizinhosVivos = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int novaLinha = linha + i;
            int novaColuna = coluna + j;
            if (novaLinha >= 0 && novaLinha < automato->matriz->ordem &&
                novaColuna >= 0 && novaColuna < automato->matriz->ordem)
            {
                vizinhosVivos += obterValorCelula(automato->matriz, novaLinha, novaColuna);
            }
        }
    }
    return vizinhosVivos;
}

// Função para evoluir o reticulado por um número de gerações
void evoluirReticulado(AutomatoCelular *automato, int geracoes)
{
    for (int g = 0; g < geracoes; g++)
    {
        MatrizEsparsa *novaMatriz = alocarMatrizEsparsa(automato->matriz->ordem);
        for (int i = 0; i < automato->matriz->ordem; i++)
        {
            for (int j = 0; j < automato->matriz->ordem; j++)
            {
                int vizinhosVivos = contarVizinhosVivos(automato, i, j);
                int valorCelula = obterValorCelula(automato->matriz, i, j);

                if (valorCelula == 1 && (vizinhosVivos == 2 || vizinhosVivos == 3))
                {
                    inserirCelula(novaMatriz, i, j); // Célula viva permanece viva
                }
                else if (valorCelula == 0 && vizinhosVivos == 3)
                {
                    inserirCelula(novaMatriz, i, j); // Célula morta se torna viva
                }
            }
        }
        desalocarMatrizEsparsa(automato->matriz); // Libera a matriz anterior
        automato->matriz = novaMatriz;            // Substitui pela nova matriz
    }
}

// Função para imprimir o reticulado
void imprimeReticulado(AutomatoCelular *automato)
{
    imprimirMatrizEsparsa(automato->matriz);
}