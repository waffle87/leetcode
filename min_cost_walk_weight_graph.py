# 3108. Minimum Cost Walk in Weighted Graph

"""
there is an undirected weighted graph with 'n' vertices labeled from 0 to 'n
- 1'. you are given the integer 'n' and an array 'edges', where 'edges[i] =
[u_i, v_i, w_i]' indicates that there is an edge between vertices 'u_i' and
'v_i' with a weight of 'w_i'. a walk on the graph is a sequence of vertices
and edges. the walk starts and ends with a vertex, and each edge connects the
vertex that comes before it and the vertex that comes after it. it's
important to note that a walk may visit the same edge or vertex more than
once. return the array 'answer' where 'answer[i]' denotes the minimum cost of
a walk for query 'i'.
"""


class UnionFind:
    def __init__(self, size):
        self.parent = [i for i in range(size)]
        self.rank = [0 for _ in range(size)]
        self.d = [~0 for _ in range(size)]

    def find(self, node):
        if self.parent[node] != node:
            self.parent[node] = self.find(self.parent[node])
        return self.parent[node]

    def union(self, a, b, val):
        p1, p2 = self.find(a), self.find(b)
        if self.rank[p1] > self.rank[p2]:
            self.parent[p2] = p1
            self.d[p1] &= self.d[p2] & val
        elif self.rank[p1] < self.rank[p2]:
            self.parent[p1] = p2
            self.d[p2] &= self.d[p1] & val
        else:
            self.parent[p1] = p2
            self.d[p2] &= self.d[p1] & val
            self.rank[p2] += 1


class Solution(object):
    def minimumCost(self, n, edges, query):
        """
        :type n: int
        :type edges: List[List[int]]
        :type query: List[List[int]]
        :rtype: List[int]
        """
        uf = UnionFind(n)
        for u, v, w in edges:
            uf.union(u, v, w)
        ans = []
        for u, v in query:
            if uf.find(u) != uf.find(v):
                ans.append(-1)
            else:
                ans.append(uf.d[uf.find(u)])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.minimumCost(
            n=5, edges=[[0, 1, 7], [1, 3, 7], [1, 2, 1]], query=[[0, 3], [3, 4]]
        )
    )
    print(
        obj.minimumCost(
            n=3, edges=[[0, 2, 7], [0, 1, 15], [1, 2, 6], [1, 2, 1]], query=[[1, 2]]
        )
    )
