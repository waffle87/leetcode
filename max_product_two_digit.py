# 3536. Maximum Product of Two Digits

"""
you are given a positive integer 'n'. return the maximum product of any two
digits 'n'. note you may use the same digit twice if it appears more than
once in 'n'.
"""

from heapq import nlargest
from math import prod


class Solution:
    def maxProduct(self, n: int) -> int:
        return prod(nlargest(2, map(int, str(n))))


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxProduct(n=31))
    print(obj.maxProduct(n=22))
    print(obj.maxProduct(n=124))
