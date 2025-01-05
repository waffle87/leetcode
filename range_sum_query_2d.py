# 304. Range Sum Query 2D - Immutable

"""
given a 2d matrix 'matrix', handle multiple queries of the following type:
calculate the sum of the elements of 'matrix' inside the rectangle defined by
its upper left corner '(row1, col1)' and lower right corer '(row2, col2)'.
you must design an algorithm where 'sumRegion' works on 'O(1)' time
complexity.
"""


class NumMatrix(object):
    def __init__(self, matrix):
        """
        :type matrix: List[List[int]]
        """
        m, n = len(matrix), len(matrix[0])
        self.sum = [[0] * (n + 1) for _ in range(m + 1)]
        for r in range(1, m + 1):
            for c in range(1, n + 1):
                self.sum[r][c] = (
                    self.sum[r - 1][c]
                    + self.sum[r][c - 1]
                    - self.sum[r - 1][c - 1]
                    + matrix[r - 1][c - 1]
                )

    def sumRegion(self, row1, col1, row2, col2):
        """
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        row1, col1, row2, col2 = (
            row1 + 1,
            col1 + 1,
            row2 + 1,
            col2 + 1,
        )
        return (
            self.sum[row2][col2]
            - self.sum[row2][col1 - 1]
            - self.sum[row1 - 1][col2]
            + self.sum[row1 - 1][col1 - 1]
        )


if __name__ == "__main__":
    obj = NumMatrix(
        [
            [3, 0, 1, 4, 2],
            [5, 6, 3, 2, 1],
            [1, 2, 0, 1, 5],
            [4, 1, 0, 1, 7],
            [1, 0, 3, 0, 5],
        ]
    )
    print(obj.sumRegion(2, 1, 4, 3))
    print(obj.sumRegion(1, 1, 2, 2))
    print(obj.sumRegion(1, 2, 2, 4))
