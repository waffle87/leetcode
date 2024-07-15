# 2196. Create Binary Tree From Descriptions
from collections import defaultdict

"""
you are given a 2d integer array 'descriptions' where 'descriptions[i] =
[parent_i, child_i, isleft_i]' indicates that 'parent_i' is the parent of
'child_i', in a binary tree of unique values. construct the binary tree
described by 'descriptions' and return its root. the test cases will be
generated such that the binary tree is valid.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def createBinaryTree(self, descriptions):
        """
        :type descriptions: List[List[int]]
        :rtype: Optional[TreeNode]
        """
        children = set()
        m = {}
        for p, c, l in descriptions:
            np = m.setdefault(p, TreeNode(p))
            nc = m.setdefault(c, TreeNode(c))
            if l:
                np.left = nc
            else:
                np.right = nc
            children.add(c)
        root = (set(m) - set(children)).pop()
        return m[root]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.createBinaryTree(
            descriptions=[
                [20, 15, 1],
                [20, 17, 0],
                [50, 20, 1],
                [50, 80, 0],
                [80, 19, 1],
            ]
        )
    )
    print(obj.createBinaryTree(descriptions=[[1, 2, 1], [2, 3, 0], [3, 4, 1]]))
