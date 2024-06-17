# 633. Sum of Square Numbers
from math import sqrt

"""
given a non-negative integer 'c', decide whether there are two integers 'a'
and 'b' such that 'a^2 + b^2 = c'
"""


class Solution(object):
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        for a in range(int(sqrt(c)) + 1):
            b = sqrt(c - a * a)
            if b == int(b):
                return True
        return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.judgeSquareSum(5))  # expect: true
    print(obj.judgeSquareSum(3))  # expect: false
