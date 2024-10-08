#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duende.h"

void lerQuantidade(int *qtdDuendes){
    scanf("%d", qtdDuendes);
}

Duende *alocaDuendes(int qtdDuendes){
    return (Duende*) malloc(qtdDuendes * sizeof(Duende));
}

Time *alocaTimes(int qtdTimes){
    return (Time*) malloc(qtdTimes * sizeof(Time));
}

void desalocaDuendes(Duende **duendes){
    free(*duendes);
    *duendes = NULL;
}

void desalocaTimes(Time **times){
    free(*times);
    *times = NULL;
}

void lerDuendes(Duende *duendes, int qtdDuendes){
    for (int i = 0; i < qtdDuendes; i++) {
        scanf("%s %d", duendes[i].nome, &duendes[i].idade);
        duendes[i].escalado = NAO;
    }
}

int proximoMaisVelho(Duende *duendes, int qtdDuendes) {
    int indexMaisVelho = -1;
    for (int i = 0; i < qtdDuendes; i++) {
        if (duendes[i].escalado == NAO && 
           (indexMaisVelho == -1 || duendes[i].idade > duendes[indexMaisVelho].idade)) {
            indexMaisVelho = i;
        }
    }
    return indexMaisVelho;
}

void escalarTimes(Duende *duendes, Time *times, int qtdDuendes) {
    int qtdTimes = qtdDuendes / 4;
    
    // Escalando os líderes
    for (int i = 0; i < qtdTimes; i++) {
        int index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].nomeLider, duendes[index].nome);
        times[i].idadeLider = duendes[index].idade;
    }

    // Escalando os confeiteiros
    for (int i = 0; i < qtdTimes; i++) {
        int index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].nomeConfeiteiro, duendes[index].nome);
        times[i].idadeConfeiteiro = duendes[index].idade;
    }

    // Escalando os entregadores
    for (int i = 0; i < qtdTimes; i++) {
        int index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].nomeEntregador, duendes[index].nome);
        times[i].idadeEntregador = duendes[index].idade;
    }

    // Escalando os embrulhadores
    for (int i = 0; i < qtdTimes; i++) {
        int index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].nomeEmbrulhador, duendes[index].nome);
        times[i].idadeEmbrulhador = duendes[index].idade;
    }
}

void printTimes(Time *times, int qtdTimes) {
    for (int i = 0; i < qtdTimes; i++) {
        printf("TIME %d\n", i + 1);
        printf("PILOTO > %s %d\n", times[i].nomeLider, times[i].idadeLider);
        printf("CONFEI > %s %d\n", times[i].nomeConfeiteiro, times[i].idadeConfeiteiro);
        printf("ENTREG > %s %d\n", times[i].nomeEntregador, times[i].idadeEntregador);
        printf("EMBRUL > %s %d\n\n", times[i].nomeEmbrulhador, times[i].idadeEmbrulhador);
    }
}
