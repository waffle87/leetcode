# 1391. Check if There is a Valid Path in a Grid
from typing import List

"""
you are given an 'm x n' 'grid'. each cell of 'grid' represents a street. the
street of 'grid[i][j]' can be 1 .. 6, connecting to a left/upper/right cell
and the right/lower/upper cell. you will initially start at the street of the
upper left cell '(0, 0)'. a valid path in the grid is the path that starts
from the upper left cell '(0, 0)' and ends at the bottom right cell '(m - 1,
n - 1)'. the path should only follow the streets. notice that you are not
allowed to change any street. return true if there is a valid path in the
grid or 'false' otherwise.
"""


class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        if not grid:
            return true
        directions = {
            1: [(0, -1), (0, 1)],
            2: [(-1, 0), (1, 0)],
            3: [(0, -1), (1, 0)],
            4: [(0, 1), (1, 0)],
            5: [(0, -1), (-1, 0)],
            6: [(0, 1), (-1, 0)],
        }
        vis = set()
        goal = (len(grid) - 1, len(grid[0]) - 1)

        def dfs(i, j):
            vis.add((i, j))
            if (i, j) == goal:
                return True
            for d in directions[grid[i][j]]:
                ni, nj = i + d[0], j + d[1]
                if (
                    0 <= ni < len(grid)
                    and 0 <= nj < len(grid[0])
                    and (ni, nj) not in vis
                    and (-d[0], -d[1]) in directions[grid[ni][nj]]
                ):
                    if dfs(ni, nj):
                        return True
            return False

        return dfs(0, 0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.hasValidPath(grid=[[2, 4, 3], [6, 5, 2]]))
    print(obj.hasValidPath(grid=[[1, 2, 1], [1, 2, 1]]))
    print(obj.hasValidPath(grid=[[1, 1, 2]]))
