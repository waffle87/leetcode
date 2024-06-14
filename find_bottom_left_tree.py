# 513. Find Bottom Left Tree Value

"""
given the 'root' of a binary tree, return the leftmost value in the last row
of the tree
"""


class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def findBottomLeftValue(self, root):
        queue = [root]
        for node in queue:
            queue += filter(None, (node.right, node.left))
        return node.val
