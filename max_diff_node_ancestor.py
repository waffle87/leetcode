# 1026. Maximum Difference Between Node and Ancestor

"""
given the 'root' of a binary tree, find the maximum value 'v' for which there
exists different nodes 'a' and 'b' where 'v = | a.val - b.val |' and 'a' is
an ancesotr of 'b'. a node 'a' is an ancesotr of 'b' if either any child if
'a' is equal to 'b' or any child 'a' is an ancestor of 'b'.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def helper(self, root, min_val, max_val):
        if not root:
            return
        self.diff = max(
            self.diff, max(abs(min_val - root.val), abs(max_val - root.val))
        )
        min_val = min(min_val, root.val)
        max_val = max(max_val, root.val)
        self.helper(root.left, min_val, max_val)
        self.helper(root.right, min_val, max_val)

    def maxAncestorDiff(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        self.diff = 0
        self.helper(root, root.val, root.val)
        return self.diff


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxAncestorDiff(root=[8, 3, 10, 1, 6, None, 14, None, None, 4, 7, 13])
    )  # expect: 7
    print(obj.maxAncestorDiff(root=[1, None, 2, None, 0, 3]))  # expect: 3
