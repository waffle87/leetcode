# 861. Score After Flipping Matrix

"""
given an 'm  n' binary matrix 'grid'. a move consists of choosing any row or
column and toggling each value in thatrow or column. every row of the matrix
is interpreted as a binary number, and the score of the matrix is the sum of
these numbers. return the highest possible score after making any number of
moves, including zero.
"""


class Solution(object):
    def matrixScore(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        ans = (1 << n - 1) * m
        for i in range(1, n):
            curr = sum(grid[j][i] == grid[j][0] for j in range(m))
            ans += max(curr, m - curr) * (1 << n - 1 - i)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.matrixScore(grid=[[0, 0, 1, 1], [1, 0, 1, 0], [1, 1, 0, 0]]))
    print(obj.matrixScore(grid=[[0]]))
