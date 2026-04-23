#include <stdio.h>

int removeElement(int *nums, int numsSize, int val)
{
    int k = 0;
    for (int read = 0; read < numsSize; read++)
    {
        if (nums[read] != val)
        {
            nums[k] = nums[read];
            k++;
        }
    }
    return k;
}

int main()
{
    int nums[8] = {0, 1, 2, 2, 3, 0, 4, 2};
    int numsSize = 8;
    int val = 2;
    int k;

    k = removeElement(nums, numsSize, val);

    for (int i = 0; i < k; i++)
    {
        printf("Valor: %d\n", nums[i]);
    }

    return 0;
}
