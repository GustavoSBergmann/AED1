#include <stdio.h>

void sortColors(int *nums, int numsSize)
{
    int i, j, tmp;
    for (i = 1; i < numsSize; i++)
    {
        j = i - 1;
        tmp = nums[i];
        while ((j >= 0) && (tmp < nums[j]))
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = tmp;
    }
}

int main()
{
    int nums[6] = {2, 0, 2, 1, 1, 0};
    int numsSize = 6;

    sortColors(nums, numsSize);

    printf("Array: [");
    for (int i = 0; i < numsSize; i++)
    {
        printf(" %d", nums[i]);
    }
    printf(" ]\n");

    return 0;
}
