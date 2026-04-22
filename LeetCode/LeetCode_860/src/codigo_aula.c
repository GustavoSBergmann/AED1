#include <stdio.h>
#include <stdbool.h>

bool lemonadeChange(int *bills, int billsSize)
{
    int i, j;
    for (j = 1; j < billsSize; j++)
    {
        i = j - 1;
        int temp = bills[j];

        if (temp == 10)
        {
            while (i >= 0 && bills[i] != 5)
            {
                i--;
            }
            if (bills[i + 1] == 5)
            {
                bills[i + 1] = 0;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int bills[5] = {5, 5, 5, 10, 20};
    int billsSize = 5;
    bool canSale;

    canSale = lemonadeChange(bills, billsSize);

    printf("%d\n", canSale);

    return 0;
}
