# 3567. Minimum Absolute Difference in Sliding Submatrix
from bisect import bisect_left, insort
from typing import List

"""
you are given an 'm x n' integer matrix 'grid' and an integer 'k'. for every
two contiguous 'k x k' submatrix of 'grid', compute the minimum absolute
difference between any two distinct values within that submatrix. return a 2d
array 'ans' of size '(m - k + 1) x (n - k + 1)' where 'ans[i][j]' is the
minimum absolute difference in the submatrix whose top-left corner is '(i,
j)' in 'grid'. note: if all elements in the submatrix have the same value,
the answer will be 0. a submatrix '(x1, y1, x2, y2)' is a matrix that is
formed by choosing all cells 'matrix[x][y]' where 'x1 <= x <= x2' and 'y1 <=
y <= y2'.
"""


class Solution:
    def compute_diff(self, dp):
        if len(dp) < 2:
            return 0
        min_diff = float("inf")
        for i in range(len(dp) - 1):
            diff = dp[i + 1] - dp[i]
            if diff > 0 and diff < min_diff:
                min_diff = diff
        return min_diff if min_diff != float("inf") else 0

    def minAbsDiff(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        ans = [[0] * (n - k + 1) for _ in range(m - k + 1)]
        for r in range(m - k + 1):
            dp = []
            for i in range(k):
                for j in range(k):
                    insort(dp, grid[r + i][j])
            ans[r][0] = self.compute_diff(dp)
            for c in range(1, n - k + 1):
                for i in range(k):
                    remove = grid[r + i][c - 1]
                    idx = bisect_left(dp, remove)
                    dp.pop(idx)
                for i in range(k):
                    add = grid[r + i][c + k - 1]
                    insort(dp, add)
                ans[r][c] = self.compute_diff(dp)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minAbsDiff(grid=[[1, 8], [3, -2]], k=2))
    print(obj.minAbsDiff(grid=[[3, -1]], k=1))
    print(obj.minAbsDiff(grid=[[1, -2, 3], [2, 3, 5]], k=2))
