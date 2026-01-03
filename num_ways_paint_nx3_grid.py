# 1411. Number of Ways to Paint N × 3 Grid

"""
you have a 'grid' of size 'n x 3' and you want to paint each cell of the grid
with exactly one of the three colours: red, yellow, or green while making
sure that no two adjacent cells have the same colour. given 'n' the number of
rows of the grid, return the number of ways you can paint this 'grid'. as the
answer may grow large, the answer must be computer modulo 10e9 + 7.
"""


class Solution(object):
    def numOfWays(self, n):
        """
        :type n: int
        :rtype: int
        """
        a1, a2, mod = 6, 6, 10**9 + 7
        for i in range(n - 1):
            a1, a2 = a1 * 3 + a2 * 2, a1 * 2 + a2 * 2
        return (a1 + a2) % mod


if __name__ == "__main__":
    obj = Solution()
    print(obj.numOfWays(n=1))
    print(obj.numOfWays(n=5000))
