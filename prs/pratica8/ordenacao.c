#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
void ordena(Aluno *alunos, int n)
{
	int gap, i, j;
	Aluno temp;

	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			temp = alunos[i];
			for (j = i; j >= gap && compare(alunos[j - gap].nome, temp.nome) > 0; j -= gap)
			{
				alunos[j] = alunos[j - gap];
			}
			alunos[j] = temp;
		}
	}
}

// Manter como especificado
int compare(const char *aluno1, const char *aluno2)
{
	return strcmp(aluno1, aluno2);
}

/* Manter como especificado */
void imprimeResposta(Aluno *alunos, int n, int k)
{
	printf("\n%s\n", alunos[k - 1].nome);
}

/* Manter como especificado */
Aluno *alocaAlunos(int n)
{
	return (Aluno *)malloc(n * sizeof(Aluno));
}

/* Manter como especificado */
void liberaAlunos(Aluno **alunos)
{
	if (*alunos != NULL)
	{
		free(*alunos);
		*alunos = NULL;
	}
}

/* Manter como especificado */
void leAlunos(Aluno *alunos, int n)
{
	for (int i = 0; i < n; i++)
	{
		scanf("%s", alunos[i].nome);
	}
}

/* Manter como especificado */
void leQuantidades(int *n, int *k)
{
	scanf("%d %d", n, k);
}