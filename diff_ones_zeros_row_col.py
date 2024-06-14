# 2482. Difference Between Ones and Zeros in Row and Column

"""
given a 0-indexed 'm  n' binary matrix 'grid', where the difference matrix
'diff' is created with the following procedure: let the number of ones in
i'th row be 'ones_row[i]', let the number of ones in the j'th column be
'ones_col[j]', let the number of zeros in the i'th row be 'zeros_row[i]', let
the number of zeros in the j'th column be 'zeros_col[j]'. 'diff[i][j] =
ones_row[i] + ones_col[j] - zeros_row[i] - zeros_col[j]'. return the
difference matrix 'diff'
"""


class Solution(object):
    def onesMinusZeros(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        m, n = len(grid), len(grid[0])
        row_one = [0] * m
        col_one = [0] * n
        for i in range(m):
            for j in range(n):
                row_one[i] += grid[i][j]
                col_one[j] += grid[i][j]
        for i in range(m):
            for j in range(n):
                grid[i][j] = 2 * (row_one[i] + col_one[j]) - m - n
        return grid


if __name__ == "__main__":
    obj = Solution()
    print(obj.onesMinusZeros(grid=[[0, 1, 1], [1, 0, 1], [0, 0, 1]]))
    print(obj.onesMinusZeros(grid=[[1, 1, 1], [1, 1, 1]]))
