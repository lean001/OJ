#include <stdio.h>

void exchange(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *array, int begin, int end)
{
    int key = array[end];
    int index = begin - 1;
    int j;
    for (j = begin; j <= end - 1; j++)
    {
        if (array[j] <= key)
        {
            index += 1;
            exchange(&array[index], &array[j]);
        }       
    }
    exchange(&array[index + 1], &array[end]);
    return index + 1;
}


void quickSort(int *array, int begin, int end)
{
    int mid = -1;
    if (begin < end)
    {
        mid = partition(array, begin, end);
        quickSort(array, begin, mid - 1);
        quickSort(array, mid + 1, end);
    }
}

void printArr(int *arr, int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char **argv)
{
    int arr[] = {90, 4, 6, 34, -9, 12, 55};
    printArr(arr, 7);

    quickSort(arr, 0, 7);

    printArr(arr, 7);

    return 0;
}
