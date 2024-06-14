# 1584. Min Cost to Connect All Points
from collections import defaultdict
import heapq

"""
given a array 'points' representing integer coordinates of some points on a
2d-plane, where 'points[i] = [x[i], y[i]]'. the cost of connecting two points
'[x[i], y[i]]' and '[x[j], y[j]]' is the manhattan distance between them:
'|x[i], - x[j]| + |y[i] + y[j]|', where '|val|' denotes the absolute value of
'val'. return the minimum cost to make all points connected. all points are
connected if there is exactly one simple path betwen any two points.
"""


class Solution(object):
    def minCostConnectPoints(self, points):
        manhattan = lambda p1, p2: abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])
        n, c = len(points), defaultdict(list)
        for i in range(n):
            for j in range(i + 1, n):
                d = manhattan(points[i], points[j])
                c[i].append((d, j))
                c[j].append((d, i))
        cnt, ans, vis, heap = 1, 0, [0] * n, c[0]
        vis[0] = 1
        heapq.heapify(heap)
        while heap:
            d, j = heapq.heappop(heap)
            if not vis[j]:
                vis[j], cnt, ans = 1, cnt + 1, ans + d
                for record in c[j]:
                    heapq.heappush(heap, record)
            if cnt >= n:
                break
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.minCostConnectPoints([[0, 0], [2, 2], [3, 10], [5, 2], [7, 0]])
    )  # expect: 20
    print(obj.minCostConnectPoints([[3, 12], [-2, 5], [-4, 1]]))  # expect: 18
