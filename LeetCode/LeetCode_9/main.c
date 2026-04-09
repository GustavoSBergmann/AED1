#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
    double original = x, invertido = 0;

    // Inverte o número
    while (x > 0)
    {
        invertido = (invertido * 10) + (x % 10);
        x /= 10;
    }

    return (original == invertido);
}

void main()
{
    int x = -121;

    if (isPalindrome(x))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}