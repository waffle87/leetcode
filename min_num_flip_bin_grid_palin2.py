# 3240. Minimum Number of Flips to Make Binary Grid Palindromic II

"""
you are given an 'm x n' binary matrix 'grid'. a row or column is considered
palindromic if its values read the same forward as backward. you can flip any
number of cells in 'grid' from 0 to 1 or from 1 to 0. return the minimum
number of cells that need to be flipped to make all rows and columns
palindromic and the total number of 1s in 'grid' divisible by 4.
"""


class Solution(object):
    def minFlips(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        ans, one, diff, m, n = 0, 0, 0, len(grid), len(grid[0])
        for i in range(m // 2):
            for j in range(n // 2):
                v = grid[i][j] + grid[i][~j] + grid[~i][j] + grid[~i][~j]
                ans += min(v, 4 - v)
        if n % 2:
            for i in range(m // 2):
                diff += grid[i][n // 2] ^ grid[~i][n // 2]
                one += grid[i][n // 2] + grid[~i][n // 2]
        if m % 2:
            for i in range(n // 2):
                diff += grid[m // 2][j] ^ grid[m // 2][~j]
                one += grid[m // 2][j] + grid[m // 2][~j]
        if n % 2 and m % 2:
            ans += grid[m // 2][n // 2]
        if diff == 0 and one % 4:
            ans += 2
        return ans + diff


if __name__ == "__main__":
    obj = Solution()
    print(obj.minFlips(grid=[[1, 0, 0], [0, 1, 0], [0, 0, 1]]))
    print(obj.minFlips(grid=[[0, 1], [0, 1], [0, 0]]))
    print(obj.minFlips(grid=[[1], [1]]))
