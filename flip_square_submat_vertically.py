# 3643. Flip Square Submatrix Vertically
from typing import List

"""
you are given an 'm x n' integer matrix 'grid', and three integers 'x', 'y',
and 'k'. the integers 'x' and 'y' represent the row and column indices of the
top elft corner of a square submatrix and the integer 'k' represents the size
(side length) of the square submatrix. your task is to flip the submatrix by
reversing the order of its rows vertically. return the updated matrix.
"""


class Solution:
    def reverseSubmatrix(
        self, grid: List[List[int]], x: int, y: int, k: int
    ) -> List[List[int]]:
        for i in range(k >> 1):
            r1, r2 = grid[x + i], grid[x + k - 1 - i]
            for j in range(k):
                r1[y + j], r2[y + j] = r2[y + j], r1[y + j]
        return grid


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.reverseSubmatrix(
            grid=[[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]],
            x=1,
            y=0,
            k=3,
        )
    )
    print(obj.reverseSubmatrix(grid=[[3, 4, 2, 3], [2, 3, 4, 2]], x=0, y=2, k=2))
