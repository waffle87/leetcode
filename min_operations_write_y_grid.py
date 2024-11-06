# 3071. Minimum Operations to Write the Letter Y on a Grid
from collections import Counter
from itertools import chain

"""
you are given a 0-indexed 'n x n' grid where 'n' is odd, and 'grid[r][c]' is
0, 1, or 2. we say that a cell belongs to the letter y if it belongs to one
of the following: the diagonal starting at the top-left cell and ending at
the center cell of the grid, the diagonal starting at the top-right cell nd
ending at the center cell of the grid, or the vertical line starting at the
center cell and ending at the bottom border of the grid. return the minimum
number of operations needed to write the letter y on the grid given that in
one operation you can change the value at cell to 0, 1, or 2.
"""


class Solution(object):
    def minimumOperationsToWriteY(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n1 = len(grid)
        n2 = n1 // 2
        y = ((grid[i][i], grid[n1 - i - 1][n2], grid[i][n1 - i - 1]) for i in range(n2))
        cnt1 = Counter(chain(*grid))
        cnt1[grid[n2][n2]] += 1
        cnt2 = Counter(chain(*grid)) - cnt1
        return n1 * n1 - max(
            cnt1[0] + cnt2[1],
            cnt1[1] + cnt2[0],
            cnt1[0] + cnt2[2],
            cnt1[2] + cnt2[0],
            cnt1[1] + cnt2[2],
            cnt1[2] + cnt2[1],
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumOperationsToWriteY(grid=[[1, 2, 2], [1, 1, 0], [0, 1, 0]]))
    print(
        obj.minimumOperationsToWriteY(
            grid=[
                [0, 1, 0, 1, 0],
                [2, 1, 0, 1, 2],
                [2, 2, 2, 0, 1],
                [2, 2, 2, 2, 2],
                [2, 1, 2, 2, 2],
            ]
        )
    )
