# 621. Number of Sets of K Non-Overlapping Line Segments

"""
given 'n' points on a 1d plane, where the i'th point is at 'x = i', find the
number of ways we can draw exactly 'k' non-overlapping line segments such
that each segment covers two or more points. the endpoints of each segmment
must have integeral coordinates. the 'k' line segments do not have to cover
all 'n' points, and they are allowed to share endpoints. return the number of
ways we can draw 'k' non-overlapping segments. since the answer can be very
large, return it modulo 10^9+7.
"""

from math import comb


class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        return comb(n + k - 1, 2 * k) % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfSets(n=4, k=2))
    print(obj.numberOfSets(n=3, k=1))
    print(obj.numberOfSets(n=30, k=7))
