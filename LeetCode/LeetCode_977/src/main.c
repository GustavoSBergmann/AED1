#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
    int *result = (int *)malloc(numsSize * sizeof(int));
    int i = 0, j = numsSize - 1;
    int write = numsSize - 1;

    while (i <= j)
    {
        if (abs(nums[i]) < abs(nums[j]))
        {
            result[write] = nums[j] * nums[j];
            j--;
            write--;
        }
        else
        {
            result[write] = nums[i] * nums[i];
            i++;
            write--;
        }
    }

    (*returnSize) = numsSize;
    return result;
}

int main()
{
    int nums[5] = {-4, -1, 0, 3, 10};
    int numsSize = 5;
    int returnSize = 0;
    int *result = NULL;

    result = sortedSquares(nums, numsSize, &returnSize);

    printf("###############################\n");
    printf("Squares Array: [");
    for (int i = 0; i < returnSize; i++)
    {
        printf(" %d", result[i]);
    }
    printf(" ]\n");
    printf("###############################\n");

    free(result);

    return 0;
}
