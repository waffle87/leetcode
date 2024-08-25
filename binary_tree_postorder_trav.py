# 145. Binary Tree Postorder Traversal

"""
given the 'root' of a binary tree, return the postorder traversal of its
nodes' values
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        trav, stack = [], [root]
        while stack:
            node = stack.pop()
            if node:
                trav.append(node.val)
                stack.append(node.left)
                stack.append(node.right)
        return trav[::-1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.postorderTraversal(root=[1, None, 2, 3]))
