# -*- coding:utf-8 -*-
class ListNode:
    def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        L = []
        while listNode:
            L.append(listNode.val)
            listNode = listNode.next
        return L[::-1]



node = ListNode(1)
node1 = ListNode(2)
node2 = ListNode(3)
node.next = node1
node1.next = node2

S = Solution()
print S.printListFromTailToHead(node)

