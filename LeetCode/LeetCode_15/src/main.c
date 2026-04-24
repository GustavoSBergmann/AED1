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
        j = i - 1;
        tmp = array[i];

        while ((j >= 0) && (tmp < array[j]))
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = tmp;
    }
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    (*returnSize) = 0;

    if (numsSize < 3)
    {
        *returnColumnSizes = NULL;
        return NULL;
    }

    insertionSort(nums, numsSize);

    int **matrix = (int **)malloc(numsSize * sizeof(int *));
    int i, j, k;
    int rows = 0;

    (**returnColumnSizes) = 3;

    for (i = 0; i < numsSize - 3; i++)
    {
        j = i + 1;
        k = numsSize - 1;

        while (j < k)
        {
            if (nums[i] + nums[j] + nums[k] < 0)
            {
                j++;
            }
            else if (nums[i] + nums[j] + nums[k] > 0)
            {
                k--;
            }
            else
            {
                matrix[rows][0] = nums[i];
                matrix[rows][1] = nums[j];
                matrix[rows][2] = nums[k];

                j++;
                k--;
                rows++;
            }
        }
    }
    (*returnSize) = rows;
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
