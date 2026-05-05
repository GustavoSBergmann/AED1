#include <stdio.h>

int somatorio(int n);

int main()
{
    int numero = 5;

    printf("O somatorio de %d: %d", numero, somatorio(numero));

    return 0;
}

int somatorio(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return (n + somatorio(n - 1));
    }
}