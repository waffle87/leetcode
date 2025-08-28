# 3446. Sort Matrix by Diagonals
import heapq

"""
you are given an 'n x n' square matrix of integers 'grid'. return the matrix
such that the diagonals in the bottom left triangle including the middle are
sorted in non-increasing order. the diagonals in the top-right triangle are
sorted in non-decreasing order.
"""


class Solution(object):
    def sortMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        n, m = len(grid), len(grid[0])
        diags = {}
        for i in range(n):
            for j in range(m):
                key = i - j
                if key not in diags:
                    diags[key] = []
                if key < 0:
                    heapq.heappush(diags[key], grid[i][j])
                else:
                    heapq.heappush(diags[key], -grid[i][j])
        for i in range(n):
            for j in range(m):
                key = i - j
                if key < 0:
                    grid[i][j] = heapq.heappop(diags[key])
                else:
                    grid[i][j] = -heapq.heappop(diags[key])
        return grid


if __name__ == "__main__":
    obj = Solution()
    print(obj.sortMatrix(grid=[[1, 7, 3], [9, 8, 2], [4, 5, 6]]))
    print(obj.sortMatrix(grid=[[0, 1], [1, 2]]))
    print(obj.sortMatrix(grid=[[1]]))
