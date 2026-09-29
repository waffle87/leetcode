# 2267. Check if There Is a Valid Parentheses String Path

"""
a parentheses string is non-empty string that consists of only '(' and ')'.
it is valid if any of the following conditions is true: it is '()', it can be
written as 'AB', or it can be written as '(A)'. you are given an 'm x n'
matrix of parentheses 'grid'. a valid parentheses string path in the grid is
a path satisfying all of the given conditions. return true if there exists a
valid parentheses string path in the grid. otherwise, return 'false'.
"""

from functools import cache


class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        if ~(m + n) & 1 or grid[0][0] == ")" or grid[-1][-1] == "(":
            return False

        @cache
        def dfs(i, j, x):
            x += 1 - ((ord(grid[i][j]) & 1) << 1)
            if x < 0 or x > m - i + n - j - 1:
                return False
            if i == m - 1 and j == n - 1:
                return x == 0
            return (i < m - 1 and dfs(i + 1, j, x)) or (j < n - 1 and dfs(i, j + 1, x))

        return dfs(0, 0, 0)


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.hasValidPath(
            grid=[["(", "(", "("], [")", "(", ")"], ["(", "(", ")"], ["(", "(", ")"]]
        )
    )
    print(obj.hasValidPath(grid=[[")", ")"], ["(", "("]]))
