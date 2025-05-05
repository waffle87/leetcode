# 790. Domino and Tromino Tiling

"""
you have two types of tiles: a '2 x 1' domino shape and a tromino shape. you
may rotate these shapes. given an integer 'n', return the number of ways to
tile a '2 x n' board. since the answer may be very large, return it modulo
10^9+7. in a tiling, every square must be tiled by a tile. two tilings are
different if and only if there are two 4-directionally adjacent cells on the
board such that exactly one of the tilings has both squares occupied by a
tile.
"""


class Solution(object):
    def numTilings(self, n):
        """
        :type n: int
        :rtype: int
        """
        mod = 10**9 + 7
        if n <= 2:
            return n
        f_prev, g_prev, f_prev2, g_prev2 = 2, 2, 1, 1
        for i in range(3, n + 1):
            filled = f_prev + f_prev2 + 2 * g_prev2
            gap = f_prev + g_prev
            f_prev2, f_prev, g_prev2, g_prev = f_prev, filled, g_prev, gap
        return f_prev % mod


if __name__ == "__main__":
    obj = Solution()
    print(obj.numTilings(n=3))
    print(obj.numTilings(n=1))
