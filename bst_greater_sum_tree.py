# 1038. Binary Search Tree to Greater Sum Tree

"""
given the 'root' of a binary search tree, convert it to a greater tree such
that every key o the original bst is changed to the original key plus the sum
of all keys greater than the original key in bst. as a reminder, a binary
search tree is a tree that satisfies the following constraints. the left
subtree of a node contains only nodes with keys less than the node's key. the
right subtree of a node contains only nodes with keys greater than the node's
key. both the left and right subtrees also be binary search trees.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, accum=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    accum = 0

    def bstToGst(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root.right:
            self.bstToGst(root.right)
        root.accum = self.accum = self.accum + root.val
        if root.left:
            self.bstToGst(root.left)
        return root
