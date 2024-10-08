#include <stdio.h>
#include "hash.h"

int main()
{
    Hash hash;
    int n;

    // Ler a quantidade de casos
    scanf("%d", &n);

    while (n-- > 0)
    {
        int m, p, s;

        // Lendo tamanho da tabela e quantidade de pesos
        scanf("%d %d", &m, &p);

        // Iniciar Hash
        inicia(&hash, m, p);

        // Lendo pesos
        for (int i = 0; i < p; i++)
        {
            scanf("%d", &hash.pesos[i]);
        }

        // Lendo quantidade de chaves
        scanf("%d", &s);
        Chave chave;
        int ultima_posicao = -1;

        for (int i = 0; i < s; i++)
        {
            // Lendo chave e inserindo na tabela
            scanf("%s", chave);
            ultima_posicao = insere(&hash, chave);
        }

        // Imprimir a última posição ou -1 se for repetida
        printf("%d\n", ultima_posicao);

        // Liberar Hash
        libera(&hash);
    }

    return 0;
}