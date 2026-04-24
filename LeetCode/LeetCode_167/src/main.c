#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    int i = 0, j = numbersSize - 1;
    int *result = (int *)malloc(2 * sizeof(int));

    while (i <= j)
    {
        if (numbers[i] + numbers[j] < target)
        {
            i++;
        }
        else if (numbers[i] + numbers[j] > target)
        {
            j--;
        }
        else
        {
            result[0] = i + 1;
            result[1] = j + 1;
            (*returnSize) = 2;
            return result;
        }
    }
    return NULL;
}

int main()
{
    int numbers[4] = {2, 7, 11, 15};
    int numbersSize = 4;
    int target = 9;
    int returnSize = 0;
    int *result = NULL;

    result = twoSum(numbers, numbersSize, target, &returnSize);

    printf("###############################\n");
    if (returnSize == 2)
    {
        printf("Indices: [ %d, %d ]\n", result[0], result[1]);
    }
    else
    {
        printf("Soma correspondente nao encontrada!");
    }
    printf("###############################\n");

    free(result);

    return 0;
}
