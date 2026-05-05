#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return (fibonacci(n - 1) + fibonacci(n - 2));
    }
}

int main()
{
    int termo = 6;

    printf("Termo %d da sequencia de Fibonacci: %d", termo, fibonacci(termo));

    return 0;
}
