#include <stdio.h>


double maxSubSum(double* nums, int len)
{
    double maxSum = nums[0];
    double tmpSum = nums[0];
    int i;

    if (nums == NULL || len <= 0)
        return -1;
    if (len == 1)
        return nums[0];

    for(i = 1; i < len; i++)
    {
        tmpSum += nums[i];
        if (tmpSum < 0)
            tmpSum = 0;
        if (tmpSum > maxSum)
            maxSum = tmpSum;
    }
    return maxSum;
}


int main()
{
    double nums[] = { 2, -1, -1, 4, -5, 9 };

    printf("%f\n", maxSubSum(nums, 6));

    return 0;
}
