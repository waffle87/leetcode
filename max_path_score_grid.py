# 3742. Maximum Path Score in a Grid
from typing import List

"""
you are given an 'm x n' grid where each cell contains one of the values 0,
1, or 2. you are also given an integer 'k'. you start from the top left
corner and want to reach the bottom right corner by moving on right or down.
each cell contributes a specific score and incurs an associated cost. return
the maximum score achievable without exciting a total cost of 'k' or -1 if no
valid path exists. note if you reach the last cell but the total cost exceeds
'k', the path is invalid.
"""


class Solution:
    def maxPathScore(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[[float("-inf")] * (k + 1) for _ in range(n)] for _ in range(m)]
        dp[0][0][0] = 0
        for i in range(m):
            for j in range(n):
                for c in range(k + 1):
                    if dp[i][j][c] == float("-inf"):
                        continue
                    if i + 1 < m:
                        val = grid[i + 1][j]
                        cost = 0 if val == 0 else 1
                        if c + cost <= k:
                            dp[i + 1][j][c + cost] = max(
                                dp[i + 1][j][c + cost], dp[i][j][c] + val
                            )
                    if j + 1 < n:
                        val = grid[i][j + 1]
                        cost = 0 if val == 0 else 1
                        if c + cost <= k:
                            dp[i][j + 1][c + cost] = max(
                                dp[i][j + 1][c + cost], dp[i][j][c] + val
                            )
        ans = max(dp[m - 1][n - 1])
        return -1 if ans < 0 else ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxPathScore(grid=[[0, 1], [2, 0]], k=1))
    print(obj.maxPathScore(grid=[[0, 1], [1, 2]], k=1))
