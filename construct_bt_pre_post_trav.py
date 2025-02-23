# 889. Construct Binary Tree from Preorder and Postorder Traversal
from leetcode import TreeNode


"""
given two integer array, 'preorder' and 'postorder' where 'preorder' is the
preorder traversal of a binary tree of distinct values and 'postorder' is the
postorder traversal of the same tree, reconstruct and return the binary tree.
if there exists multiple answers, you can return any of  them.
"""


class Solution(object):
    def constructFromPrePost(self, preorder, postorder):
        """
        :type preorder: List[int]
        :type postorder: List[int]
        :rtype: Optional[TreeNode]
        """
        stack, j = [TreeNode(preorder[0])], 0
        for i in preorder[1:]:
            node = TreeNode(i)
            while stack[-1].val == postorder[j]:
                stack.pop()
                j += 1
            if not stack[-1].left:
                stack[-1].left = node
            else:
                stack[-1].right = node
            stack.append(node)
        return stack[0]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.constructFromPrePost(
            preorder=[1, 2, 4, 5, 3, 6, 7], postorder=[4, 5, 2, 6, 7, 3, 1]
        )
    )
    print(obj.constructFromPrePost(preorder=[1], postorder=[1]))
