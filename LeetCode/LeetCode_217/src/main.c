#include <stdio.h>
#include <stdbool.h>

// Não é a solução perfeita, mas foi o que consegui fazer

bool containsDuplicate(int *nums, int numsSize)
{
    for (int read = 0; read < numsSize; read++)
    {
        int cmp = read + 1;
        while (cmp < numsSize)
        {
            if (nums[read] == nums[cmp])
            {
                return true;
            }
            cmp++;
        }
    }
    return false;
}

int main()
{
    int nums[4] = {1, 2, 3, 4};
    int numsSize = 4;
    bool containsDup;

    containsDup = containsDuplicate(nums, numsSize);

    printf("%s", (containsDup) ? "Numeros repetidos" : "Numeros distintos");

    return 0;
}
