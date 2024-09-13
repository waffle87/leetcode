# 124. Binary Tree Maximum Path Sum

"""
a path in a binary tree is a sequence of nodes where each pair of adjacent
nodes in the sequence has an edge connecting them. a node can only appear in
the sequence at most once. note that the path does not need to pass through
the root. the path sum of a path is the sum of the node's value in the path.
given the 'root' of a binary tree, return the maximum path sum of any non
empty path
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def dfs(self, root):
        if not root:
            return 0
        left = max(0, self.dfs(root.left))
        right = max(0, self.dfs(root.right))
        self.ans = max(self.ans, left + right + root.val)
        return max(left, right) + root.val

    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans = float("-inf")
        self.dfs(root)
        return self.ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxPathSum(root=[1, 2, 3]))
    print(obj.maxPathSum(root=[-10, 9, 20, None, None, 15, 7]))
