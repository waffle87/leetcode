# 3882. Minimum XOR Path in a Grid

"""
you are given a 2d integer array 'grid' of size 'm x n'. you start at the
top-left cell '(0, 0)' and want to reach the bottom-right cell '(m - 1, n -
1)'. at each step, you may move either right or down. the cost of a path is
defined as the bitwise xor of all the values in the cells along that path,
including the start and end cells. return the minimum possible xor value
among all valid paths from '(0, 0)' to '(m - 1, n - 1)'.
"""


class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        dp = [{0}] + [set() for _ in range(len(grid[0]) - 1)]
        for row in grid:
            for i, j in enumerate(row):
                dp[i] = {k ^ j for k in dp[i] | (dp[i - 1] if i else set())}
        return min(dp[-1])


if __name__ == "__main__":
    obj = Solution()
    print(obj.minCost(grid=[[1, 2], [3, 4]]))
    print(obj.minCost(grid=[[6, 7], [5, 8]]))
    print(obj.minCost(grid=[[2, 7, 5]]))
