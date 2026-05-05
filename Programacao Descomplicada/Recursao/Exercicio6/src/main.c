#include <stdio.h>

int mult(int n1, int n2)
{
    if (n2 == 1)
    {
        return n1;
    }
    else
    {
        return n1 + mult(n1, n2 - 1);
    }
}

int main()
{
    int n1 = 4, n2 = 4;

    printf("Resultado %d x %d: %d \n", n1, n2, mult(n1, n2));

    return 0;
}
