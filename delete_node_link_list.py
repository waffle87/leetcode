# 237. Delete Node in a Linked List

"""
there is a singy linked list 'head' and we want to delete a node 'node' in
it. you are given the node to be deleted 'node'. you will not be given access
to the first node of 'head'. all the values of the linked list are unique and
it is guaranteed that the given node 'node' is not the last node in the
linked list. delete the given node. note that by deleting the node, we do not
mean removing it from memory.
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val = node.next.val
        node.next = node.next.next
