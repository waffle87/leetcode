# 3558. Number of Ways to Assign Edge Weights I

"""
there is an undirected tree with 'n' nodes labeed from 1 to 'n', rooted at
node 1. the tree is represented by a 2d integer array 'edges' of length 'n -
1' where 'edges[i] = [ui, vi]' indicates that there is an edge between nodes
'ui' and 'vi'. initially, all edges have a weight of 0. you must assign each
edge a weight of either 1 or 2. the cost of a path between any two nodes 'u'
and 'v' is the total weight of all edges in the path connecting them. select
any one node 'x'at the maximum depth. return the number of ways to assign
edge weights in the path from node 1 to 'x' such that its total cost is odd.
since the answer may be large, return it modulo 10^9 + 7. note: ignore all
"""


class Solution:
    def assignEdgeWeights(self, edges: List[List[int]]) -> int:
        depth = {1: 1}
        max_depth = 0
        for u, v in sorted((min(u, v), max(u, v)) for u, v in edges):
            depth[v] = depth[u] + 1
            max_depth = max(max_depth, depth[v])
        return (2 ** (max_depth - 2)) % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    print(obj.assignEdgeWeights(edges=[[1, 2]]))
    print(obj.assignEdgeWeights(edges=[[1, 2], [1, 3], [3, 4], [3, 5]]))
