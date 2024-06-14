# 2642. Design Graph With Shortest Path Calculator

"""
there is a directed weighted graph that consists of 'n' nodes numbered from 0
to 'n - 1'. the edges of the graph are initially represented by the given
array 'edges' where 'edges[i] = [from[i], to[i], edge_cost[i]]' meaning that
there is an edge from 'from[i]' to 'to[i]' with the cost 'edge_cost[i]'.
"""


class Graph(object):
    def __init__(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        """
        self.N = n
        self.INF = 10**19
        adj_list = collections.defaultdict(list)
        for u, v, wt in edges:
            adj_list[u].append((v, wt))
        self.adj_list = adj_list

    def addEdge(self, edge):
        """
        :type edge: List[int]
        :rtype: None
        """
        self.adj_list[edge[0]].append((edge[1], edge[2]))

    def shortestPath(self, node1, node2):
        """
        :type node1: int
        :type node2: int
        :rtype: int
        """
        h = []
        heapq.heappush(h, (0, node1))
        dist = [self.INF] * self.N
        dist[node1] = 0
        while len(h):
            d, u = heapq.heappop(h)
            if u == node2:
                return d
            if dist[u] < d:
                continue
            for v, wt in self.adj_list[u]:
                if dist[v] > dist[u] + wt:
                    dist[v] = dist[u] + wt
                    heapq.heappush(h, (dist[v], v))
        return -1
