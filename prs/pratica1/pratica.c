// Italo Gustavo Guasti - 22.2.4111

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void read_matrix(int matrix[MAX_SIZE][MAX_SIZE], int M, int N)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void apply_corrections(int matrix[MAX_SIZE][MAX_SIZE], int M, int N, int X, int Y)
{
    int temp[MAX_SIZE][MAX_SIZE];

    // Adjust Y to be within the matrix bounds
    int y_offset = (Y % M + M) % M;
    // Adjust X to be within the matrix bounds
    int x_offset = (-X % N + N) % N;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int new_i = (i - y_offset + M) % M;
            int new_j = (j - x_offset + N) % N;
            temp[new_i][new_j] = matrix[i][j];
        }
    }

    // Copy the temp matrix back to the original matrix
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = temp[i][j];
        }
    }
}

int main()
{
    int M, N;
    int test_case = 1;

    while (scanf("%d %d", &M, &N) && (M != 0 || N != 0))
    {
        int matrix[MAX_SIZE][MAX_SIZE];

        read_matrix(matrix, M, N);

        int X, Y;
        while (scanf("%d %d", &X, &Y) && (X != 0 || Y != 0))
        {
            apply_corrections(matrix, M, N, X, Y);
        }

        printf("Teste %d\n", test_case++);
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}