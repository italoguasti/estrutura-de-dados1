#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct Celula
{
    int linha;
    int coluna;
    struct Celula *proxLinha;
    struct Celula *proxColuna;
} Celula;

typedef struct
{
    int ordem;
    Celula **linhas;
    Celula **colunas;
} MatrizEsparsa;

// Função para alocar uma matriz esparsa
MatrizEsparsa *alocarMatrizEsparsa(int ordem);

// Função para desalocar uma matriz esparsa
void desalocarMatrizEsparsa(MatrizEsparsa *matriz);

// Função para inserir um elemento na matriz esparsa
void inserirCelula(MatrizEsparsa *matriz, int linha, int coluna);

// Função para remover um elemento da matriz esparsa
void removerCelula(MatrizEsparsa *matriz, int linha, int coluna);

// Função para obter o valor de uma célula (0 ou 1)
int obterValorCelula(MatrizEsparsa *matriz, int linha, int coluna);

// Função para imprimir a matriz esparsa como uma matriz densa (com todos os valores)
void imprimirMatrizEsparsa(MatrizEsparsa *matriz);

#endif