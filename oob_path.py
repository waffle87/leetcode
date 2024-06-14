# 576. Out of Boundary Paths

"""
there is an 'm  n' grid with a ball. the ball is initially at the position
'[start_row, start_column]'. you are allowed to move the ball to one of the
four adjacent cells in the grid (possible out of the grid crossing the grid
boundary). you can apply at most 'max_move' moves to the ball. given the give
integers, 'm', 'n', 'max_move', 'start_row', 'and start_column', return the
number of paths to move the ball out of the grid boundary. since the answer
can be very large, return it modulo 10^9+7
"""


class Solution(object):
    def findPaths(self, m, n, maxMove, startRow, startColumn):
        """
        :type m: int
        :type n: int
        :type maxMove: int
        :type startRow: int
        :type startColumn: int
        :rtype: int
        """
        dp = [[[-1] * (maxMove + 1) for _ in range(n + 1)] for _ in range(m + 1)]

        def solve(i, j, maxMove):
            if maxMove < 0:
                return 0
            if i < 0 or i >= m or j < 0 or j >= n:
                return 1
            if dp[i][j][maxMove] != -1:
                return dp[i][j][maxMove]
            a = solve(i - 1, j, maxMove - 1)
            b = solve(i + 1, j, maxMove - 1)
            c = solve(i, j - 1, maxMove - 1)
            d = solve(i, j + 1, maxMove - 1)
            dp[i][j][maxMove] = a + b + c + d
            return dp[i][j][maxMove]

        return solve(startRow, startColumn, maxMove) % 1000000007


if __name__ == "__main__":
    obj = Solution()
    print(obj.findPaths(m=2, n=2, maxMove=2, startRow=0, startColumn=0))  # expect: 6
    print(obj.findPaths(m=1, n=3, maxMove=3, startRow=0, startColumn=1))  # expect: 12
