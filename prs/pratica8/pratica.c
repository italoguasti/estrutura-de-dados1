#include "ordenacao.h"
#include <stdio.h>

int main ()
{
	int n, k;
	Aluno* alunos;

	leQuantidades(&n, &k);

    	alunos = alocaAlunos(n);
    	leAlunos(alunos, n);

    	ordena(alunos, n);
    	imprimeResposta(alunos, k, n);

    	liberaAlunos(&alunos);

  	return 0;
}
