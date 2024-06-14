# 141. Linked List Cycle

"""
given the 'head' of a linked list, determine if the linked list has a cycle
in it. there is a cycle in a linked list if there is some node in the list
that can be reached again by continuously following the 'next' pointer.
internally, 'pos' is used to denote the index of the node that tail's 'next'
pointer is connected to. note that 'pos' is not passed as a parameter. return
true if there is a cycle in the linked list. otherwise return false.
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        fast = slow = head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
            if fast == slow:
                return True
        return False


if __name__ == "__main__":
    obj = Solution()
