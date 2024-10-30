# 987. Vertical Order Traversal of a Binary Tree
from collections import defaultdict

"""
given the 'root' of a binary tree, calcuate the vertical order traversal of
the binary tree. for each node at position '(row, col)', its left and right
children will be at positions '(row + 1, col - 1)' and '(row + 1, col + 1)'
respectively. the root of the tree is at '(0, 0)'. the vertical order
traversal of a binary tree is a list of top to bottom ordering for each
column index starting from the leftmost column and ending on the rightmost
column. there may be multiple nodes in the same row and same column. in such
a case, sort these nodes by their values. return the vertical order traversal
of the binary tree
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def helper(self, placement, level, root, _dict, limits):
        if not root:
            return
        _dict[placement].append((level, root.val))
        limits[0] = min(limits[0], placement)
        limits[1] = max(limits[1], placement)
        self.helper(placement - 1, level + 1, root.left, _dict, limits)
        self.helper(placement + 1, level + 1, root.right, _dict, limits)

    def verticalTraversal(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """
        _dict = defaultdict(list)
        limits = [float("inf"), float("-inf")]
        self.helper(0, 0, root, _dict, limits)
        ans = []
        for i in range(limits[0], limits[1] + 1):
            tmp = []
            for j in sorted(_dict[i]):
                tmp.append(j[1])
            ans.append(tmp)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.verticalTraversal(root=[3, 9, 20, None, None, 15, 7]))
    print(obj.verticalTraversal(root=[1, 2, 3, 4, 5, 6, 7]))
    print(obj.verticalTraversal(root=[1, 2, 3, 4, 6, 5, 7]))
