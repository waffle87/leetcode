# 2641. Cousins in Binary Tree II
from collections import Counter

"""
given the 'root' of a binary tree, replace the value of each node in the tree
with the sum of all its cousins' values. two nodes of a binary tree are
cousins if they have the same depth with different paths. return 'root' of
the modified tree. note that the depth of a nodie is a number of edges in the
path from the root node to it.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def replaceValueInTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        sum = Counter()

        def dfs1(r, l):
            if not r:
                return
            sum[l] += r.val
            dfs1(r.left, l + 1)
            dfs1(r.right, l + 1)

        dfs1(root, 0)

        def dfs2(r, l, curr):
            cousin_sum = (
                sum[l + 1]
                - (r.left.val if r.left else 0)
                - (r.right.val if r.right else 0)
            )
            if r.left:
                curr.left = TreeNode(cousin_sum)
                dfs2(r.left, l + 1, curr.left)
            if r.right:
                curr.right = TreeNode(cousin_sum)
                dfs2(r.right, l + 1, curr.right)
            return curr

        return dfs2(root, 0, TreeNode(0))


if __name__ == "__main__":
    obj = Solution()
    print(obj.replaceValueInTree(root=[5, 4, 9, 1, 10, None, 7]))
    print(obj.replaceValueInTree(root=[3, 1, 2]))
