#include <stdio.h>

void insertionSort(int *array, int size)
{
    int i, j, temp;

    for (i = 1; i < size; i++)
    {
        j = i - 1;
        temp = array[i];

        while ((j >= 0) && (temp < array[j]))
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

int arrayPairSum(int *nums, int numsSize)
{
    insertionSort(nums, numsSize);
    int soma = 0;

    for (int i = 0; i < numsSize; i += 2)
    {
        soma += nums[i];
    }

    return soma;
}

int main()
{
    int nums[6] = {6, 2, 6, 5, 1, 2};
    int numsSize = 6;

    printf("Soma maxima: %d\n", arrayPairSum(nums, numsSize));

    return 0;
}
