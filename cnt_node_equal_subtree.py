# 2265. Count Nodes Equal to Average of Subtree
from leetcode import TreeNode, treenode_build

"""
given the root of a binary tree, return the number of nodes where the value
of the node is equal to the average of the values in its subtree. note, the
average of 'n' elements is the sum of the n elements divided by n and rounded
down to the nearest integer. also, a subtree of root is a tree consisting of
root and all of its descendants
"""


class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        def dfs(node):
            if node is None:
                return 0, 0
            left_sum, left_cnt = dfs(node.left)
            right_sum, right_cnt = dfs(node.right)
            subtree_sum = left_sum + right_sum + node.val
            subtree_cnt = left_cnt + right_cnt + 1
            if subtree_sum // subtree_cnt == node.val:
                nonlocal total_cnt
                total_cnt += 1
            return subtree_sum, subtree_cnt

        total_cnt = 0
        dfs(root)
        return total_cnt


if __name__ == "__main__":
    obj = Solution()
    r1 = treenode_build(vals=[4, 8, 5, 0, 1, None, 6])
    r2 = treenode_build(vals=[1])
    print(obj.averageOfSubtree(r1))
    print(obj.averageOfSubtree(r2))
