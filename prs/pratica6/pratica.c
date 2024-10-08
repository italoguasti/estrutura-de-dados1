#include "pilha.h"
#include <stdio.h>

int main()
{
    char ch;
    Item item;
    Pilha pilha;

    PilhaInicia(&pilha);

    int correto = 1;

    while (scanf("%c", &ch) != EOF)
    {
        if (ch == '\n')
            break;
        else if (ch == '(')
        {
            PilhaPush(&pilha, ch);
        }
        else if (ch == ')')
        {
            if (PilhaEhVazia(&pilha))
            {
                correto = 0;
                break;
            }
            else
            {
                PilhaPop(&pilha, &item);
            }
        }
    }

    if (!PilhaEhVazia(&pilha))
    {
        correto = 0;
    }

    if (correto)
    {
        printf("correto\n");
    }
    else
    {
        printf("incorreto\n");
    }

    PilhaEsvazia(&pilha);

    return 0;
}
