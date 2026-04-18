#include <stdio.h>
#include <stdbool.h>

bool lemonadeChange(int *bills, int billsSize)
{
    int five = 0, ten = 0;
    for (int cliente = 0; cliente < billsSize; cliente++)
    {
        if (bills[cliente] == 5)
        {
            five++;
        }
        if (bills[cliente] == 10)
        {
            if (five > 0)
            {
                ten++;
                five--;
            }
            else
            {
                return false;
            }
        }
        if (bills[cliente] == 20)
        {
            if (five > 0 && ten > 0)
            {
                ten--;
                five--;
            }
            else if (five > 2)
            {
                five -= 3;
            }
            else
            {
                return false;
            }
        }
    }
    if (five >= 0 && ten >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    int bills[5] = {5, 5, 10, 10, 20};
    int billsSize = 5;
    bool canSale;

    canSale = lemonadeChange(bills, billsSize);

    printf("%d\n", canSale);

    return 0;
}
