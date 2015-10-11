#include <stdio.h>

int* arrayPrint(int **arr, int n)
{
    int col = n - 1;
    int row = 0;
    int index;
    int *result = (int *)malloc(sizeof(int) * n * n);

    result[0] = arr[row][col];
    
    index = 1;
    col = n - 2;
    while ( index < n*n )
    {
        if (col == n - 1 && 
        {
            if (col == n - 1 && row != 0)
                row = 0;

        } else
        {
            result[index++] = arr[row++][col--];
        }
            
    }
}
