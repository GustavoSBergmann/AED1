#include <stdio.h>

int sum(int num1, int num2);

void main()
{
    int num1, num2;

    printf("Num1: ");
    scanf("%d", &num1);

    printf("Num2: ");
    scanf("%d", &num2);

    printf("%d", sum(num1, num2));
}

int sum(int num1, int num2)
{
    return (num1 + num2);
}