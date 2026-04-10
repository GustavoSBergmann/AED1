#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *str = (char *)malloc(100);
    int qtd = 0;

    printf("Escreva na string: ");
    scanf("%99s", str);
    for (int i = 0; *(str + i) != '\0'; i++)
    {
        if (*(str + i) == '1')
        {
            qtd++;
        }
    }

    free(str);

    printf("Os 1's encontrados foram: %d\n", qtd);

    return 0;
}