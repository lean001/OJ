#include <stdio.h>

int maxProfit(int *prices, int lenght)
{
    int i, j;
    int tmp;
    int sum[2] = {0};
    for (i = 0; i< length; i++)
    {
        tmp = prices[i];
        for (j = i + 1; j < lenght; j++)
        {
            if (prices[j] - tmp > 0)
                sum[0] += prices[j] - tmp;
        }
    }
}
