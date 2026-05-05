#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array = (int *)malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        printf("Insira o valor %d: ", i + 1);
        scanf(" %d", (array + i));
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Valor %d: %d\n", i + 1, *(array + i));
    }

    free(array);

    return 0;
}
