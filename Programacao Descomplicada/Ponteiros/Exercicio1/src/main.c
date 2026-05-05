#include <stdio.h>

int main()
{
    int inteiro = 10;
    float real = 25.25;
    char caractere = 'A';

    int *pInteiro = &inteiro;
    float *pReal = &real;
    char *pCaractere = &caractere;

    printf("\n--------- Antes da Modificacao ---------\n");
    printf("Inteiro: %d \n", inteiro);
    printf("Real: %.02f \n", real);
    printf("Caractere: %c \n", caractere);

    *pInteiro = 27;
    *pReal = 49.49;
    *pCaractere = 'B';

    printf("\n--------- Depois da Modificacao ---------\n");
    printf("Inteiro: %d \n", inteiro);
    printf("Real: %.02f \n", real);
    printf("Caractere: %c \n", caractere);

    return 0;
}
