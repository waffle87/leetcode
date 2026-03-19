# 3212. Count Submatrices With Equal Frequency of X and Y
from typing import List

"""
given a 2d character matrix 'grid' where 'grid[i][j]' is either "X", "Y", or
".", return the number of submatrices that contain 'grid[0][0]', an equal
frequency of 'X' and 'Y', and at least one 'X'.
"""


class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        n, ans = len(grid[0]), 0
        x, y = [0] * n, [0] * n
        for i in grid:
            rx, ry = 0, 0
            for j in range(n):
                rx += i[j] == "X"
                ry += i[j] == "Y"
                x[j] += rx
                y[j] += ry
                ans += (x[j] > 0) & (x[j] == y[j])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfSubmatrices(grid=[["X", "Y", "."], ["Y", ".", "."]]))
    print(obj.numberOfSubmatrices(grid=[["X", "X"], ["X", "Y"]]))
    print(obj.numberOfSubmatrices(grid=[[".", "."], [".", "."]]))
