#include <stdio.h>

int kElevadoN(int k, int n)
{
    if (n == 1)
    {
        return k;
    }
    else
    {
        return (k * kElevadoN(k, n - 1));
    }
}

int main()
{
    int k = 3;
    int n = 4;

    printf("%d elevado a %d: %d", k, n, kElevadoN(k, n));

    return 0;
}
