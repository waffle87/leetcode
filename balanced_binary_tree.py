# 110. Balanced Binary Tree
import leetcode

"""
given a binary tree, determine if it is height balanced
"""


class Solution(object):
    def isBalanced(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        self.balanced = True

        def dfs(node):
            if not node:
                return 0
            l, r = dfs(node.left), dfs(node.right)
            if abs(l - r) > 1:
                self.balanced = False
            return max(l, r) + 1

        dfs(root)
        return self.balanced


if __name__ == "__main__":
    obj = Solution()
    r1 = leetcode.treenode_build(vals=[3, 9, 20, None, None, 15, 7])
    r2 = leetcode.treenode_build(vals=[1, 2, 2, 3, 3, None, None, 4, 4])
    print(obj.isBalanced(r1))
    print(obj.isBalanced(r2))
