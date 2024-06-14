# 143. Reorder List

"""
given the head of a singly linked list. the list can be represented as 'l0 ->
l1 -> ... -> Ln'. reorder the list to be of the following form: 'l0 -> ln ->
ln-1 -> ln-2'. you may not modify the values in the list's nodes. only nodes
themselves may be changed.
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        if not head:
            return []
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        prev, curr = None, slow.next
        while curr:
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp
        slow.next = None
        head1, head2 = head, prev
        while head2:
            tmp = head1.next
            head1.next = head2
            head1 = head2
            head2 = tmp
