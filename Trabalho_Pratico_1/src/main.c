#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *findDiagonalOrder(int **mat, int matSize, int *matColSize, int *returnSize)
{
    int m = matSize;
    int n = *matColSize;

    int *order = (int *)malloc(m * n * sizeof(int));

    int i = 0, j = 0, k = 0;

    // Percorre o vetor order preenchendo-o
    while (k < m * n)
    {
        // Sobe diagonalmente
        while (i >= 0 && j < n)
        {
            order[k++] = mat[i][j];
            i--;
            j++;
        }

        // Se j passou do limite a direita e i do limite superior
        if (j == n)
        {
            i += 2;
            j = n - 1;
        }
        // Se apenas i passou do limite superior
        else
        {
            i = 0;
        }

        // Se já passou do limite do vetor, então para de percorrer
        if (k >= m * n)
        {
            break;
        }

        // Desce diagonalmente
        while (i < m && j >= 0)
        {
            order[k++] = mat[i][j];
            i++;
            j--;
        }

        // Se i passou do limite inferior e j do limite a esquerda
        if (i == m)
        {
            j += 2;
            i = m - 1;
        }
        // Se apenas j passou do limite a esquerda
        else
        {
            j = 0;
        }
    }

    // Retorna o vetor e o seu tamanho
    *returnSize = m * n;
    return order;
}

int main()
{
    int row0[3] = {1, 2, 3};
    int row1[3] = {4, 5, 6};
    int row2[3] = {7, 8, 9};

    int *mat[] = {row0, row1, row2};
    int matSize = 3;
    int matColSize = 3;
    int returnSize;
    int *order = NULL;

    order = findDiagonalOrder(mat, matSize, &matColSize, &returnSize);

    printf("Array: [");
    for (int i = 0; i < returnSize; i++)
    {
        printf(" %d", order[i]);
    }
    printf(" ]\n");

    free(order);

    return 0;
}
