#include "ordenacao.h"

#include <stdio.h>

/* Manter como especificado */ 
void coutingSort(Paciente* A, Paciente* B, int n, int fator);

/* Manter como especificado */ 
void radixSort(Paciente* pacientes, int n);

/* Manter como especificado */ 
int pegadigito(int senha, int fator);

// Manter como especificado
void le(Paciente* pacientes, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &pacientes[i].senha, pacientes[i].nome);
    }
}

// Manter como especificado
void imprime(Paciente* pacientes, int n){
    for (int i = 0; i < n; i++) {
        printf("%07d %s\n", pacientes[i].senha, pacientes[i].nome);
    }    
}

// Manter como especificado
void ordenar(Paciente* pacientes, int n){
    radixSort(pacientes, n);    
}

/** 
 * Manter como especificado
 * Método de ordenacao CoutingSort
 * Args:
 *   A = vetor a ser ordenado
 *   B = vetor auxiliar para armazenar o vetor A ordenado
 *   n = tamanho do vetor A
 *   fator = fator usado para pegar o digito
 **/ 
void coutingSort(Paciente* A, Paciente* B, int n, int fator) {
    int C[10] = {0}; // Para contar os dígitos de 0 a 9

    // Contando as ocorrências dos dígitos
    for (int i = 0; i < n; i++) {
        int digito = pegadigito(A[i].senha, fator);
        C[digito]++;
    }

    // Calculando as posições dos elementos
    for (int i = 1; i < 10; i++) {
        C[i] += C[i - 1];
    }

    // Ordenando com base no dígito atual
    for (int i = n - 1; i >= 0; i--) {
        int digito = pegadigito(A[i].senha, fator);
        B[C[digito] - 1] = A[i];
        C[digito]--;
    }

    // Copiando o resultado de volta para A
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

/** 
 * Manter como especificado
 * Método de ordenacao CoutingSort
 * Args:
 *   pacientes = vetor a ser ordenado
 *   n = tamanho do vetor A
 *   m = quantidade de digitos
 **/ 
void radixSort(Paciente* pacientes, int n) {
    // Vetor auxiliar a ser usado no couting sort
    Paciente B[MAX_N];

    for (int fator = 1; fator <= 1000000; fator *= 10) {
        coutingSort(pacientes, B, n, fator);
    }

}

/**
 * Manter como especificado
 * Funcao que pega o digito esperado de um numero
 */
int pegadigito(int senha, int fator) {
    return (senha / fator) % 10;
}
