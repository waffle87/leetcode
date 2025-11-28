# 2872. Maximum Number of K-Divisible Components

"""
there is an undirected tree with 'n' nodes labeled from 0 to 'n - 1'. you are
given the integer 'n' and a 2d integer array 'edges' of length 'n - 1', where
'edges[i] = [a_i, b_i]' indicates that there is an edge between nodes 'a_i'
and 'b_i' in the tree. you are also given a 0-indexed integer array 'values'
of length 'n' where 'values[i]' is the value associated with the i'th node
and an integer 'k'. a valid split of the tree is obtained by removing any set
of edges, possibly empty, from the tree such that the resulting components
all have values thatare divisible by 'k', where the value of a connected
component is the sum of the values of its node. return the maximum number of
components in any valid split
"""


class Solution(object):
    def maxKDivisibleComponents(self, n, edges, values, k):
        """
        :type n: int
        :type edges: List[List[int]]
        :type values: List[int]
        :type k: int
        :rtype: int
        """
        adj, ans, m = [], 0, len(edges)
        for i in range(m + 1):
            adj.append([])
        for i in range(m):
            u, v = edges[i][0], edges[i][1]
            adj[u].append(v)
            adj[v].append(u)
        vis = [False for _ in range(n)]

        def dfs(node):
            nonlocal ans
            if vis[node]:
                return 0
            vis[node] = True
            s = values[node]
            for i in adj[node]:
                s += dfs(i)
            if s % k == 0:
                ans += 1
                return 0
            return s

        dfs(0)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxKDivisibleComponents(
            n=5, edges=[[0, 2], [1, 2], [1, 3], [2, 4]], values=[1, 8, 1, 4, 4], k=6
        )
    )
    print(
        obj.maxKDivisibleComponents(
            n=7,
            edges=[[0, 1], [0, 2], [1, 3], [1, 4], [2, 5], [2, 6]],
            values=[3, 0, 6, 1, 5, 2, 1],
            k=3,
        )
    )
