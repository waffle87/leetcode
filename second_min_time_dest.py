# 2045. Second Minimum Time to Reach destination
from collections import defaultdict
import heapq
from math import ceil

"""
a city is represented as a bi directional connected graph with 'n' vertices
where each vertex is labeled from 1 to 'n' inclusively. the edges in the
graph are represented as a 2d integer array 'edges' where each 'edges[i] =
[ui, vi]' denotes a bi directional edge between vertex 'ui' and vertex 'vi'.
every vertex pair is connected by at most one edge, and no vertex has an edge
to itself. the time taken to traverse any edge is 'time' minutes. each vertex
has a traffic signal which changes its colour from green to red and vice
versa every 'change' minutes. all signals change at the same time. you can
entre a vertex at any time, but can leave a vertex only when the signal is
green. you cannot wait at a vertex if the signal is green.
"""


class Solution(object):
    def secondMinimum(self, n, edges, time, change):
        """
        :type n: int
        :type edges: List[List[int]]
        :type time: int
        :type change: int
        :rtype: int
        """
        d = [[] for _ in range(n + 1)]
        d[1] = [0]
        g, heap = defaultdict(list), [(0, 1)]
        for a, b in edges:
            g[a] += [b]
            g[b] += [a]
        while heap:
            min_dist, idx = heapq.heappop(heap)
            if idx == n and len(d[n]) == 2:
                return max(d[n])
            for neib in g[idx]:
                if (min_dist // change) % 2 == 0:
                    cand = min_dist + time
                else:
                    cand = ceil(min_dist / (2 * change)) * (2 * change) + time
                if not d[neib] or (len(d[neib]) == 1 and d[neib] != [cand]):
                    d[neib] += [cand]
                    heapq.heappush(heap, (cand, neib))


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.secondMinimum(
            n=5, edges=[[1, 2], [1, 3], [1, 4], [3, 4], [4, 5]], time=3, change=5
        )
    )
    print(obj.secondMinimum(n=2, edges=[[1, 2]], time=3, change=2))
