# 2503. Maximum Number of Points From Grid Queries
import heapq
from bisect import bisect_left

"""
you are given an 'm x n' integer matrix 'grid' and an array 'queries' of size
'k'. find an array 'answer' of size 'k' such that for each integer
'queries[i]' start in the top left cell of the matrix and repeat the
following process: if 'queries[i]' is strictly greater than the value of the
current cell that you are in, then you get one point if it is your first time
visiting that cell, and you can move to any adjacent cell in all 4
directions, otherwise you do not get any points, and you end this process.
after the process 'answer[i]' is the maximum number of ponts you can get.
note that for each query, yu are allowed to visit the same cell multiple
times.
"""


class Solution(object):
    def maxPoints(self, grid, queries):
        """
        :type grid: List[List[int]]
        :type queries: List[int]
        :rtype: List[int]
        """
        n, m = len(grid), len(grid[0])
        heap = [(grid[0][0], 0, 0)]
        v, order = {(0, 0)}, []
        while len(heap) > 0:
            curr, i, j = heapq.heappop(heap)
            order.append(curr)
            for x, y in [(i - 1, j), (i, j - 1), (i + 1, j), (i, j + 1)]:
                if 0 <= x < n and 0 <= y < m and (x, y) not in v:
                    v.add((x, y))
                    heapq.heappush(heap, (grid[x][y], x, y))
        high = -1
        for i in range(len(order)):
            high = max(high, order[i])
            order[i] = high
        ans = []
        for i in queries:
            ans.append(bisect_left(order, i))
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxPoints(grid=[[1, 2, 3], [2, 5, 7], [3, 5, 1]], queries=[5, 6, 2]))
    print(obj.maxPoints(grid=[[5, 2, 1], [1, 1, 2]], queries=[3]))
