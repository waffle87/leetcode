# 725. Split Linked List in Parts

"""
given the 'head' of a singly linked list and an integer 'k', split the linked
list into 'k' consecutive linked list parts. the length of each part should
be as equal as possible: no two parts should have a size differing by more
than one. this may lead some parts being null. the parts should be in the
order of occurence in the input list, and parts occuring earlier should
always have a size greater than or equal to parts occuring later. return an
array of the 'k' parts.
"""


class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def splitListToParts(self, head, k):
        parts = [None] * k
        len = 0
        node = head
        while node:
            len += 1
            node = node.next
        n, r = divmod(len, k)
        node = root
        prev = None
        for i in range(k):
            parts[i] = node
            for j in range(n + (1 if r > 0 else 0)):
                prev = node
                node = node.next
            if prev:
                prev.next = None
            if r > 0:
                r -= 1
        return parts
