# 3651. Minimum Cost Path with Teleportations
from itertools import accumulate

"""
you are given an 'm x n' 2d integer array 'grid' and an integer 'k'. you
start at the top-left cell '(0, 0)' and your goal is to reach the
bottom-right cell '(m - 1, n - 1)'. there are two types of moves available:
normal move you can move righ or down from your current cell '(i, j)' ie. you
can move to '(i, j + 1)' (right) or '(i + 1, j)' (down). the cost is the
value of the destination cell. teleportation you can teleport from any cell
'(i, j)' to any cell '(x, y)' such that 'grid[x][y] <= grid[i][j]'; the cost
of ttotals move is 0. you may teleport at most 'k' times. return the minimum
total cost to reach cell (m - 1, n - 1) from '(0, 0)'.
"""


class Solution(object):
    def minCost(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        total = max([max(row) for row in grid])
        dp = None
        costs = [[0] * n for _ in range(m)]
        for x in range(k + 1):
            for i in range(m - 1, -1, -1):
                for j in range(n - 1, -1, -1):
                    costs[i][j] = float("inf")
                    if i == m - 1 and j == n - 1:
                        costs[i][j] = 0
                    else:
                        if i < m - 1:
                            s = costs[i + 1][j] + grid[i + 1][j]
                            if s < costs[i][j]:
                                costs[i][j] = s
                        if j < n - 1:
                            s = costs[i][j + 1] + grid[i][j + 1]
                            if s < costs[i][j]:
                                costs[i][j] = s
                        if x > 0 and dp[grid[i][j]] < costs[i][j]:
                            costs[i][j] = dp[grid[i][j]]
            dp = [float("inf")] * (total + 1)
            for i in range(m):
                for j in range(n):
                    if costs[i][j] < dp[grid[i][j]]:
                        dp[grid[i][j]] = costs[i][j]
            dp = list(accumulate(dp, min))
        return costs[0][0]


if __name__ == "__main__":
    obj = Solution()
    print(obj.minCost(grid=[[1, 3, 3], [2, 5, 4], [4, 3, 5]], k=2))
    print(obj.minCost(grid=[[1, 2], [2, 3], [3, 4]], k=1))
