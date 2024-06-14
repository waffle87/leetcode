# 1289. Minimum Falling Path Sum II
from heapq import nsmallest

"""
given a 'n * n' integer matrix 'grid' return the minimum sum of a falling
path with non zero shifts. a falling path with non zero shifts is a choice of
exactly one element from each row of 'grid' such that no two elements chosen
in adjacent rows are in the same column
"""


class Solution(object):
    def minFallingPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        for i in range(1, len(grid)):
            r = nsmallest(2, grid[i - 1])
            for j in range(len(grid[0])):
                grid[i][j] += r[1] if grid[i - 1][j] == r[0] else r[0]
        return min(grid[-1])


if __name__ == "__main__":
    obj = Solution()
    print(obj.minFallingPathSum(grid=[[1, 2, 3], [4, 5, 6], [7, 8, 9]]))
    print(obj.minFallingPathSum(grid=[[7]]))
