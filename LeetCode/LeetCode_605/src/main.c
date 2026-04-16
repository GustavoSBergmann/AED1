#include <stdio.h>
#include <stdbool.h>

bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n)
{
    int number = 0;
    for (int i = 0; i < flowerbedSize; i++)
    {
        if (flowerbed[i] == 0)
        {
            int left = (i == 0) ? 0 : flowerbed[i - 1];
            int right = (i == flowerbedSize - 1) ? 0 : flowerbed[i + 1];

            if (left == 0 && right == 0)
            {
                flowerbed[i] = 1;
                number++;
            }
        }
    }

    return (number >= n);
}

// int main(int argc, char const *argv[])
int main()
{
    int flowerbed[5] = {1, 0, 0, 0, 1};
    int flowerbedSize = 5, n = 1;
    bool canBePlanted;

    canBePlanted = canPlaceFlowers(flowerbed, flowerbedSize, n);

    if (canBePlanted)
    {
        printf("Podem ser plantadas %d flores", n);
    }
    else
    {
        printf("NAO podem ser plantadas %d flores", n);
    }

    return 0;
}
