# -*- coding:utf-8 -*-
AC
class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        result = ''
        for ch in s:
            if ch == ' ':
                result = '%s%s' % (result, '%20') 
            else:
                result = '%s%s' % (result, ch)
        return result

s = Solution()
print s.replaceSpace(" We Are Happy")

