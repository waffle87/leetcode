# 876. Middle of the Linked List

"""
given the head of a singly linked list, return the middle of the node of the
linked list. if there are two middle nodes, return the second middle node.
"""

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        slow, fast = head, head
        while fast:
            fast = fast.next
            if fast:
                fast = fast.next
                slow = slow.next
        return slow
