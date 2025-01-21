# 2132. Stamping the Grid
from itertools import product

"""
you are given an 'm x n' binary matrix 'grid' where each cell is either 0 or
1 (empty or occupied, respectively). you are then given stamps of size
'stampHeight x stampWidth'. we want to fit the stamps such that they follow
the given restrictions and requirements: cover all the empty cells, do not
cover any of the occupied cells, we can put as many stamps as we want, stamps
can overlap with eachother, stamps are not allowed to be rotated, stampsmust
stay completely in the grid. return 'true' if it is possible to fit the
stamps while following the given restrictions, otherwise return 'false'.
"""


class Solution(object):
    def possibleToStamp(self, grid, stampHeight, stampWidth):
        """
        :type grid: List[List[int]]
        :type stampHeight: int
        :type stampWidth: int
        :rtype: bool
        """

        def acc_2d(grid):
            dp = [[0] * (n + 1) for _ in range(m + 1)]
            for c, r in product(range(n), range(m)):
                dp[r + 1][c + 1] = dp[r + 1][c] + dp[r][c + 1] - dp[r][c] + grid[r][c]
            return dp

        def sumRegion(r1, c1, r2, c2):
            return dp[r2 + 1][c2 + 1] - dp[r1][c2 + 1] - dp[r2 + 1][c1] + dp[r1][c1]

        m, n = len(grid), len(grid[0])
        dp = acc_2d(grid)
        diff = [[0] * (n + 1) for _ in range(m + 1)]
        for c in range(n - stampWidth + 1):
            for r in range(m - stampHeight + 1):
                if sumRegion(r, c, r + stampHeight - 1, c + stampWidth - 1) == 0:
                    diff[r][c] += 1
                    diff[r][c + stampWidth] -= 1
                    diff[r + stampHeight][c] -= 1
                    diff[r + stampHeight][c + stampWidth] += 1
        dp2 = acc_2d(diff)
        for c, r in product(range(n), range(m)):
            if dp2[r + 1][c + 1] == 0 and grid[r][c] != 1:
                return False
        return True


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.possibleToStamp(
            grid=[[1, 0, 0, 0], [1, 0, 0, 0], [1, 0, 0, 0], [1, 0, 0, 0], [1, 0, 0, 0]],
            stampHeight=4,
            stampWidth=3,
        )
    )
    print(
        obj.possibleToStamp(
            grid=[[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]],
            stampHeight=2,
            stampWidth=2,
        )
    )
