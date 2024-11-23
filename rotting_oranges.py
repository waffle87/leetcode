# 994. Rotting Oranges
from collections import deque

"""
you are given an 'm x n' 'grid' where each cell can have one of three values:
0 representing an empty cell, 1 representing a fresh orange, or 2
representing a rotten orange. every minute, any fresh orange that is
4-directionall adjacent to a rotten orange becomes rotten. return the minimum
number of minutethat must elapse until no cell has a fresh oragne. if this is
impossible, return -1
"""


class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rows = len(grid)
        if rows == 0:
            return -1
        cols, fresh_cnt, rotten = len(grid[0]), 0, deque()
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    rotten.append((r, c))
                elif grid[r][c] == 1:
                    fresh_cnt += 1
        min_pass = 0
        while rotten and fresh_cnt > 0:
            min_pass += 1
            for _ in range(len(rotten)):
                x, y = rotten.popleft()
                for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                    xx, yy = x + dx, y + dy
                    if xx < 0 or xx == rows or yy < 0 or yy == cols:
                        continue
                    if grid[xx][yy] == 0 or grid[xx][yy] == 2:
                        continue
                    fresh_cnt -= 1
                    grid[xx][yy] = 2
                    rotten.append((xx, yy))
        return min_pass if fresh_cnt == 0 else -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.orangesRotting(grid=[[2, 1, 1], [1, 1, 0], [0, 1, 1]]))
    print(obj.orangesRotting(grid=[[2, 1, 1], [0, 1, 1], [1, 0, 1]]))
    print(obj.orangesRotting(grid=[[0, 2]]))
