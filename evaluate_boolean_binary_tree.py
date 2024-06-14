# 2331. Evaluate Boolean Binary Tree

"""
given the 'root' of a full binary tree with the following properties. leaf
nodes have either the value 0 or 1, where 0 represents false and 1 represents
true. non leaf nodes have either the value 2 or 3, where 2 represents the
boolean or, and 3 represents the boolean and. the evaluation of a node is as
follows. if the node is a leaf node, the evaluation is the value of the node,
ie. true or false. otherwise, evaluate the node's two children and apply the
boolean operation of its value with the children's evaluations. return the
boolean result of evaulating the 'root' node. a full binary tree is a binary
tree where each node has either 0 or 2 children. a leaf node is a node that
has zero children.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def evaluateTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        if root.val == 0 or root.val == 1:
            return root.val
        if root.val == 2:
            return self.evaluateTree(root.left) or self.evaluateTree(root.right)
        if root.val == 3:
            return self.evaluateTree(root.left) and self.evaluateTree(root.right)
