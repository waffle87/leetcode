# 2577. Minimum Time to Visit a Cell In a Grid
import heapq

"""
you are given an 'm x n' matrix 'grid' consisting of non-negative integers
where 'grid[row][col]' represents the minimum time required to be able to
visit the cell '(row, col)', which means you can visit the cell '(row, col)'
only when the time you visit it is greater than or equal to the value. you
are standing in the top left cell of the matrix in the 0th second and you
must move to any adjacent cell in the four directions: up, down, left, and
right. each move you make takes 1 second. return the minimum time required in
which you can visit the bottom right cell of the matrix. if you cannot visit
the bottomright cell, then return -1.
"""


class Solution(object):
    def minimumTime(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
        m, n = len(grid), len(grid[0])
        vis, pq = set(), [(grid[0][0], 0, 0)]
        while pq:
            time, row, col = heapq.heappop(pq)
            if row == m - 1 and col == n - 1:
                return time
            if (row, col) in vis:
                continue
            vis.add((row, col))
            for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                r, c = row + dr, col + dc
                if 0 <= r < m and 0 <= c < n and (r, c) not in vis:
                    wait = 1 if ((grid[r][c] - time) % 2 == 0) else 0
                    heapq.heappush(pq, (max(time + 1, grid[r][c] + wait), r, c))


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumTime(grid=[[0, 1, 3, 2], [5, 1, 2, 5], [4, 3, 8, 6]]))
    print(obj.minimumTime(grid=[[0, 2, 4], [3, 2, 1], [1, 0, 4]]))
