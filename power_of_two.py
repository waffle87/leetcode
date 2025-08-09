# 231. Power of Two
from math import log2

"""
given an integer 'n', return true if it is a power of two. otherwise, return
false. an integer 'n' is a power of two if there exists an integer 'x' such
that 'n == 2^x'
"""


class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return n > 0 and (log2(n) % 1 == 0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.isPowerOfTwo(1))
    print(obj.isPowerOfTwo(16))
    print(obj.isPowerOfTwo(3))
