# 693. Binary Number with Alternating Bits

"""
given a positive integer, check whether it has alternating bits: namely if
two adjacent bits will always have different values
"""


class Solution(object):
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        x = n ^ (n >> 1)
        return (x & (x + 1)) == 0


if __name__ == "__main__":
    obj = Solution()
    print(obj.hasAlternatingBits(5))
    print(obj.hasAlternatingBits(7))
    print(obj.hasAlternatingBits(11))
