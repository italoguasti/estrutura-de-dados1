#include <stdio.h>
#include <stdlib.h>
#include "automato.h"

int main()
{
    int ordem, geracoes;

    // Lê a ordem do reticulado e o número de gerações a partir da entrada padrão
    scanf("%d %d", &ordem, &geracoes);

    // Inicializa o autômato celular
    AutomatoCelular *automato = leituraReticulado(ordem);

    // Evolui o autômato celular pelo número especificado de gerações
    evoluirReticulado(automato, geracoes);

    // Imprime o estado final do reticulado
    imprimeReticulado(automato);

    // Desaloca a memória do autômato celular
    desalocarReticulado(automato);

    return 0;
}