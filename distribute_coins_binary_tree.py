# 979. Distribute Coins in Binay Tree

"""
given the 'root' of a binary tree with 'n' nodes where each 'node' is the
tree that has 'node.val' coins. there are 'n' coins in total throughout the
whole tree. in one move, we may choose two adjacent nodes and move one coin
from one node to another. a move may be from parent to child, or from child
to parent. return the minimum number of moves required to make every node
have exactly one coin.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def distributeCoins(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        def dfs(node):
            if not node:
                return 0, 0
            (lbal, lcnt), (rbal, rcnt) = dfs(node.left), dfs(node.right)
            bal = node.val + lbal + rbal - 1
            return bal, lcnt + rcnt + abs(bal)

        return dfs(root)[1]
