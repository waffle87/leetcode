# 1976. Number of Ways to Arrive at Destination
from collections import defaultdict
import heapq

"""
you are in a city that consists of 'n' intersections numbered from 0 to 'n -
1' with bi directional roads between some intersections. the inputs are
generated such that you can reach any intersection from any other
intersection and that there is at most one road between any two
intersections. you are given an integer 'n' and a 2d integer array 'roads'
where 'roads[i] = [u_i, v_i, t_i]' means that there is a road between
intersections 'u' and 'v' that takes 't' minutes to travel. you want to know
in how many ways you can travel from interseciton 0 to intersection 'n - 1'.
"""


class Solution(object):
    def countPaths(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """
        graph = defaultdict(list)
        for u, v, t in roads:
            graph[u].append([v, t])
            graph[v].append([u, t])

        def dijkstra(src):
            dist, ways = [float("inf")] * n, [0] * n
            pq = [(0, src)]
            ways[src] = 1
            dist[src] = 0
            while pq:
                d, u = heapq.heappop(pq)
                if dist[u] < d:
                    continue
                for v, t in graph[u]:
                    if dist[v] > d + t:
                        dist[v] = d + t
                        ways[v] = ways[u]
                        heapq.heappush(pq, (dist[v], v))
                    elif dist[v] == d + t:
                        ways[v] = (ways[v] + ways[u]) % (10**9 + 7)
            return ways[n - 1]

        return dijkstra(0)


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.countPaths(
            n=7,
            roads=[
                [0, 6, 7],
                [0, 1, 2],
                [1, 2, 3],
                [1, 3, 3],
                [6, 3, 3],
                [3, 5, 1],
                [6, 5, 1],
                [2, 5, 1],
                [0, 4, 5],
                [4, 6, 2],
            ],
        )
    )
    print(obj.countPaths(n=2, roads=[[1, 0, 10]]))
