# 1483. Kth Ancestor of a Tree Node
from math import log2

"""
you are given a tree with 'n' nodes numbered from 0 to 'n - 1' in the form of
a parent array 'parent' where 'parent[i]' is the parent of the i'th node. the
root of the tree is node 0. find the k'th ancestor of a given node. the k'th
ancestor of a tree node is the k'th node in the path from that node to the
root node. implement the 'TreeAncestor' class.
"""


class TreeAncestor(object):
    def __init__(self, n, parent):
        """
        :type n: int
        :type parent: List[int]
        """
        m = int(log2(n)) + 1
        self.dp = [[-1] * m for _ in range(n)]
        for j in range(m):
            for i in range(n):
                if j == 0:
                    self.dp[i][0] = parent[i]
                elif self.dp[i][j - 1] != -1:
                    self.dp[i][j] = self.dp[self.dp[i][j - 1]][j - 1]

    def getKthAncestor(self, node, k):
        """
        :type node: int
        :type k: int
        :rtype: int
        """
        while k > 0 and node != -1:
            i = int(log2(k))
            node = self.dp[node][i]
            k -= 1 << i
        return node


if __name__ == "__main__":
    obj = TreeAncestor(n=7, parent=[-1, 0, 0, 1, 1, 2, 2])
    print(obj.getKthAncestor(node=3, k=1))
    print(obj.getKthAncestor(node=5, k=2))
    print(obj.getKthAncestor(node=6, k=3))
