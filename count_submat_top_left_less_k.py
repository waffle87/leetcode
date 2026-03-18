# 3070. Count Submatrices with Top-Left Element and Sum Less Than k
from typing import List

"""
you are given a 0-index integer matrix 'grid' and an integer 'k'. return the
number of submatrices that contain the top-left element of the 'grid', and
have a sum less than or equal to 'k'.
"""


class Solution:
    def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
        m, n, ans = len(grid), len(grid[0]), 0
        for i in range(m):
            for j in range(n):
                if i > 0:
                    grid[i][j] += grid[i - 1][j]
                if j > 0:
                    grid[i][j] += grid[i][j - 1]
                if i > 0 and j > 0:
                    grid[i][j] -= grid[i - 1][j - 1]
                if grid[i][j] <= k:
                    ans += 1
                else:
                    break
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countSubmatrices(grid=[[7, 6, 3], [6, 6, 1]], k=18))
    print(obj.countSubmatrices(grid=[[7, 2, 9], [1, 5, 0], [2, 6, 6]], k=20))
