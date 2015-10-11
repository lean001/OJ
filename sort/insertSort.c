#include <stdio.h>

void insertSort(int *array, int len)
{
     int key,i, j;

    for (i = 2; i < len; i++) {
         key = array[i];
         j = i - 1;
        while (j >= 0 && array[j] > key) { 
             array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}


int main()
{
    int A[] = {31, 41, 59, 0, 26, 41, 58};
    int i;

    for(i = 0; i < 7; i++)
        printf("%d ", A[i]);
    printf("\n");

    insertSort(A, 7);

    for(i = 0; i < 7; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
