# 201. Bitwise AND of Numbers Range
import math

"""
given two integers 'm' and 'n' that represent the range '[m,
n]', return the bitwise and of all numbers in this range, inclusive.
"""


class Solution(object):
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if m == n:
            return m
        diff = n - m
        msb = 1 << math.floor(math.log2(diff))
        bit_rem = (msb << 1) - 1
        return m & m & ~bit_rem


if __name__ == "__main__":
    obj = Solution()
    print(obj.rangeBitwiseAnd(5, 7))
    print(obj.rangeBitwiseAnd(0, 0))
    print(obj.rangeBitwiseAnd(1, 82747883))
