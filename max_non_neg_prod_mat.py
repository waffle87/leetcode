# 1594. mximum Non Negative Product in a Matrix
from typing import List

"""
you are given an 'm x n' matrix 'grid'. initially, you are located at the top
left corner '(0, 0)' and in each step, you can only move right or down in the
matrix. among all possible paths starting from the top left corner and ending
in the bottom-right corner, find the path with the maximum non-negative
product. the product of a path is the product of all integers in the grid
cells visited along the path. return the maximum non-negative product. if the
maximum product is negative, return -1. notice that the modulo is performed
after getting the maximum product.
"""


class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        mod = 10**9 + 7
        mn = [[float("inf")] * n for _ in range(m)]
        mx = [[float("-inf")] * n for _ in range(m)]
        mn[0][0], mx[0][0] = grid[0][0], grid[0][0]
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                mn[i][j] = min(
                    mn[i - 1][j] * grid[i][j] if i > 0 else float("inf"),
                    mx[i - 1][j] * grid[i][j] if i > 0 else float("inf"),
                    mn[i][j - 1] * grid[i][j] if j > 0 else float("inf"),
                    mx[i][j - 1] * grid[i][j] if j > 0 else float("inf"),
                )
                mx[i][j] = max(
                    mn[i - 1][j] * grid[i][j] if i > 0 else float("-inf"),
                    mx[i - 1][j] * grid[i][j] if i > 0 else float("-inf"),
                    mn[i][j - 1] * grid[i][j] if j > 0 else float("-inf"),
                    mx[i][j - 1] * grid[i][j] if j > 0 else float("-inf"),
                )
        ans = mx[-1][-1]
        return ans % mod if ans >= 0 else -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxProductPath(grid=[[-1, -2, -3], [-2, -3, -3], [-3, -3, -2]]))
    print(obj.maxProductPath(grid=[[1, -2, 1], [1, -2, 1], [3, -4, 1]]))
    print(obj.maxProductPath(grid=[[1, 3], [0, -4]]))
