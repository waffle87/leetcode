# 2812. Find the Safest Path in a Grid
import heapq

"""
given a 0-indexed 2d matrix 'grid' of size 'n  n' where '(r, c)' represents
a cell containing a thief if 'grid[r][c] == 1', or an empty cell if
'grid[r][c] == 0'. you are initially positioned at cell '(0, 0)'. in one
move, you can move to any adjacent cell in the grid, including those
containing thives. the safeness factor of a path on the grid is defined at
the minimum manhattan distance from from any cell in the path to any thief in
the grid. return the maximum safeness factor of all paths leading to cell '(n
- 1, n - 1)'.
"""


class Solution(object):
    def maximumSafenessFactor(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        a = []
        depth, m, n = 0, len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    a.append([i, j])
        vis = [[0 for j in range(n)] for i in range(m)]
        dist = [[0 for j in range(n)] for i in range(m)]
        while a:
            b = []
            for i, j in a:
                if not vis[i][j]:
                    vis[i][j] = 1
                    dist[i][j] = depth
                    for x, y in [[i + 1, j], [i - 1, j], [i, j + 1], [i, j - 1]]:
                        if 0 <= x < m and 0 <= y < n:
                            b.append([x, y])
            a = b
            depth += 1
        vis = [[0 for j in range(n)] for i in range(m)]
        pq = [[-dist[0][0], 0, 0]]
        while pq:
            d, i, j = heapq.heappop(pq)
            if vis[i][j]:
                continue
            vis[i][j] = 1
            if i == m - 1 and j == n - 1:
                return -d
            for x, y in [[i + 1, j], [i - 1, j], [i, j + 1], [i, j - 1]]:
                if 0 <= x < m and 0 <= y < n:
                    heapq.heappush(pq, [-min(-d, dist[x][y]), x, y])
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumSafenessFactor(grid=[[1, 0, 0], [0, 0, 0], [0, 0, 1]]))
    print(obj.maximumSafenessFactor(grid=[[0, 0, 1], [0, 0, 0], [0, 0, 0]]))
    print(
        obj.maximumSafenessFactor(
            grid=[[0, 0, 0, 1], [0, 0, 0, 0], [0, 0, 0, 0], [1, 0, 0, 0]]
        )
    )
