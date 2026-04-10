#include <stdio.h>

void main()
{
    char str[100];
    int tamanho = 0;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    for (int count = 0; str[count] != '\n'; count++)
    {
        tamanho++;
    }
    printf("Tamanho da string: %d", tamanho);
}