# 1145. Binary Tree Coloring Game

"""
two players play a turn based game on a binary tree. we are given the 'root'
of this binary tree, and the number of nodes 'n' in the tree. 'n' is odd and
each node has a distinct value from 1 to 'n'. initially the first player
names a value 'x' with '1 <= x <= n' and the second player names a value 'y'
with '1 <= y <= n' and 'y != x'. the first player colours the node with value
'x' red and the second player colours the node with value 'y' blue. then the
players take turns starting with the first player. in each turn that player
chooses a node of their colour and the colours an uncoloured neighbour of the
chose node.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def btreeGameWinningMove(self, root, n, x):
        """
        :type root: Optional[TreeNode]
        :type n: int
        :type x: int
        :rtype: bool
        """
        c = [0, 0]

        def cnt(node):
            if not node:
                return 0
            l, r = cnt(node.left), cnt(node.right)
            if node.val == x:
                c[0], c[1] = l, r
            return l + r + 1

        return cnt(root) / 2 < max(max(c), n - sum(c) - 1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.btreeGameWinningMove(root=[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11], n=11, x=3))
    print(obj.btreeGameWinningMove(root=[1, 2, 3], n=3, x=1))
