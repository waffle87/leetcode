# 3548. Equal Sum Grid Partition II
from typing import List

"""
you are given an 'm x n' matrix 'grid' of positive integers. your task is to
determine if it is possible to make either one horizontal or one vertical cut
on the grid such that each of the two resulting sections formed by the cut is
non-empty, the sum of the elements in both sections is equal or can be made
equal by discounting at most one single cell in total, and if a cell is
discounted, the rest of the section must remain connected. return 'true' if
such a partition exists, otherwise return false.
"""


class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        total = 0
        for i in range(m):
            for j in range(n):
                total += grid[i][j]
        for _ in range(4):
            exist = set()
            exist.add(0)
            sum_val = 0
            m = len(grid)
            n = len(grid[0])
            if m < 2:
                grid = self.rotation(grid)
                continue
            if n == 1:
                for i in range(m - 1):
                    sum_val += grid[i][0]
                    tag = sum_val * 2 - total
                    if tag == 0 or tag == grid[0][0] or tag == grid[i][0]:
                        return True
                grid = self.rotation(grid)
                continue
            for i in range(m - 1):
                for j in range(n):
                    exist.add(grid[i][j])
                    sum_val += grid[i][j]
                tag = sum_val * 2 - total
                if i == 0:
                    if tag == 0 or tag == grid[0][0] or tag == grid[0][n - 1]:
                        return True
                    continue
                if tag in exist:
                    return True
            grid = self.rotation(grid)
        return False

    def rotation(self, grid: List[List[int]]) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        tmp = [[0] * m for _ in range(n)]
        for i in range(m):
            for j in range(n):
                tmp[j][m - 1 - i] = grid[i][j]
        return tmp


if __name__ == "__main__":
    obj = Solution()
    print(obj.canPartitionGrid(grid=[[1, 4], [2, 3]]))
    print(obj.canPartitionGrid(grid=[[1, 2], [3, 4]]))
    print(obj.canPartitionGrid(grid=[[1, 2, 4], [2, 3, 5]]))
    print(obj.canPartitionGrid(grid=[[4, 1, 8], [3, 2, 6]]))
