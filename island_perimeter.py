# 463. Island Perimeter

"""
given  a 'row  col' grid representing a map where 'grid[i][j] = 1'
represents land and 'grid[i][j] = 0' represents water. grid cells are
connected horizontally/vertically (not diagonally). the 'gird' is completely
surrounded by water, and there is exactly one island. the island does not
have lakes meaning the water inside is not connected to the water around the
island. one cell is a square with side length 1. the grid is rectangular
width and height don't exceed 100. determine the perimeter of the island.
"""


class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n, ans = len(grid), len(grid[0]), 0
        for i in range(m):
            for j in range(n):
                ans += 4 * grid[i][j]
                if i > 0:
                    ans -= grid[i][j] * grid[i - 1][j]
                if i < m - 1:
                    ans -= grid[i][j] * grid[i + 1][j]
                if j > 0:
                    ans -= grid[i][j] * grid[i][j - 1]
                if j < n - 1:
                    ans -= grid[i][j] * grid[i][j + 1]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.islandPerimeter(
            grid=[[0, 1, 0, 0], [1, 1, 1, 0], [0, 1, 0, 0], [1, 1, 0, 0]]
        )
    )
    print(obj.islandPerimeter(grid=[[1]]))
    print(obj.islandPerimeter(grid=[[1, 0]]))
