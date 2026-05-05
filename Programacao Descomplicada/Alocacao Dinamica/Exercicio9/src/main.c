#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array = NULL;
    int tamanho = 0;
    int n;

    do
    {
        printf("Insira um numero: ");
        scanf(" %d", &n);

        if (n >= 0)
        {
            tamanho++;
            int *temp = (int *)realloc(array, tamanho * sizeof(int));
            if (temp != NULL)
            {
                array = temp;
                array[tamanho - 1] = n;
            }
        }
    } while (n >= 0);

    printf("Array: [");
    for (int i = 0; i < tamanho; i++)
    {
        printf(" %d", array[i]);
    }
    printf(" ]\n");

    return 0;
}
