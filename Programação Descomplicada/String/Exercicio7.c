#include <stdio.h>
#include <stdlib.h>

void main()
{
    char str1[100], str2[100];

    printf("Insira a primeira string: ");
    scanf("%s", str1);

    printf("Insira a segunda string: ");
    scanf("%s", str2);

    for (int count = 0; str1[count] != '\0' || str2[count] != '\0'; count++)
    {
        if (str1[count] != str2[count])
        {
            printf("Strings DIFERENTES");
            exit(0);
        }
    }

    printf("Strings IGUAIS");
}