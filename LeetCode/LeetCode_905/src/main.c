#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArrayByParity(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;

    int i = 0;
    int j = numsSize - 1;

    while (i < j)
    {
        while (i < j && nums[i] % 2 == 0)
        {
            i++;
        }
        while (i < j && nums[j] % 2 == 1)
        {
            j--;
        }
        if (i < j)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    return nums;
}

int main()
{
    int nums[4] = {3, 1, 2, 4};
    int numsSize = 4;
    int returnSize;

    int *array = sortArrayByParity(nums, numsSize, &returnSize);

    printf("[ ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]");

    free(array);

    return 0;
}
