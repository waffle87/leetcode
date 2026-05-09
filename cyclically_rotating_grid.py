# 1914. Cyclically Rotating a Grid
from typing import List

"""
you are given an 'm x n' integer matrix 'grid', where 'm' and 'n' are both
even integers, and an integer 'k'. the matrix is composed of several layers.
a cyclic rotation of the matrix is done by rotating each layer once, each
element in the layer will take the place of the adjacent element in the
counter-clocwise direction. return the matrix after applying 'k' cyclic
rotations to it.
"""


class Solution:
    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        top = [x for x in grid[0]]
        right = [row[-1] for row in grid[1:-1]]
        bottom = [x for x in grid[-1]][::-1]
        left = [row[0] for row in grid[1:-1]][::-1]
        sequence = top + right + bottom + left
        stripped = [[x for x in row[1:-1]] for row in grid[1:-1]]
        rotate = k % len(sequence)
        rearranged = sequence[rotate:] + sequence[:rotate]
        if stripped != [] and stripped[0] != []:
            stripped = self.rotateGrid(stripped, k)
        top = rearranged[:n]
        right = rearranged[n : n + m - 2]
        bottom = rearranged[n + m - 2 : n + m - 2 + n][::-1]
        left = rearranged[n + m - 2 + n :][::-1]
        grid = [[a] + b + [c] for a, b, c in zip(left, stripped, right)]
        grid = [top] + grid + [bottom]
        return grid


if __name__ == "__main__":
    obj = Solution()
    print(obj.rotateGrid(grid=[[40, 10], [30, 20]], k=1))
    print(
        obj.rotateGrid(
            grid=[[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]], k=2
        )
    )
