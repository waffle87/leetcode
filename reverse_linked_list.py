# 206. Reverse Linked List

"""
given the 'head' of a singly linked list, reverse the list, and return the
reversed list.
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prev = None
        while head:
            curr = head
            head = head.next
            curr.next = prev
            prev = curr
        return prev


if __name__ == "__main__":
    obj = Solution()
    print(obj.reverseList(head=[1, 2, 3, 4, 5]))
    print(obj.reverseList(head=[1, 2]))
    print(obj.reverseList(head=[]))
