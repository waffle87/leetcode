# 48. Rotate Image
from typing import List

"""
you are given an 'n x n' 2d 'matrix' representing an image, rotate the image
by 90 degrees (clockwise). you have to rotate the image in place, meaning you
have to modify the input 2d matrix directly. do not allocate another 2d
matrix and do the rotation.
"""


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for i in range(n >> 1):
            for j in range(i, n - 1 - i):
                matrix[i][j], matrix[j][~i], matrix[~i][~j], matrix[~j][i] = (
                    matrix[~j][i],
                    matrix[i][j],
                    matrix[j][~i],
                    matrix[~i][~j],
                )


if __name__ == "__main__":
    obj = Solution()
    m1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    m2 = [[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]]
    obj.rotate(m1)
    obj.rotate(m2)
    print(m1)
    print(m2)
