# 1110. Delete Nodes And Return Forest

"""
given the 'root' of a binary tree, each node in the tree has a distinct
value. after deleting all nodes with a value in 'to_delete', we are left with
a forest (a disjoint union of trees). return the roots of the trees in the
remaining forest. you may return the result in any order.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def delNodes(self, root, to_delete):
        """
        :type root: TreeNode
        :type to_delete: List[int]
        :rtype: List[TreeNode]
        """
        sel_del, ans = set(to_delete), []

        def helper(root, is_root):
            if not root:
                return None
            root_del = root.val in sel_del
            if is_root and not root_del:
                ans.append(root)
            root.left = helper(root.left, root_del)
            root.right = helper(root.right, root_del)
            return None if root_del else root

        helper(root, True)
        return ans
