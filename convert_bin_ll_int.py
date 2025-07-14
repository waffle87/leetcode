# 1290. Convert Binary Number in a Linked List to Integer

"""
given 'head' which is a reference node to a singly linked list. the value of
each node in the linked list is either 0 or 1. the linked list holds the
binary representation of a number. return the decimal value of the number in
the linked list. the most significant bit is at the head of the linked list.
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def getDecimalValue(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: int
        """
        ans = 0
        while head:
            ans = 2 * ans + head.val
            head = head.next
        return ans


if __name__ == "__main__":
    obj = Solution()
    h1 = ListNode(1, ListNode(0, ListNode(1)))
    h2 = ListNode(0)
    print(obj.getDecimalValue(h1))
    print(obj.getDecimalValue(h2))
