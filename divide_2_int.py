# 29. Divide Two Integers

"""
Given two integers 'dividend' and 'divisor', divide two integers without
using multiplication, division, or mod operations. the integer division
should truncate toward zero, which means losing its fractional part. for
example, 8.345 would be truncated to 8. return the quotient after dividing
'dividend' by 'divisor'.
"""


class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if dividend == -2147483648 and divisor == -1:
            return 2147483647
        dvd, dvs, ans = abs(dividend), abs(divisor), 0
        for i in range(32)[::-1]:
            if (dvd >> i) - dvs >= 0:
                ans += 1 << i
                dvd -= dvs << i
        return ans if (dividend > 0) == (divisor > 0) else -ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.divide(dividend=10, divisor=3))
    print(obj.divide(dividend=7, divisor=-3))
