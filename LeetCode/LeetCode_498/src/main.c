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

    while (k < m * n)
    {
        while (i >= 0 && j < n)
        {
            order[k++] = mat[i][j];
            i--;
            j++;
        }

        if (j == n)
        {
            i += 2;
            j = n - 1;
        }
        else
        {
            i = 0;
        }

        if (k >= m * n)
            break;

        while (i < m && j >= 0)
        {
            order[k++] = mat[i][j];
            i++;
            j--;
        }

        if (i == m)
        {
            j += 2;
            i = m - 1;
        }
        else
        {
            j = 0;
        }
    }

    *returnSize = m * n;
    return order;
}

int main()
{
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matSize = 9;
    int matColSize;
    int returnSize;
    int *order = NULL;

    order = findDiagonalOrder(mat, matSize, &matColSize, &returnSize);

    printf("Array: [");
    for (int i = 0; i < matSize; i++)
    {
        printf(" %d", order[i]);
    }
    printf(" ]\n");

    return 0;
}
