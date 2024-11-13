# 2088. Count Fertile Pyramids in a Land
from itertools import product

"""
a farmer has a rectangular grid of land with 'm' rows and 'n' columns that
can be divided into unit cells. each cell is either fertile (represented by a
1) or barren (represented by a 0). all cells outside the grid are considered
barren. a pyamidal plot of land can be defined as a set of cells with the
following criteria: the number of cells in the set has to be greater than 1
and all cells must be fertile, and the apex of the pyramid is the topmost
cell of the pyramid. the height of a pyramid is the number of rows it covers.
let '(r, c)' be the apex of the pyramid and its height be 'h'. given a
0-indexed 'm x n' binary matrix 'grid' representing the farmland, return the
total number of pyramidal and inverse pyramidal plots that can be found in
'grid'.
"""


class Solution(object):
    def countPyramids(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n, ans = len(grid), len(grid[0]), 0

        def dp(i, j, dir):
            if (
                grid[i][j] == 1
                and 0 <= i + dir < m
                and j > 0
                and j + 1 < n
                and grid[i + dir][j] == 1
            ):
                return min(dp(i + dir, j - 1, dir), dp(i + dir, j + 1, dir)) + 1
            return grid[i][j]

        for i, j in product(range(m), range(n)):
            ans += max(0, dp(i, j, 1) - 1)
            ans += max(0, dp(i, j, -1) - 1)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countPyramids(grid=[[0, 1, 1, 0], [1, 1, 1, 1]]))
    print(obj.countPyramids(grid=[[1, 1, 1], [1, 1, 1]]))
    print(
        obj.countPyramids(
            grid=[[1, 1, 1, 1, 0], [1, 1, 1, 1, 1], [1, 1, 1, 1, 1], [0, 1, 0, 0, 1]]
        )
    )
