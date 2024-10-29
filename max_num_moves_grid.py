# 2684. Maximum Number of Moves in a Grid

"""
given a 0-indexed array 'm * n' grid consisting of positive integers. you can
start at any cell in the first column of the matrix and traverse the grid in
the following way: from cell '(row, col)', you can move to any of the cells:
'(row - 1, col + 1), (row, col + 1), and (row + 1, col + 1)'. such that thhe
value of the cell you are moving to should be strictly bigger than the value
of the current cell. return the maximum number of moves that you can perform.
"""


class Solution(object):
    def maxMoves(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n, ans = len(grid), len(grid[0]), 0
        dp = [0] * m
        for j in range(1, n):
            left_top, found = 0, False
            for i in range(m):
                next_left_top, curr = dp[i], -1
                if i - 1 >= 0 and left_top != -1 and grid[i][j] > grid[i - 1][j - 1]:
                    curr = max(curr, left_top + 1)
                if dp[i] != -1 and grid[i][j] > grid[i][j - 1]:
                    curr = max(curr, dp[i] + 1)
                dp[i] = curr
                found = found or (dp[i] != -1)
                left_top = next_left_top
            if not found:
                break
            ans = j
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxMoves(grid=[[2, 4, 3, 5], [5, 4, 9, 3], [3, 4, 2, 11], [10, 9, 13, 15]])
    )
    print(obj.maxMoves(grid=[[3, 2, 4], [2, 1, 9], [1, 1, 7]]))
