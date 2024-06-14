# 2265. Count Nodes Equal to Average of Subtree

"""
given the root of a binary tree, return the number of nodes where the value
of the node is equal to the average of the values in its subtree. note, the
average of 'n' elements is the sum of the n elements divided by n and rounded
down to the nearest integer. also, a subtree of root is a tree consisting of
root and all of its descendants
"""


class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def averageOfSubtree(self, root):
        ans = 0

        def traverse(node):
            nonlocal ans
            if not node:
                return 0, 0
            left_sum, left_count = traverse(node.left)
            right_sum, right_count = traverse(node.right)
            s = node.val + left_sum + right_sum
            c = 1 + left_count + right_count
            if s // c == node.val:
                ans += 1
            return s, c

        traverse(root)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.averageOfSubtree(root=[4, 8, 5, 0, 1, null, 6]))
    print(obj.averageOfSubtree(root=[1]))
