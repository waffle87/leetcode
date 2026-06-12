# 3559. Number of Ways to Assign Edge Weights II

"""
there is an undirected tree with 'n' nodes labeled from 1 to 'n', rooted at
node 1. the tree is represented by a 2d integer array 'edges' of length 'n -
1', where 'edges[i] = [ui, vi]' indicates that there is an edge between nodes
'ui' and 'vi'. return an array 'answer' where 'answer[i]' is the number of
valid assignments for 'queries[i]'. since the answer may be very large, apply
modulo 10^9+7 to each 'answer[i]'.
"""


class Solution:
    def assignEdgeWeights(
        self, edges: List[List[int]], queries: List[List[int]]
    ) -> List[int]:
        n, mod = len(edges) + 1, 10**9 + 7
        adj = [[] for _ in range(n + 1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        depth = [0] * (n + 1)
        parent = [0] * (n + 1)
        vis = [0] * (n + 1)
        vis[1] = 1
        q = deque([1])
        while q:
            node = q.popleft()
            for neighbour in adj[node]:
                if not vis[neighbour]:
                    vis[neighbour] = 1
                    depth[neighbour] = depth[node] + 1
                    parent[neighbour] = node
                    q.append(neighbour)
        log = max(1, n.bit_length())
        up = [parent]
        for k in range(1, log):
            prev = up[-1]
            up.append([prev[prev[v]] for v in range(n + 1)])

        def lca(u, v):
            if depth[u] < depth[v]:
                u, v = v, u
            diff = depth[u] - depth[v]
            for k in range(log):
                if (diff >> k) & 1:
                    u = up[k][u]
            if u == v:
                return u
            for k in range(log - 1, -1, -1):
                if up[k][u] != up[k][v]:
                    u = up[k][u]
                    v = up[k][v]
            return up[0][u]

        pow2 = [1] * (n + 1)
        for i in range(1, n + 1):
            pow2[i] = pow2[i - 1] * 2 % mod
        ans = []
        for u, v in queries:
            k = depth[u] + depth[v] - 2 * depth[lca(u, v)]
            ans.append(pow2[k - 1] if k else 0)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.assignEdgeWeights(edges=[[1, 2]], queries=[[1, 1], [1, 2]]))
    print(
        obj.assignEdgeWeights(
            edges=[[1, 2], [1, 3], [3, 4], [3, 5]], queries=[[1, 4], [3, 4], [2, 5]]
        )
    )
