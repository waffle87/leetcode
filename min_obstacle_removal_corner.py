# 2290. Minimum Obstacle Removal to Reach Corner
from collections import deque

"""
you are given a 0-indexed 2d integer array 'grid' of size 'm x n'. each cell
has one of two values: 0 represents an empty cell, and 1 rperesents an
obstacle that may be removed. you can move up, down, left, or right from and
to an empty cell. return the minimum number of obstacles to remove so you can
move from the upper left corner ('0, 0') to the lower right corner ('m -1, n
- 1').
"""


class Solution(object):
    def minimumObstacles(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = map(len, (grid, grid[0]))
        dist = [[float("inf")] * n for _ in range(m)]
        dist[0][0] = 0
        dq = deque([(0, 0, 0)])
        while dq:
            o, r, c = dq.popleft()
            for i, j in (r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1):
                if m > i >= 0 <= j < n and dist[i][j] == float("inf"):
                    if grid[i][j] == 1:
                        dist[i][j] = o + 1
                        dq.append((o + 1, i, j))
                    else:
                        dist[i][j] = o
                        dq.append((o, i, j))
        return dist[-1][-1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumObstacles(grid=[[0, 1, 1], [1, 1, 0], [1, 1, 0]]))
    print(
        obj.minimumObstacles(grid=[[0, 1, 0, 0, 0], [0, 1, 0, 1, 0], [0, 0, 0, 1, 0]])
    )
