#include <stdio.h>

int somaCubos(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return (n * n * n + somaCubos(n - 1));
    }
}

int main()
{
    int numero = 4;

    printf("Soma dos %d primeiros cubos: %d", numero, somaCubos(numero));

    return 0;
}
