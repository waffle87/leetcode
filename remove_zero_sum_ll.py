# 1171. Remove Zero Sum Consecutive Nodes from Linked List

"""
given the 'head' of a linked list, we repeatedly delete the consecutive
sequences of nodes that sum to 0 until there are no such sequences. after
doing so, return the head of the final linked list. you may return any such
answer.
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def removeZeroSumSublists(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        curr = tmp = ListNode(0)
        tmp.next = head
        prefix = 0
        seen = collections.OrderedDict()
        while curr:
            prefix += curr.val
            node = seen.get(prefix, curr)
            while prefix in seen:
                seen.popitem()
            seen[prefix] = node
            node.next = curr = curr.next
        return tmp.next
