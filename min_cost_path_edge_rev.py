# 3650. Minimum Cost Path with Edge Reversals
import heapq

"""
you are given a directed, weighted graph with 'n' nodes labeled from 0 to 'n
- 1', and an array 'edges' where 'edges[i] =[ui, vi, wi]' represents a
directed edge from node 'ui' to node 'vi' with cost 'wi'. each node 'ui' has
a switch that can be used at most once: when you arrive at 'ui' and have not
yet its switch, you may activate it on one of its incoming edges 'vi -> ui'
reverse that edge to 'ui -> vi' and immediately traverse it. the reversal is
only valid for that single move, and using a reversed edge costs '2 * wi'.
return the minimum cost to travel from node 0 to node 'n - 1'. if it is not
possible, return -1.
"""


class Solution(object):
    def dijkstra(self, n):
        inf = float("inf")
        vis = [False] * n
        dist = [inf] * n
        pq = [(0, 0)]
        dist[0] = 0
        while pq:
            du, u = heapq.heappop(pq)
            if vis[u]:
                continue
            vis[u] = True
            for v, w in self.g[u]:
                nd = du + w
                if nd < dist[v]:
                    dist[v] = nd
                    heapq.heappush(pq, (nd, v))
        return -1 if dist[n - 1] == inf else dist[n - 1]

    def minCost(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        self.g = [[] for _ in range(n)]
        for u, v, w in edges:
            self.g[u].append((v, w))
            self.g[v].append((u, w * 2))
        return self.dijkstra(n)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minCost(n=4, edges=[[0, 1, 3], [3, 1, 1], [2, 3, 4], [0, 2, 2]]))
    print(obj.minCost(n=4, edges=[[0, 2, 1], [2, 1, 1], [1, 3, 1], [2, 3, 3]]))
