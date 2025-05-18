# 1931. Painting a Grid With Three Different Colors
from collections import Counter

"""
you are given two integers 'm' and 'n'. consider an 'm x n' grid where each
cell is initially white. you can paint each cell red, green, or blue. all
cells must be painted. return the number of ways to colour the grid with no
two adjacent cells having the same colour. since the answer can be very
large, return it modulo 10^9+7.
"""


class Solution(object):
    def colorTheGrid(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = {(1 << (2 * m)) - 1: 1}
        mod = 10**9 + 7
        for i in range(m * n - 1, -1, -1):
            copy = Counter()
            x, y = divmod(i, m)
            for j in dp:
                valid = {0, 1, 2}
                if y < m - 1:
                    valid.discard(j >> (2 * m - 2))
                if x < n - 1:
                    valid.discard(j & 3)
                for k in valid:
                    new = (j >> 2) + (k << (2 * m - 2))
                    copy[new] = (copy[new] + dp[j]) % mod
            dp = copy
        return sum(dp.values()) % mod


if __name__ == "__main__":
    obj = Solution()
    print(obj.colorTheGrid(m=1, n=1))
    print(obj.colorTheGrid(m=1, n=2))
    print(obj.colorTheGrid(m=5, n=5))
