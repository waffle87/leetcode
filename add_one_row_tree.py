# 623. Add One Row to Tree

"""
given the 'root' of a binary tree and two integers 'val' and 'depth', add a
row of nodes with value 'val' at the given depth 'depth'. note that 'root'
node is at depth 1. the adding rule is given the integer 'depth' for each
non-null tree node 'curr' at the depth 'depth - 1' create two tree nodes with
value 'val' as 'curr's left subtree root and right subtree root. 'curr's
original left subtree should be the left subtree of the new left subtree
root. if 'depth == 1' that means that there is no depth 'depth - 1' at all,
then create a tree node with value 'val' as the new root of the whole
original tree, and the original tree is the new left subtree.
"""


class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def addOneRow(self, root, val, depth):
        """
        :type root: TreeNode
        :type val: int
        :type depth: int
        :rtype: TreeNode
        """

        def dfs(root, val, depth):
            if root == None:
                return
            if depth > 2:
                dfs(root.left, val, depth - 1)
                dfs(root.right, val, depth - 1)
            else:
                ptr = root.left
                root.left = TreeNode(val, ptr, None)
                ptr = root.right
                root.right = TreeNode(val, None, ptr)

        if depth == 1:
            ptr = TreeNode(val, root, None)
            return ptr
        dfs(root, val, depth)
        return root
