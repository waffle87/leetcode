# 404. Sum of Left Leaves
from collections import deque

"""
given the 'root' of a binary tree, return the sum of all left leaves. a leaf
is a node with no childen. a leaft leaf is a leaf that is the left child of
another node.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        s, ans = deque([(root, False)]), 0
        while s:
            curr, is_left = s.pop()
            if not curr.left and not curr.right and is_left:
                ans += curr.val
            if curr.right:
                s.append((curr.right, False))
            if curr.left:
                s.append((curr.left, True))
        return ans
