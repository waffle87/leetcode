# 655. Print Binary Tree
from leetcode import treenode_build

"""
given the 'root' of a binary tree, construct a 0-indexed 'm x n' string
matrix 'res' that represents a formatted layout of the tree. the formatted
layout matrix should be constructed using the following rules. the height of
the tree is 'height' and the number of rows 'm' should be equal to 'height +
1'. the number of columns 'n' should be equal to '2^(height + 1) - 1'. place
the root node in the middle of the top row (more formally, at location
'res[0][(n - 1) / 2]'). continue this process until all the nodes in the tree
have been placed. any empty cells should contain the empty string "". return
the constructed matrix 'res'.
"""


class Solution(object):
    def printTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[str]]
        """

        def height(node):
            return 0 if not node else 1 + max(height(node.left), height(node.right))

        def build(node, row, left, right):
            if not node:
                return
            mid = (left + right) / 2
            self.grid[row][mid] = str(node.val)
            build(node.left, row + 1, left, mid - 1)
            build(node.right, row + 1, mid + 1, right)

        h = height(root)
        w = 2**h - 1
        self.grid = [[""] * w for i in range(h)]
        build(node=root, row=0, left=0, right=w - 1)
        return self.grid


if __name__ == "__main__":
    obj = Solution()
    r1 = treenode_build(vals=[1, 2])
    r2 = treenode_build(vals=[1, 2, 3, None, 4])
    print(obj.printTree(r1))
    print(obj.printTree(r2))
