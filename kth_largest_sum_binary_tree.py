# 2583. Kth Largest Sum in a Binary Tree

"""
you are given the 'root' of a binary tree and a positive integer 'k'. the
level sum in the tree is the sum of the values of the nodes that are on the
same level. return the k'th largest level sum in the tree (not necessarily
distinct). if there are fewer than 'k' levels in the tree, return -1. note
that two nodes are on the same level if they have the same distance from the
root.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def kthLargestLevelSum(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
        """
        vals = []
        stack = [(root, 0)]
        while stack:
            node, i = stack.pop()
            if i == len(vals):
                vals.append(0)
            vals[i] += node.val
            if node.left:
                stack.append((node.left, i + 1))
            if node.right:
                stack.append((node.right, i + 1))
        return sorted(vals, reverse=True)[k - 1] if len(vals) >= k else -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.kthLargestLevelSum(root=[5, 8, 9, 2, 1, 3, 7, 4, 6], k=2))
    print(obj.kthLargestLevelSum(root=[1, 2, None, 3]))
