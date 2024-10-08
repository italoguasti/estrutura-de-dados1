#ifndef AUTOMATO_H
#define AUTOMATO_H

#include "matriz.h"

typedef struct
{
    MatrizEsparsa *matriz;
} AutomatoCelular;

// Função para alocar o reticulado
AutomatoCelular *alocarReticulado(int ordem);

// Função para desalocar o reticulado
void desalocarReticulado(AutomatoCelular *automato);

// Função para leitura do reticulado a partir do terminal
AutomatoCelular *leituraReticulado(int ordem);

// Função para evoluir o reticulado por um número de gerações
void evoluirReticulado(AutomatoCelular *automato, int geracoes);

// Função para imprimir o reticulado
void imprimeReticulado(AutomatoCelular *automato);

#endif