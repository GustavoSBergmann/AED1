#include <stdio.h>

void selectionSort(int *nums, int numsSize)
{
    int i, j;

    for (i = 0; i < numsSize - 1; i++)
    {
        int minimo = i;
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[minimo] > nums[j])
            {
                minimo = j;
            }
        }

        if (minimo != i)
        {
            int temp = nums[minimo];
            nums[minimo] = nums[i];
            nums[i] = temp;
        }
    }
}

void printArray(int *nums, int numsSize)
{
    printf("Vetor: [");
    for (int i = 0; i < numsSize; i++)
    {
        printf(" %d", nums[i]);
    }
    printf(" ]\n");
}

int main()
{
    int nums[8] = {5, 15, 20, 17, 18, 30, 3, 29};
    int numsSize = 8;

    printArray(nums, numsSize);

    selectionSort(nums, numsSize);

    printArray(nums, numsSize);

    return 0;
}