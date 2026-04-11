/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numSize, int target, int *returnSize);

int main()
{
    int nums[4] = {2, 7, 11, 15};
    int numsSize = 4;
    int target = 9;
    int *returnSize = (int *)malloc(2 * sizeof(int));
    int *result = NULL;

    result = twoSum(nums, numsSize, target, returnSize);

    if (*returnSize == 2)
    {
        printf("%d + %d = %d\n", nums[*result], nums[*(result + 1)], target);
        printf("Indices: %d, %d", *result, *(result + 1));
    }
    else if (*returnSize == 0)
    {
        printf("Soma não encontrada!\n");
    }
    return 0;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *result = (int *)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}