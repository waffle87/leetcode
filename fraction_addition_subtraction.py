# 592. Fraction Addition and Subtraction
from re import findall
from math import gcd

"""
given a string 'expression' representing an expression of fraction addition
and subtraction, return the calculation result in string format. the final
result should an irreducible fraction. if your final result is an integer,
change it to the format of a fraction has a denominator 1. so in this case, 2
should be converted to "2/1"
"""


class Solution(object):
    def fractionAddition(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        nums = map(int, findall("[+-]?\d+", expression))
        a, b = 0, 1
        for i in nums:
            j = next(nums)
            a = a * j + i * b
            b *= j
            g = gcd(a, b)
            a //= g
            b //= g
        return "%d/%d" % (a, b)


if __name__ == "__main__":
    obj = Solution()
    print(obj.fractionAddition(expression="-1/2+1/2"))
    print(obj.fractionAddition(expression="-1/2+1/2+1/3"))
    print(obj.fractionAddition(expression="1/3-1/2"))
