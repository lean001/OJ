#include <stdio.h>
#include <stdlib.h>


char* convert(char* s, int numRows)
{
    int i;

    if (s == NULL || numRows < 1 )
        return NULL;
    if (numRows == 1)
        return s;
    if (numRows == 2)
    {
        for (i = 0; i < numRows; i++)
        {
            if ( i == 0 || i == numRows - 1 )
                arr[i][count] = s[i + 2 * (numRows - 1)];
            else
                arr[i][count] = s[i + numRows - 1];
        }
    }

    i = 0;
    while ( i + 2 * (numRows - 1 ) < len)
    {
        one[count] = s[i + 2 * (numRows - 1)];
        i = i + 2 * (numRows - 1);
        count++;
    }
}
