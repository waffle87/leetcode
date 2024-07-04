# 2181. Merge Nodes in Between Zeros

"""
given the 'head' of a linked list which contains a series of integers
separated by 0's. the beginning and end of the linked list will have
'node.val == 0'. for every consecutive 0's, merge all the nodes lying in
between them into a single node whose value is the sum of all the merged
nodes. the modified list should not contain any 0's. return the 'head' of the
modified linked list.
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def mergeNodes(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        p1, p2 = head, head.next
        s = 0
        while p2:
            if p2.val == 0:
                p1 = p1.next
                p1.val = s
                s = 0
            else:
                s += p2.val
            p2 = p2.next
        p1.next = None
        return head.next
