# 1022. Sum of Root To Leaf Binary Numbers
from typing import Optional

from leetcode import TreeNode, treenode_build

"""
you are given the 'root' of a binary tree where each node has a value of 0
or 1. each root to leaf path represents a binary number starting with the
most significant bit. for all leaves in the tree, consider the numbers
represented by the path from the root to that leaf. return the  sum of these
numbers. the test cases are generated such that the answer fits in a 32-bit
integer.
"""


class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        def dfs(node, val):
            if not root:
                return 0
            val = (val << 1) + node.val
            if not node.left and not node.right:
                return val
            return dfs(node.left, val) + dfs(node.right, val)

        return dfs(root, 0)


if __name__ == "__main__":
    obj = Solution()
    r1 = treenode_build(vals=[1, 0, 1, 0, 1, 0, 1])
    r2 = treenode_build(vals=[0])
    print(obj.sumRootToLeaf(r1))
    print(obj.sumRootToLeaf(r2))
