#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int myAtoi(char* str) {
    int len = strlen(str);
    int sign = 0;
    long long result = 0;
    int i = 0;
    int j;
    char* pstr = str;

    if ((len == 0 || str[0] < '0' || str[0] > '9') && str[0] != '-' && str[0] != '+' && str[0] != ' ')
        return 0;
    
    if (len == 1 && str[0] >= '0' && str[0] <= '9')
        return str[0] - '0';

    int* pNums = (int*)malloc(sizeof(int) * len);
    if (!pNums)
        return 0;

    if(str[0] == '-')
        sign = 1;
    else if(str[0] == '+')
        sign = 2;

    if (sign)
    {
        pstr++;
        while (i < len && *pstr != '\0')
        {
            if (*pstr > '9' || *pstr < '0')
                break;
            pNums[i++] = *pstr - '0';
            pstr++;
        }
    }else{
        while(*pstr == ' ')
            pstr++;
        if (*pstr == '+')
        {
            sign = 2;
            pstr++;
        }else if(*pstr == '-')
        {
            sign = 1;
            pstr++;
        }
        while(i < len && *pstr != '\0')
        {
            if (*pstr > '9' || *pstr < '0')
                break;
            pNums[i++] = *pstr - '0';
            pstr++;
        }
    }

    for(j = 0; j < i ; j++)
        result += pNums[j] * (long long)powl(10.0, i - j - 1);

    free(pNums);
    result = sign == 1 ? -result : result;
    
    if (result > 2147483647)
        result = 2147483647;
    else if (result < -2147483648)
        result = -2147483648;

    return result;
}


int main()
{
    char nums[] = "34234242121";

    printf("%d\n", myAtoi(nums));

    return 0;
}
