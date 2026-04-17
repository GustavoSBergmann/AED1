#include <stdio.h>

void moveZeroes(int *nums, int numsSize)
{
    int write = 0;
    for (int read = 0; read < numsSize; read++)
    {
        if (nums[read] != 0)
        {
            nums[write] = nums[read];
            write++;
        }
    }
    while (write < numsSize)
    {
        nums[write] = 0;
        write++;
    }
}

int main()
{
    int nums[5] = {0, 1, 0, 3, 12};
    int numsSize = 5;

    moveZeroes(nums, numsSize);

    for (int i = 0; i < numsSize; i++)
    {
        printf("Valor %d: %d \n", i, nums[i]);
    }

    return 0;
}
