# 2536. Increment Submatrices by One

"""
you are given a positive integer 'n', indicating that we initially have an 'n
x n' 0-indexed integer matrix 'mat' filled with zeros. you are also given a
2d integer array 'query'. for each 'query[i] = [row1_i, col1_i, row2_i,
col2_i]', you should do the following operation: add 1 to every element in
the submatrix with the top left corner '(row1_i, col1_i)' and the bottom
right corner '(row2_i, col2_i)'. that is, add 1 to 'mat[x][y]' for all
'row1_i <= x <= row2_i' and 'col1_i <= y <= col2_i'. return the matrix 'mat'
after performing every query
"""


class Solution(object):
    def rangeAddQueries(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: List[List[int]]
        """
        ans = [[0] * n for _ in range(n)]
        for r1, c1, r2, c2 in queries:
            ans[r1][c1] += 1
            if r2 + 1 < n:
                ans[r2 + 1][c1] -= 1
            if c2 + 1 < n:
                ans[r1][c2 + 1] -= 1
            if r2 + 1 < n and c2 + 1 < n:
                ans[r2 + 1][c2 + 1] += 1
        for i in range(1, n):
            for j in range(n):
                ans[i][j] += ans[i - 1][j]
        for i in range(n):
            for j in range(1, n):
                ans[i][j] += ans[i][j - 1]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.rangeAddQueries(n=3, queries=[[1, 1, 2, 2], [0, 0, 1, 1]]))
    print(obj.rangeAddQueries(n=2, queries=[[0, 0, 1, 1]]))
