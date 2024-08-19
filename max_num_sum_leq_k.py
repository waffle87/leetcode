# 3007. Maximum Number That Sum of the Prices Is Less Than or Equal to K
from bisect import bisect_right

"""
you are given an integer 'k' and an integer 'x'. the price of a number is
calculated by the count of set its at positions 'x, 2x, 3x, etc.', in its
binary representation, starting from the least significant bit. the following
tale contains examples of how price is calculated
x    num    binary representation    price
------------------------------------------
1    13     000001101                3
2    13     000001101                1
2    233    011101001                3
3    13     000001101                1
3    362    101101010                2
the accumulated price of 'num' is the total price of numbers from 1 to 'num'.
'num' is considered cheap if its accumulated price is less than or equal to
'k'. return the greatest cheap number
"""


class Solution(object):
    def __init__(self):
        self.x = None

    def price(self, num):
        res = 0
        for i in range(self.x - 1, 64, self.x):
            check = num % (1 << (i + 1))
            res += ((num - check) >> 1) + max(check - (1 << i), 0)
        return res

    def findMaximumNumber(self, k, x):
        """
        :type k: int
        :type x: int
        :rtype: int
        """
        self.x = x
        return bisect_right(range((1 << 63) - 1), k, key=self.price) - 2


if __name__ == "__main__":
    obj = Solution()
    print(obj.findMaximumNumber(9, 1))
    print(obj.findMaximumNumber(7, 2))
