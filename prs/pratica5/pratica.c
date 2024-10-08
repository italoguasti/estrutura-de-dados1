#include "lista.h"
#include <stdio.h>

int main()
{
  Lista original, resultado, auxiliar;
  char letra;
  Item temp;

  // Inicialize as três listas
  ListaInicia(&original);
  ListaInicia(&resultado);
  ListaInicia(&auxiliar);

  // Le a linha da entrada
  while (scanf("%c", &letra) != EOF && letra != '\n')
  {
    temp.letra = letra;
    // Insira o elemento temp na lista original
    ListaInsereFinal(&original, temp);
  }

  // Analisa a lista original e coloca os caracteres na lista resultado ou auxiliar
  resolve(&original, &resultado, &auxiliar);

  // Imprime o resultado, caso a lista não esteja vazia
  if (!ListaEhVazia(&resultado))
  {
    ListaImprime(&resultado);
    printf("\n");
  }
  else
  {
    printf("\n");
  }

  // Ao final, desalocar as listas
  ListaEsvazia(&original);
  ListaEsvazia(&resultado);
  ListaEsvazia(&auxiliar);

  return 0; // não remova
}
