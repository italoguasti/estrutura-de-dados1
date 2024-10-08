#include "ordenacao.h"

#include <stdio.h>

int main() {
    int n;
    Paciente pacientes[MAX_N];

    // Ler os valores de n e m
    scanf("%d", &n);
    
    // Ler os dados dos jogadores
    le(pacientes, n);
    
    // Ordenar o vetor com o radixSort
    ordenar(pacientes, n);
    
    // Imprimir a resposta
    imprime(pacientes, n);
    
    return 0;
}