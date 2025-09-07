# 1304. Find N Unique Integers Sum up to Zero

"""
given an integer 'n', return any array containing 'n' unique integers such
that they add up to 0.
"""


class Solution(object):
    def sumZero(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        return range(1 - n, n, 2)


if __name__ == "__main__":
    obj = Solution()
    print(obj.sumZero(5))
    print(obj.sumZero(3))
    print(obj.sumZero(1))
