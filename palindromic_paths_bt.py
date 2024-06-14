# 1457. Pseudo-Palindromic Paths in a Binary Tree

"""
given a binary tree where node values are digits from 1 to 9. a path in the
binary tree is said to be pseudo palindromic if at least one permutation of
the node values in the path is a palindrome. return the number of pseudo
palindromic paths going from the root node to leaf nodes.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def pseudoPalindromicPaths(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        count ^= 1 << (root.val - 1)
        res = self.pseudoPalindromicPaths(
            root.left, count
        ) + self.pseudoPalindromicPaths(root.right, count)
        if root.left == root.right:
            if count & (count - 1) == 0:
                res += 1
        return res


if __name__ == "__main__":
    obj = Solution()
    print(obj.pseudoPalindromicPaths(root=[2, 3, 1, 3, 1, null, 1]))
    print(
        obj.pseudoPalindromicPaths(
            root=[2, 1, 1, 1, 3, null, null, null, null, null, 1]
        )
    )
    print(obj.pseudoPalindromicPaths(root=[9]))
