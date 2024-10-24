# 951. Flip Equivalent Binary Trees

"""
for a binarytree T, we can define a flip operation as follows: choose any
node, and swap the left and right child subtrees. a binary tree X is flip
equivalent to a binary tree Y if and only if we can make X equal to Y after
some number of flip operations. given the roots of two binary trees 'root1'
and 'root2', return 'true' if the two trees are flip equivalent.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def flipEquiv(self, root1, root2):
        """
        :type root1: Optional[TreeNode]
        :type root2: Optional[TreeNode]
        :rtype: bool
        """
        s1, s2 = [root1], [root2]
        while s1 and s2:
            n1, n2 = s1.pop(), s2.pop()
            if n1 is None or n2 is None:
                continue
            elif not n1 or not n1 or n1.val != n2.val:
                return False
            if (
                n1.left is None
                or n2.left is None
                or n1.left
                and n2.left
                and n1.left.val == n2.left.val
            ):
                s1.extend([n1.left, n1.right])
            else:
                s1.extend([n1.right, n1.left])
            s2.extend([n2.left, n2.right])
        return not s1 and not s2


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.flipEquiv(
            root1=[1, 2, 3, 4, 5, 6, None, None, None, 7, 8],
            root2=[1, 3, 2, None, 6, 4, 5, None, None, None, None, 8, 7],
        )
    )
    print(obj.flipEquiv(root1=[], root2=[]))
    print(obj.flipEquiv(root1=[], root2=[1]))
