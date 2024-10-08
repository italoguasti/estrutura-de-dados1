#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Manter como especificado
void inicia(Hash *hash, int m, int p) {
    hash->m = m;
    hash->p = p;
    hash->chaves = (Chave*) malloc(m * sizeof(Chave));
    hash->pesos = (int*) malloc(p * sizeof(int));

    // Inicializando tabela com chaves vazias
    for (int i = 0; i < m; i++) {
        hash->chaves[i][0] = '\0'; // Indica posição vazia
    }
}

// Manter como especificado
void libera(Hash *hash) {
    free(hash->chaves);
    free(hash->pesos);
}

// Função para converter a chave para lowercase e ignorar caracteres não alfabéticos
void normaliza_chave(Chave chave_normalizada, const Chave chave) {
    int idx = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        if (isalpha(chave[i])) {
            chave_normalizada[idx++] = tolower(chave[i]);
        }
    }
    chave_normalizada[idx] = '\0'; // Finaliza a string
}

int H(Hash* hash, Chave chave) {
    Chave chave_normalizada;
    normaliza_chave(chave_normalizada, chave);

    int soma = 0;
    int len = strlen(chave_normalizada);

    for (int i = 0; i < len; i++) {
        soma += chave_normalizada[i] * hash->pesos[i % hash->p];
    }

    return soma % hash->m;
}

// Manter como especificado
int insere(Hash *hash, Chave chave) {
    int pos = H(hash, chave);

    for (int i = 0; i < hash->m; i++) {
        int idx = (pos + i) % hash->m;

        if (hash->chaves[idx][0] == '\0') {
            // Encontrou uma posição vazia, inserir a chave
            strcpy(hash->chaves[idx], chave);
            return idx;
        } else if (strcmp(hash->chaves[idx], chave) == 0) {
            // A chave já existe
            return -1;
        }
    }
    // Tabela cheia
    return -1;
}
