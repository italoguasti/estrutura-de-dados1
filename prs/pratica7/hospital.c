#include "hospital.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void troca(Paciente *p1, Paciente *p2)
{
    // Realizar a troca das informacoes entre os pacientes
    Paciente aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

bool ehMaisNovo(const Data *d1, const Data *d2)
{
    // Se o primeiro for mais novo, retorne "true"
    // Se o segundo for mais novo, retorne "false"
    // Se os dois tiverem a mesma idade, retorne "false"
    if (d1->ano > d2->ano)
    {
        return true;
    }
    else if (d1->ano < d2->ano)
    {
        return false;
    }
    else
    {
        // Aqui os anos são iguais
        if (d1->mes > d2->mes)
        {
            return true;
        }
        else if (d1->mes < d2->mes)
        {
            return false;
        }
        else
        {
            // Aqui os meses são iguais
            if (d1->dia > d2->dia)
            {
                return true;
            }
            else if (d1->dia < d2->dia)
            {
                return false;
            }
        }
    }

    return false;
}

void lePacientes(Paciente *pacientes, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%s%d%d%d", pacientes[i].nome, &pacientes[i].nascimento.dia,
              &pacientes[i].nascimento.mes, &pacientes[i].nascimento.ano);
}

void bubblesort(Hospital *hospital, int *comp, int *mov)
{
    int trocas = 0;
    *comp = 0;
    *mov = 0;
    for (int i = 0; i < hospital->n; i++)
    {
        for (int j = 1; j < hospital->n - i; j++)
        {
            (*comp)++; // Incrementa o contador de comparações
            if (ehMaisNovo(&(hospital->pacientes[j - 1].nascimento), &(hospital->pacientes[j].nascimento)))
            {
                troca(&(hospital->pacientes[j - 1]), &(hospital->pacientes[j]));
                (*mov)++; // Incrementa o contador de movimentações apenas na troca
                trocas++;
            }
        }
        if (trocas == 0)
        {
            break; // Sai do loop se nenhuma troca foi feita, o que significa que a lista está ordenada
        }
    }
}

void selectionsort(Hospital *hospital, int *comp, int *mov)
{
    *comp = 0;
    *mov = 0;
    int menor;
    for (int i = 0; i < hospital->n; i++)
    {
        menor = i;
        for (int j = i + 1; j < hospital->n; j++)
        {
            (*comp)++;
            if (ehMaisNovo(&hospital->pacientes[menor].nascimento, &hospital->pacientes[j].nascimento))
                menor = j;
        }
        if (menor != i)
        {
            (*mov)++;
            troca(&hospital->pacientes[menor], &hospital->pacientes[i]);
        }
    }
}

void insertionsort(Hospital *hospital, int *comp, int *mov)
{
    *comp = 0;
    *mov = 0;
    int j;
    Paciente aux;
    for (int i = 1; i < hospital->n; i++)
    {
        aux = hospital->pacientes[i];
        j = i - 1;
        while (j >= 0)
        {
            (*comp)++;
            if (ehMaisNovo(&aux.nascimento, &hospital->pacientes[j].nascimento) == false)
            {
                hospital->pacientes[j + 1] = hospital->pacientes[j];
                j--;
                (*mov)++;
            }
            else
            {
                break;
            }
        }
        if (j < 0)
        {
            (*comp)++;
        }
        troca(&hospital->pacientes[j + 1], &aux);
        (*mov)++;
    }
}