#include <stdio.h>

bool isBadVersion(int version);

int firstBadVersion(int n)
{
    int right = n - 1;
    int left = 1;
    int mid;
    if (n <= 0 || !isBadVersion(n))
        return 0;
    if (n == 1 && isBadVersion(1))
        return n;

    while(left <= right)
    {
        mid = left + ((right - left) >> 2);
        if(!isBadVersion(mid) && isBadVersion(mid + 1)) /*v x*/
            return mid + 1;
        else if(!isBadVersion(mid) && !isBadVersion(mid + 1)) /*x x*/
            left = mid + 1;
        else if(isBadVersion(mid) && isBadVersion(mid + 1)) /*v v*/
            right = mid - 1
    }
}
