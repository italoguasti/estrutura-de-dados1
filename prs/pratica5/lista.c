#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

// Inicia as variáveis da lista
void ListaInicia(Lista *pLista)
{
    pLista->pPrimeiro = (Celula *)malloc(sizeof(Celula));
    pLista->pPrimeiro->pProx = NULL;
    pLista->pUltimo = pLista->pPrimeiro;
}

// Retorna se a lista está vazia
bool ListaEhVazia(Lista *pLista)
{
    return (pLista->pPrimeiro->pProx == NULL);
}

// Insere um item no final da lista
bool ListaInsereFinal(Lista *pLista, Item x)
{
    pLista->pUltimo->pProx = (Celula *)malloc(sizeof(Celula));
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->item = x;
    pLista->pUltimo->pProx = NULL;
    return true;
}

// Retira o primeiro item da lista
bool ListaRetiraPrimeiro(Lista *pLista, Item *pX)
{
    if (ListaEhVazia(pLista))
        return false;

    Celula *pAux;
    pAux = pLista->pPrimeiro;
    pLista->pPrimeiro = pLista->pPrimeiro->pProx;
    *pX = pLista->pPrimeiro->item;
    free(pAux);
    return true;
}

// Imprime os elementos da lista
void ListaImprime(Lista *pLista)
{
    Celula *pAux;
    pAux = pLista->pPrimeiro->pProx;
    while (pAux != NULL)
    {
        printf("%c", pAux->item.letra);
        pAux = pAux->pProx;
    }
}

// Remove cada elemento de uma lista e libera a memória
void ListaEsvazia(Lista *pLista)
{
    Item temp;
    while (!ListaEhVazia(pLista))
    {
        ListaRetiraPrimeiro(pLista, &temp);
    }
    free(pLista->pPrimeiro);
}

// Acrescenta o conteúdo de uma lista no início de outra, apenas manipulando ponteiros
void ListaInclude(Lista *pLista1, Lista *pLista2)
{
    if (ListaEhVazia(pLista2))
        return;

    Celula *pAux;
    pAux = pLista2->pPrimeiro->pProx;
    while (pAux != NULL)
    {
        ListaInsereFinal(pLista1, pAux->item);
        pAux = pAux->pProx;
    }
    ListaEsvazia(pLista2);
}

// Analisa a lista original e coloca os caracteres na lista resultado ou auxiliar
void resolve(Lista *original, Lista *resultado, Lista *auxiliar)
{
    int flag = 0;
    Celula *pAux;
    Item temp;

    // Percorre a lista original, caractere por caractere
    pAux = original->pPrimeiro->pProx;
    while (pAux != NULL)
    {
        // Se o caractere for ']' então incluir os caracteres da lista auxiliar na lista resultado
        if (pAux->item.letra == ']' || pAux->item.letra == '[')
        {
            if (flag == 1)
            {
                // A flag deve indicar que "End" foi pressionado
                flag = 0;
                // Se a lista auxiliar nao estiver vazia
                if (!ListaEhVazia(auxiliar))
                {
                    // incluir o conteudo da lista auxiliar na lista de resultado
                    ListaInclude(resultado, auxiliar);
                    // iniciar os ponteiros da lista auxiliar novamente
                    ListaInicia(auxiliar);
                }
            }
        }

        // Se ler o caractere '[', a flag deve indicar que "Home" foi pressionado
        if (pAux->item.letra == '[')
        {
            flag = 1;
        }

        // Se ler um caractere sem "Home" ter sido pressionado, inserir direto no final da lista de resultado
        if (pAux->item.letra != '[' && pAux->item.letra != ']' && flag == 0)
        {
            temp.letra = pAux->item.letra;
            ListaInsereFinal(resultado, temp);
        }
        // se ler um caractere com "Home" tendo sido pressionado, inserir na lista auxiliar
        else if (pAux->item.letra != '[' && pAux->item.letra != ']' && flag == 1)
        {
            temp.letra = pAux->item.letra;
            ListaInsereFinal(auxiliar, temp);
        }
        // vai para a proxima celula
        pAux = pAux->pProx;
    }

    // processa os ultimos caracteres mesmo que nao haja "Home" ou "End" no final da entrada
    if (flag == 1)
    {
        // se a lista auxiliar nao estiver vazia
        if (!ListaEhVazia(auxiliar))
        {
            // incluir o conteudo da lista auxiliar na lista de resultado
            ListaInclude(resultado, auxiliar);
        }
    }
}
