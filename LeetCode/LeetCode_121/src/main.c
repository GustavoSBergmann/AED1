#include <stdio.h>

int maxProfit(int *prices, int pricesSize)
{
    int min = prices[0], max = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] < min)
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

int main()
{
    int prices[6] = {7, 1, 5, 3, 6, 4};
    int pricesSize = 6, maxGain;

    maxGain = maxProfit(prices, pricesSize);

    printf("Lucro maximo: %d\n", maxGain);

    return 0;
}
