#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void insertionSort(int *array, int arraySize)
{
    int i, j, tmp;

    for (i = 1; i < arraySize; i++)
    {
        tmp = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > tmp)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = tmp;
    }
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    *returnColumnSizes = NULL;

    if (numsSize < 3)
        return NULL;

    insertionSort(nums, numsSize);

    int **matrix = NULL;
    int rows = 0;

    for (int i = 0; i < numsSize - 2; i++)
    {
        // Evita repetir o mesmo primeiro elemento
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int j = i + 1;
        int k = numsSize - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                matrix = realloc(matrix, (rows + 1) * sizeof(int *));
                matrix[rows] = malloc(3 * sizeof(int));

                *returnColumnSizes = realloc(*returnColumnSizes,
                                             (rows + 1) * sizeof(int));

                (*returnColumnSizes)[rows] = 3;

                matrix[rows][0] = nums[i];
                matrix[rows][1] = nums[j];
                matrix[rows][2] = nums[k];

                rows++;

                j++;
                k--;

                // Ignora valores repetidos de j
                while (j < k && nums[j] == nums[j - 1])
                    j++;

                // Ignora valores repetidos de k
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }

    *returnSize = rows;
    return matrix;
}

int main()
{
    int nums[6] = {-1, 0, 1, 2, -1, -4};
    int numsSize = 6;
    int returnSize;
    int *returnColumnSizes;
    int **matrix = NULL;

    matrix = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

    return 0;
}
