/*子串最大乘积
 * {3， 4， -1，  5}
 * return 12*/
/*
 * {3, 4 } | 5 ==> 60
 * {-3, 4} | -5 ==>60
 * {0.1, 0.3} | 5 ==> 5
 * */
#include <stdio.h>
#include <stdlib.h>
double max(double a, double b)
{
    if (a - b >= 0)
        return a;
    else
        return b;
}

double min(double a, double b)
{
    if ( a - b <= 0 )
        return a;
    else
        return b;
}

double maxSubProduct(double* nums, int len)
{
    double result = 0;
    double _max = nums[0];
    double _min = nums[0];
    double minEnd;
    double maxEnd;
    int i;

    if(nums == NULL || len <= 0)
        return -1;
    if (len == 1)
        return nums[0];

    for(i = 1; i < len; i++)
    {
        maxEnd = _max * nums[i];
        minEnd = _min * nums[i];

        _max = max(max(maxEnd, minEnd), nums[i]);
        _min = min(min(minEnd, maxEnd), nums[i]);
        result = max(_max, result);
        printf("%f\n", result);
    }
    return result;
}


int main()
{
    double nums[] = {-5, 3, -1, -6, 3};

    printf("%f\n", maxSubProduct(nums, 5));

    return 0;
}
