# 1325. Delete Leaves With a Given Value

"""
given a binary tree 'root' and an integer 'target', delete all the leaf nodes
with value 'target'. note that once you delete a leaf node with value
'target', if its parent node becomes a leaf node and has the value 'target',
it should also be deleted (you need to continue doing that until you cannot)
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def removeLeafNodes(self, root, target):
        """
        :type root: TreeNode
        :type target: int
        :rtype: TreeNode
        """
        if root.left:
            root.left = self.removeLeafNodes(root.left, target)
        if root.right:
            root.right = self.removeLeafNodes(root.right, target)
        return None if root.left == root.right and root.val == target else root
