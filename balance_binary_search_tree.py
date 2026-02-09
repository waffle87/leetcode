# 1382. Balance a Binary Search Tree
from leetcode import treenode_build

"""
given the 'root' of a binary search tree, return a balance binary search tree
with the same node values. if there is more than one answer, return any of
them. a binary search tree is balance if the depth of the two subtrees of
every node never differs by more than 1.
"""


class Solution(object):
    def balanceBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """

        def inorder(node):
            return inorder(node.left) + [node.val] + inorder(node.right) if node else []

        def sorted_arr_bst(left, right):
            if left > right:
                return None
            mid = left + ((right - left) >> 1)
            root = TreeNode(vals[mid])
            root.left = sorted_arr_bst(left, mid - 1)
            root.right = sorted_arr_bst(mid + 1, right)
            return root

        vals = inorder(root)
        return sorted_arr_bst(0, len(vals) - 1)


if __name__ == "__main__":
    obj = Solution()
    r1 = treenode_build(vals=[1, None, 2, None, 3, None, 4, None, None])
    r2 = treenode_build(vals=[2, 1, 3])
    print(obj.balanceBST(r1))
    print(obj.balanceBST(r2))
