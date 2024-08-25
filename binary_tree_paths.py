# 257. Binary Tree Paths

"""
given the 'root' of a binary tree, return all root to leaf paths in any
order. a leaf is a node with no children
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if not root:
            return []
        ans, stack = [], [(root, "")]
        while stack:
            node, ls = stack.pop()
            if not node.left and not node.right:
                ans.append(ls + str(node.val))
            if node.right:
                stack.append((node.right, ls + str(node.val) + "->"))
            if node.left:
                stack.append((node.left, ls + str(node.val) + "->"))
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.binaryTreePaths(root=[1, 2, 3, None, 5]))
