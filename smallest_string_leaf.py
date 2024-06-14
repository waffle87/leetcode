# 988. Smallest String Starting From Leaf

"""
given the 'root' of a binary tree where each node has a value in the range
'[0, 25]' representing letters 'a' to 'z'. return the lexicographically
smallest string that starts at a leaf of this tree and ends at the root. as a
reminder, any shorter prefix of a string is lexicographically smaller. a leaf
of a node is a node that has no children.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def smallestFromLeaf(self, root):
        """
        :type root: TreeNode
        :rtype: str
        """

        def dfs(root, s):
            s = s + chr(ord("a") + root.val)
            if not root.left and not root.right:
                if res[0] == None:
                    res[0] = s[::-1]
                else:
                    res[0] = min(res[0], s[::-1])
            if root.left:
                dfs(root.left, s)
            if root.right:
                dfs(root.right, s)

        if not root:
            return ""
        ans = [None]
        dfs(root, "")
        return ans[0]
