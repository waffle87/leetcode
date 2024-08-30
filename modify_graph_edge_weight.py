# 2699. Modify Graph Edge Weights
from collections import defaultdict
import heapq

"""
you are given an undirected weighted connected graph containing 'n' nodes
labeled from '0' to 'n - 1' and an integer array 'edges' where 'edges[i] =
[ai, bi, wi]' indicates that there is an edge between nodes 'ai' and 'bi'
with weight 'wi'. some edges have a weight of -1 ('wi = -1'), while other
have a positive weight ('wi > 0'). your task is to modify all edges with a
weight of -1 by assigning them positive integer values in the range '[1, 2 *
10^9]' so that the shortest distance between the nodes 'source' and
'destination' becomes equal to an integer 'target'. if there are multiple
modifications that make the shortest distance equal to 'target', any of them
are considered correct. return an array containing all edges in any order if
it is possible to make the shortest to equal 'target', or an empty array if
it is not possible
"""


class Solution(object):
    def modifiedGraphEdges(self, n, edges, source, destination, target):
        """
        :type n: int
        :type edges: List[List[int]]
        :type source: int
        :type destination: int
        :type target: int
        :rtype: List[List[int]]
        """
        adj = [[] for _ in range(n)]
        for u, v, w in edges:
            adj[u].append([v, w])
            adj[v].append([u, w])

        def dijkstra(source, adj, skip_neg):
            pq = [[0, source]]
            dist = defaultdict(lambda: "inf")
            dist[source] = 0
            parent = {}
            while pq:
                d, node = heapq.heappop(pq)
                if d > dist[node]:
                    continue
                for nei, w in adj[node]:
                    if w == -1:
                        if skip_neg:
                            continue
                        w = 1
                    d2 = d + w
                    if d2 < dist[nei]:
                        dist[nei] = d2
                        parent[nei] = node
                        heapq.heappush(pq, [d2, nei])
            return dist, parent

        dist_r, parent_r = dijkstra(destination, adj, skip_neg=True)
        if dist_r.get(source, "inf") < target:
            return []
        dist, parent = dijkstra(source, adj, skip_neg=False)
        if dist[destination] > target:
            return []
        path = [destination]
        while path[-1] != source:
            path.append(parent[path[-1]])
        path = path[::-1]
        edges = {(min(u, v), max(u, v)): w for u, v, w in edges}
        walked = 0
        for u, v in zip(path, path[1:]):
            e = (min(u, v), max(u, v))
            if edges[e] == -1:
                edges[e] = max(target - dist_r.get(v, "inf") - walked, 1)
                if edges[e] > 1:
                    break
            walked += edges[e]
        for e, w in edges.items():
            if w == -1:
                edges[e] = 2 * (10**9)
        return [[u, v, w] for (u, v), w in edges.items()]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.modifiedGraphEdges(
            n=5,
            edges=[[4, 1, -1], [2, 0, -1], [0, 3, -1], [4, 3, -1]],
            source=0,
            destination=1,
            target=5,
        )
    )
    print(
        obj.modifiedGraphEdges(
            n=3, edges=[[0, 1, -1], [0, 2, 5]], source=0, destination=2, target=6
        )
    )
    print(
        obj.modifiedGraphEdges(
            n=4,
            edges=[[1, 0, 4], [1, 2, 3], [2, 3, 5], [0, 3, -1]],
            source=0,
            destination=2,
            target=6,
        )
    )
