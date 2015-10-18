/*搜找局部最小值
 \     /
  \   /
   \ /
    /
*/
#include <stdio.h>

int localMini(int* nums, int len)
{
    int left = 0;
    int right = len - 1;
    int mid = 0;
    if (nums == NULL || len <= 0)

        return -1;

    if(len == 1 || nums[1] > nums[0])
        return nums[0];
    if (nums[len - 1] < nums[len - 2])
        return nums[len - 1];

    while(left < right)
    {
        mid = left + ((right - left) >> 1);

        if (nums[mid] > nums[mid - 1])
            right = mid - 1;
        else if(nums[mid] > nums[mid + 1])
            left = mid + 1;
        else
            break;
    }
    return nums[mid];
}



int main()
{
    int nums[] = { 8, 7, 3, 4, 6, 9 };

    printf("%d\n", localMini(nums, 6));

    return 0;
}
