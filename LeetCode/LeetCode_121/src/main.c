#include <stdio.h>

int maxProfit(int *prices, int pricesSize)
{
    int min = prices[0], max = 0;

    for (int i = 1; i < pricesSize; i++)
    {
        if (min > prices[i])
        {
            min = prices[i];
        }
        else
        {
            int profit = prices[i] - min;
            if (max < profit)
            {
                max = profit;
            }
        }
    }
    return max;
}

int main(int argc, char const *argv[])
{
    int prices[3] = {2, 4, 1};
    int pricesSize = 3, maxGain;

    maxGain = maxProfit(prices, pricesSize);

    printf("Lucro maximo: %d\n", maxGain);

    return 0;
}
