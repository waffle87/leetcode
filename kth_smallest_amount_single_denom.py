# 3116. Kth Smallest Amount With Single Denomination Combination

"""
you are given an integer array 'coins' representing coins of different
denominations and an integer 'k'. you have an infinite number of coins of
each denomination. however, you are not allowed to combine coins of different
denominations. return the k'th smallest amount that can be made using these
coins.
"""

from bisect import bisect_left
from math import lcm


class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        coins.sort()
        a = []
        for i in coins:
            if all(i % j for j in a):
                a.append(i)
        n = len(a)

        def check(mid):
            total = 0
            for i in range(1, n + 1):
                q = (1 << i) - 1
                lim = 1 << n
                sign = ((i & 1) << 1) - 1
                while q < lim:
                    x = 1
                    for j in range(n):
                        if (q >> j) & 1:
                            x = lcm(x, a[j])
                    total += (mid // x) * sign
                    c = q & -q
                    r = q + c
                    q = (((r ^ q) >> 2) // c) | r
            return total >= k

        return bisect_left(range(a[0] * k + 1), True, lo=k, key=check)


if __name__ == "__main__":
    obj = Solution()
    print(obj.findKthSmallest(coins=[3, 6, 9], k=3))
    print(obj.findKthSmallest(coins=[5, 2], k=7))
