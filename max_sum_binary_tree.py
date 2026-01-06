# 1161. Maximum Level Sum of a Binary Tree
import leetcode

"""
given the 'root' of a binary tree, the level of its root is 1, the level of
its children is 2, and so on. return the smallest level 'x' such that the sum
of all the values of nodes at level 'x' is maximal.
"""


class Solution(object):
    def maxLevelSum(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        ans, q, depth = (float("-inf"), 0), [root], -1
        while q:
            ans = max(ans, (sum(node.val for node in q), depth))
            q = [kid for node in q for kid in (node.left, node.right) if kid]
            depth -= 1
        return -ans[1]


if __name__ == "__main__":
    obj = Solution()
    r1 = leetcode.treenode_build(vals=[1, 7, 0, 7, -8, None, None])
    r2 = leetcode.treenode_build(
        vals=[989, None, 10250, 98693, -89388, None, None, None, -32127]
    )
    print(obj.maxLevelSum(r1))
    print(obj.maxLevelSum(r2))
