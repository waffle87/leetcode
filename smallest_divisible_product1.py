# 3345. Smallest Divisible Digit Product I
from math import gcd

"""
you are given two integers 'n' and 't'. return the smallest nmber greater
than or equal to 'n' such that the product of its digits is divisible by 't'.
"""


class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        q, r = divmod(n, 10)
        req = t // gcd(max(q, 1), t)
        nxt = ((r + req - 1) // req) * req
        x = nxt - (nxt - 10) * (nxt // 10)
        return q * 10 + x


if __name__ == "__main__":
    obj = Solution()
    print(obj.smallestNumber(n=10, t=2))
    print(obj.smallestNumber(n=15, t=3))
