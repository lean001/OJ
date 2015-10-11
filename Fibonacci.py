#/usr/bin/python

class Solution:
    def Fibonacci(self, n):
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        first = 1
        second = 1
        tmp = 0
        for x in range(n):
            tmp = first + second
            first = second
            second = tmp
        return first 

s = Solution()
print s.Fibonacci(5)
