# 1020. Number of Enclaves

"""
given an 'm  n' binary matrix grid, where 0 represents a sea
cell and 1 represents a land cell. a move consists of walking
from one land cell to another adjacent (4-directionally) land
cell o walking off the boundary of the 'grid'. return number
of land cells in 'grid' for which we cannot walk off the
boundary of the grid in any number of moves.
"""


class Solution(object):
    def numEnclaves(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        def dfs(i, j):
            grid[i][j] = 0
            for r, c in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                if 0 <= r < m and 0 <= c < n and grid[r][c]:
                    dfs(r, c)

        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1 and (i == 0 or j == 0 or i == m - 1 or j == n - 1):
                    dfs(i, j)
        return sum(sum(row) for row in grid)


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.numEnclaves(grid=[[0, 0, 0, 0], [1, 0, 1, 0], [0, 1, 1, 0], [0, 0, 0, 0]])
    )
    print(
        obj.numEnclaves(grid=[[0, 1, 1, 0], [0, 0, 1, 0], [0, 0, 1, 0], [0, 0, 0, 0]])
    )
