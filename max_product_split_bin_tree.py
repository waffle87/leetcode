# 1339. Maximum Product of Splitted Binary Tree
import leetcode

"""
given the 'root' of a binary tree, split the binary tree into two subtrees by
removing one edge such that the product of the sums of the subtrees is
maximised. return the maximum product of the sums of the two subtrees. since
the answer may be too large, return it modulo 10^9+7. note that you need to
maximise the answer before taking the mod, and not after.
"""


class Solution(object):
    def total_sum(self, node):
        if not node:
            return 0
        return node.val + self.total_sum(node.left) + self.total_sum(node.right)

    def maxProduct(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        self.best = 0

        total = self.total_sum(root)

        def dfs(node):
            if not node:
                return 0
            s = node.val + dfs(node.left) + dfs(node.right)
            self.best = max(self.best, s * (total - s))
            return s

        dfs(root)
        return self.best % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    r1 = leetcode.treenode_build(vals=[1, 2, 3, 4, 5, 6])
    r2 = leetcode.treenode_build(vals=[1, None, 2, 3, 4, None, None, 5, 6])
    print(obj.maxProduct(r1))
    print(obj.maxProduct(r2))
