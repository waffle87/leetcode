# 872. Leaf-Similar Trees

"""
consider all levels of a binary tree, from left to right order, the value of
those leaves form a leaf value sequence. two binary trees are considered leaf
similar if their leafe value sequence is the same. return 1 if and only if
the two given trees with head nodes 'root1' and 'root2' are leaf-similar.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """

        def dfs(root):
            if root is None:
                return []
            leaves = dfs(root.left) + dfs(root.right)
            return leaves or [root.val]

        return dfs(root1) == dfs(root2)


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.leafSimilar(
            root1=[3, 5, 1, 6, 2, 9, 8, null, null, 7, 4],
            root2=[3, 5, 1, 6, 7, 4, 2, null, null, null, null, null, null, 9, 8],
        )
    )  # expect: True
    print(obj.leafSimilar(root1=[1, 2, 3], root2=[1, 3, 2]))  # expect: False
