# 869. Reordered Power of 2
from collections import Counter

"""
you are given an integer 'n'. we reorder the digits in any order (including
the original order) such that the leading digit is not zero. return true if
an only if we can do this so that the resulting number is a power of two.
"""


class Solution(object):
    def reorderedPowerOf2(self, n):
        """
        :type n: int
        :rtype: bool
        """
        cnt = Counter(str(n))
        for i in range(31):
            if Counter(str(1 << i)) == cnt:
                return True
        return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.reorderedPowerOf2(1))
    print(obj.reorderedPowerOf2(10))
