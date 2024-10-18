# 372. Super Pow
from functools import reduce

"""
your task is to calculate `a^b % 1337` where 'a' is a positive integer and
'b' is an extremely large positive integer given in the form of an array
"""


class Solution(object):
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        return (
            0
            if a % 1337 == 0
            else pow(a, reduce(lambda x, y: (x * 10 + y) % 1140, b) + 1140, 1337)
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.superPow(a=2, b=[3]))
    print(obj.superPow(a=2, b=[1, 0]))
    print(obj.superPow(a=1, b=[4, 3, 3, 8, 5, 2]))
