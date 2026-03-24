# 2906. Construct Product Matrix
from typing import List

"""
given a 0-indexed 2d integer matrix 'grid' of size 'n x m', we define a
0-indexed 2d matrix 'p' of size 'n x m' as the product matrix of 'grid' if
the following condition is met: each element 'p[i][j]' is calculated as the
product of all elements in 'grid' excpet for the element 'grid[i][j]'. this
product is then taken modulo 12345. return the product matrix of 'grid'.
"""


class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        mod = 12345
        m, n = len(grid), len(grid[0])
        p = [[0] * m for _ in range(n)]
        suffix, prefix = 1, 1
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                p[i][j] = suffix
                suffix *= grid[i][j] % mod
        for i in range(m):
            for j in range(n):
                p[i][j] *= prefix % mod
                prefix *= grid[i][j] % mod
        return p


if __name__ == "__main__":
    obj = Solution()
    print(obj.constructProductMatrix(grid=[[1, 2], [3, 4]]))
    print(obj.constructProductMatrix(grid=[[12345], [2], [1]]))
