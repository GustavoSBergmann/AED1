#include <stdio.h>

int removeDuplicates(int *nums, int numsSize)
{
    int write = 0, k;
    for (int read = 1; read < numsSize; read++)
    {
        if (nums[read] != nums[write])
        {
            write++;
            nums[write] = nums[read];
        }
    }
    write++;
    k = write;
    while (write < numsSize)
    {
        nums[write] = 101;
        write++;
    }

    return k;
}

int main()
{
    int nums[10] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int numsSize = 10;
    int repeat;

    repeat = removeDuplicates(nums, numsSize);

    printf("#############################\n");
    printf("Numeros repetidos: %d\n", repeat);
    printf("Array: [ ");
    for (int i = 0; i < repeat; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("]\n");
    printf("#############################\n");

    return 0;
}
