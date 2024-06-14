# 543. Diameter of Binary Tree

"""
given the 'root' of a binary tree, return the length of the diameter of the
tree. the diameter of a binary tree is the length of the longest path between
any two nodes in a tree. this path may or may not pass through the 'root'.
the length of a path between two nodes is represented by the number of edges
between them
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        def depth(p):
            if not p:
                return 0
            left, right = depth(p.left), depth(p.right)
            self.ans = max(self.ans, left + right)
            return max(left, right) + 1

        depth(root)
        return self.ans


if __name__ == "__main__":
    obj = Solution()
