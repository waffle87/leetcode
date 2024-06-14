# 94. Binary Tree Inorder Traversal

"""
given the root of a binary tree, return the inorder traversal of its nodes
values
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """

        def travel(root, result):
            if root != None:
                travel(root.left, result)
                result.append(root.val)
                travel(root.right, result)

        ans = []
        travel(root, ans)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.inorderTraversal([1, 0, 2, 3]))
    print(obj.inorderTraversal([]))
    print(obj.inorderTraversal([1]))
