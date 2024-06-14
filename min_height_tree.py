# 310. Minimum Height Trees

"""
a tree is an undirected graph in which any two vertices are connected by
exactly one path. in other words, any connected graph without simple cycles
is a tee. given a tree of 'n' nodes from 0 to 'n - 1' and an array of 'n - 1'
edges where 'edges[i] = [ai, bi]' indicates that there is an undirected edge
between the two nodes 'ai' and 'bi'in the the tree, you can choose any node
of the tree as the root. return a list of all mht's root labels. you can
return the answer in any order.
"""


class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        if n == 1:
            return [0]
        adj = [set() for _ in range(n)]
        for i, j in edges:
            adj[i].add(j)
            adj[j].add(i)
        leaves = [i for i in range(n) if len(adj[i]) == 1]
        while n > 2:
            n -= len(leaves)
            new_leaves = []
            for i in leaves:
                j = adj[i].pop()
                adj[j].remove(i)
                if len(adj[j]) == 1:
                    new_leaves.append(j)
            leaves = new_leaves
        return leaves


if __name__ == "__main__":
    obj = Solution()
    print(obj.findMinHeightTrees(n=4, edges=[[1, 0], [1, 2], [1, 3]]))
    print(obj.findMinHeightTrees(n=6, edges=[[3, 0], [3, 1], [3, 2], [3, 4], [5, 4]]))
