# 2415. Reverse Odd Levels of Binary Tree

"""
given the 'root' of a perfect binary tree, reverse the node values at each
odd level of the tree. return the root of the reversed tree. a binary tree is
perfect if all parent nodes have two children and all leaves are on the same
level. the level of a node is the number of edges along the path between it
and the root node.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def reverseOddLevels(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """

        def dfs(node1, node2, level):
            if not node1 or not node2:
                return
            if level % 2 != 0:
                node1.val, node2.val = node2.val, node1.val
            dfs(node1.left, node2.right, level + 1)
            dfs(node1.right, node2.left, level + 1)

        dfs(root.left, root.right, 1)
        return root


if __name__ == "__main__":
    obj = Solution()
    print(obj.reverseOddLevels(root=[2, 3, 5, 8, 13, 21, 34]))
    print(obj.reverseOddLevels(root=[7, 13, 11]))
    print(obj.reverseOddLevels(root=[0, 1, 2, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2]))
