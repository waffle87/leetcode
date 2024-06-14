# 2373. Largest Local Values in a Matrix

"""
given an 'n  n' integer matrix grid. generate an integer matrix 'max_local'
of size '(n - 2)  (n - 2)' such that 'max_local[i][j]' is equal to the
largest value of the 3  3 matrix in 'grid' centred around row 'i + 1' and
column 'j + 1'. in other words, we want to find the largest value in every
contiguous 3  3 matrix in 'grid'. return the generated matrix.
"""


class Solution(object):
    def largestLocal(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(grid)
        ans = [[0] * (n - 2) for _ in range(n - 2)]
        for i in range(n - 2):
            for j in range(n - 2):
                ans[i][j] = max(
                    grid[ii][jj] for ii in range(i, i + 3) for jj in range(j, j + 3)
                )
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.largestLocal(grid=[[9, 9, 8, 1], [5, 6, 2, 6], [8, 2, 6, 4], [6, 2, 2, 2]])
    )
    print(
        obj.largestLocal(
            grid=[
                [1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1],
                [1, 1, 2, 1, 1],
                [1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1],
            ]
        )
    )
