#include <stdio.h>
#include <stdlib.h>
#include "automato.h"

int main()
{
    int ordem, geracoes;
    scanf("%d %d", &ordem, &geracoes);

    AutomatoCelular *automato = leituraReticulado(ordem);
    evoluirReticulado(automato, geracoes);
    imprimeReticulado(automato);

    desalocarReticulado(automato);
    return 0;
}