#include <stdio.h>

int fatorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return (n * fatorial(n - 1));
    }
}

int main()
{
    int numero = 4;

    printf("Fatorial de %d = %d", numero, fatorial(numero));

    return 0;
}
