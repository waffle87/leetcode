# 3546. Equal Sum Grid Partition I
from typing import List

"""
you are given an 'm x n' matrix 'grid' of positive integers. your task is to
determine if it is possible to make either one horizontal or one vertical cut
on the grid such that each of the two resulting sections formed by the cut is
non-empty and the sum of the elements in both sections is equal. return
'true' if such partition exists, otherwise return 'false'.
"""


class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        total = sum(sum(row) for row in grid)
        if total % 2:
            return False
        target, s = total // 2, 0
        for i in range(m - 1):
            s += sum(grid[i])
            if s == target:
                return True
        s = 0
        for j in range(n - 1):
            for i in range(m):
                s += grid[i][j]
            if s == target:
                return True
        return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.canPartitionGrid(grid=[[1, 4], [2, 3]]))
    print(obj.canPartitionGrid(grid=[[1, 3], [2, 4]]))
