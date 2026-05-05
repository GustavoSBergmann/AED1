#include <stdio.h>

// Função recursiva para calcular fatorial
int fatorial(int n)
{
    int fat = 0;
    // Caso base
    if (n <= 1)
    {
        fat = 1;
        return fat;
    }
    else
    {
        fat = n * fatorial(n - 1);
        return fat; // Chamada recursiva
    }
}

int main()
{
    int num = 5;
    printf("Fatorial de %d: %d\n", num, fatorial(num)); // Saída: 120
    return 0;
}
