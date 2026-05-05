#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array = calloc(1500, sizeof(array));
    int qtd0 = 0;

    for (int i = 0; i < 1500; i++)
    {
        if (*(array + i) == 0)
        {
            qtd0++;
        }
        *(array + i) = i;
    }
    if (qtd0 == 1500)
    {
        printf("O array contem 1500 0's\n");
    }
    else
    {
        printf("O array NAO contem 1500 0's\n");
    }

    for (int i = 0; i < 10; i++)
    {
        printf("Elemento %d: %d \t", i, array[i]);
        printf("Elemento %d: %d \n", 1499 - i, array[1499 - i]);
    }

    free(array);

    return 0;
}
