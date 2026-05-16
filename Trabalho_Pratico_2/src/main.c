#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *nextGreaterElements(int *nums, int numsSize, int *returnSize)
{
    // Define o tamanho do vetor retornado
    (*returnSize) = numsSize;
    // Vetor retornado com as respostas
    int *resp = (int *)malloc(numsSize * sizeof(int));
    // Pilha com os índices dos elementos buscando um elemento maior
    int *pilha = (int *)malloc(numsSize * sizeof(int));

    // Pilha inicializada vazia
    int topo = -1;

    // Inicializa todas as respostas com -1
    // Deste modo, caso não seja encontrado um elemento maior ele permanece como está
    for (int i = 0; i < numsSize; i++)
    {
        resp[i] = -1;
    }

    // Percorre o vetor nums 2 vezes
    for (int i = 0; i < 2 * numsSize; i++)
    {
        // Garante que o indice atue circularmente
        int indice = i % numsSize;

        // Enquanto a pilha tiver elementos e o
        // elemento atual for maior que o elemento representado pelo topo da pilha
        while (topo != -1 && nums[indice] > nums[pilha[topo]])
        {
            // Guarda o próximo maior elemento na posição correspondente
            resp[pilha[topo]] = nums[indice];
            // Remove o topo da pilha
            topo--;
        }

        // Empilha apenas na primeira passagem
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

    free(newNums);

    return 0;
}
