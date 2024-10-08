#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Declarações prévias das funções
void refaz(Heap *heap);
void heapInsere(Heap *heap, Chamada chamada, int index);
bool temMaisPrioridade(Chamada *c1, Chamada *c2);

// Mantenha como especificado
Chamada criarChamada(char *nome, int prioridade, int dia, int mes, int ano)
{
    Chamada chamada;
    strcpy(chamada.nome, nome);
    chamada.prioridade = prioridade;
    chamada.nascimento.dia = dia;
    chamada.nascimento.mes = mes;
    chamada.nascimento.ano = ano;
    return chamada;
}

// Mantenha como especificado
void imprimeChamada(Chamada chamada)
{
    printf("%02d | %02d/%02d/%04d | %s\n", chamada.prioridade, chamada.nascimento.dia,
           chamada.nascimento.mes, chamada.nascimento.ano, chamada.nome);
}

// Mantenha como especificado
Heap *criarHeap()
{
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->tam = 0;
    return heap;
}

// Mantenha como especificado
Heap *destroiHeap(Heap *heap)
{
    free(heap);
    return NULL;
}

// Mantenha como especificado
void inserirChamada(Heap *heap, Chamada chamada)
{
    if (heap->tam < 100)
    {
        heapInsere(heap, chamada, heap->tam);
        heap->tam++;
    }
}

// Mantenha como especificado
Chamada atenderChamada(Heap *heap)
{
    if (heap->tam == 0)
    {
        printf("Nenhuma chamada para atender.\n");
        exit(1);
    }

    Chamada chamada = heap->chamadas[0];
    heap->chamadas[0] = heap->chamadas[heap->tam - 1];
    heap->tam--;
    refaz(heap);
    return chamada;
}

// Mantenha como especificado
bool consultarSeTemProximaChamada(Heap *heap)
{
    return heap->tam > 0;
}

// Função que reordena o heap de cima para baixo
void refaz(Heap *heap)
{
    int i = 0;
    int filhoEsq, filhoDir, maior;

    while (2 * i + 1 < heap->tam)
    {
        filhoEsq = 2 * i + 1;
        filhoDir = 2 * i + 2;
        maior = i;

        if (filhoEsq < heap->tam && temMaisPrioridade(&heap->chamadas[filhoEsq], &heap->chamadas[maior]))
        {
            maior = filhoEsq;
        }

        if (filhoDir < heap->tam && temMaisPrioridade(&heap->chamadas[filhoDir], &heap->chamadas[maior]))
        {
            maior = filhoDir;
        }

        if (maior == i)
        {
            break;
        }

        Chamada temp = heap->chamadas[i];
        heap->chamadas[i] = heap->chamadas[maior];
        heap->chamadas[maior] = temp;
        i = maior;
    }
}

// Função que insere a chamada no heap e refaz a estrutura de baixo para cima
void heapInsere(Heap *heap, Chamada chamada, int index)
{
    heap->chamadas[index] = chamada;

    int i = index;
    while (i > 0 && temMaisPrioridade(&heap->chamadas[i], &heap->chamadas[(i - 1) / 2]))
    {
        Chamada temp = heap->chamadas[i];
        heap->chamadas[i] = heap->chamadas[(i - 1) / 2];
        heap->chamadas[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Verifica se uma chamada tem maior prioridade que outra
bool temMaisPrioridade(Chamada *c1, Chamada *c2)
{
    // Verifica a prioridade
    if (c1->prioridade > c2->prioridade)
    {
        return true;
    }
    else if (c1->prioridade == c2->prioridade)
    {
        // Desempata pela data de nascimento
        if (c1->nascimento.ano < c2->nascimento.ano)
            return true;
        if (c1->nascimento.ano == c2->nascimento.ano && c1->nascimento.mes < c2->nascimento.mes)
            return true;
        if (c1->nascimento.ano == c2->nascimento.ano && c1->nascimento.mes == c2->nascimento.mes && c1->nascimento.dia < c2->nascimento.dia)
            return true;
    }
    return false;
}
