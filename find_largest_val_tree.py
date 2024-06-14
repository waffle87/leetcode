# 515. Find Largest Value in Each Tree Row

"""
given the 'root' of a binary tree, return an array of the largest value in
each row of the tree (0-indexed)
"""


class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def largestValues(self, root):
        ans = []
        row = [root]
        while any(row):
            ans.append(max(node.val for node in row))
            row = [child for node in row for child in (node.left, node.right) if child]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.largestValues(root=[1, 3, 2, 5, 3, null, 9]))  # expect: 1, 3, 9
    print(obj.largestValues(root=[1, 2, 3]))  # expect: 1, 3
