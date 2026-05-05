#include <stdio.h>

void imprimeFaixa(int n)
{
    if (n >= 0)
    {
        imprimeFaixa(n - 1);
        printf("%d\n", n);
    }
}

int main()
{
    int numero = 10;

    imprimeFaixa(numero);

    return 0;
}
