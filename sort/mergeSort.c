/*归并排序*/
#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int begin, int mid, int end)
{
    int left = begin;
    int right = mid + 1;
    int k;
    int *tmp = (int *)malloc(sizeof(int) * (end - begin + 1));

    k = 0;
    while( left <= mid && right <= end )
    {
        if (array[left] < array[right])
            tmp[k] = array[left++];
        else
            tmp[k] = array[right++];
        k++;
    }

    while(left <= mid)
        tmp[k++] = array[left++];
    while(right <= end)
        tmp[k++] = array[right++];

    for( left = 0; left < k; left++ )
        array[begin + left] = tmp[left];

    free(tmp);
}

void mergesort(int *array, int begin, int end)
{
    if (array == NULL || begin >= end)
        return;
    int mid = (begin + end) / 2;
    mergesort(array, begin, mid);
    mergesort(array, mid + 1, end);
    merge(array, begin, mid, end);
}



int main()
{
    int i;
    int nums[] = {4, 3, 43, 87, 0, 1, 33, 9, 99};

    for(i = 0; i < 9; i++)
        printf("%d ", nums[i]);
    printf("\n");

    mergesort(nums, 0, 8);

    for(i = 0; i < 9; i++)
        printf("%d ", nums[i]);
     printf("\n");

   return 0; 
}
