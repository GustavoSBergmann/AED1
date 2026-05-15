#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *nextGreaterElements(int *nums, int numsSize, int *returnSize)
{
    (*returnSize) = numsSize;
    int *resp = (int *)malloc(numsSize * sizeof(int));
    int *pilha = (int *)malloc(numsSize * sizeof(int));

    int topo = -1;

    for (int i = 0; i < numsSize; i++)
    {
        resp[i] = -1;
    }

    for (int i = 0; i < 2 * numsSize; i++)
    {
        int indice = i % numsSize;

        while (topo != -1 && nums[indice] > nums[pilha[topo]])
        {
            resp[pilha[topo]] = nums[indice];
            topo--;
        }

        if (i < numsSize)
        {
            topo++;
            pilha[topo] = indice;
        }
    }

    free(pilha);
    return resp;
}

int main()
{
    int nums[5] = {1, 2, 3, 4, 3};
    int numsSize = 5;
    int returnSize;
    int *newNums = NULL;

    newNums = nextGreaterElements(nums, numsSize, &returnSize);

    printf("Array: [");
    for (int i = 0; i < returnSize; i++)
    {
        printf(" %d", newNums[i]);
    }
    printf(" ]\n");

    return 0;
}
