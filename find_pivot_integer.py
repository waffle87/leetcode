# 2485. Find the Pivot Integer
from math import sqrt

"""
given a positive integer 'n', find the pivot integer 'x' such that the sum of
all elements between 1 and 'x' inclusively equals the sum of all elements
between 'x' and 'n' inclusively. return the pivot integer 'x'. if no such
integer exists, return -1. it is guaranteed that there will be at most one
pivot index for the given input.
"""


class Solution(object):
    def pivotInteger(self, n):
        """
        :type n: int
        :rtype: int
        """
        tmp = (n * n + n) // 2
        sqr = int(sqrt(tmp))
        if sqr * sqr == tmp:
            return sqr
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.pivotInteger(8))
    print(obj.pivotInteger(1))
    print(obj.pivotInteger(4))
