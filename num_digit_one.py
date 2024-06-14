# 233. Number of Digit One

"""
given an integer 'n', count the total number of digit 1 appearing in all
non-negative integers less than or equal to n
"""


class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        ones, m, r = 0, 1, 1
        while n > 0:
            ones += (n + 8) / 10 * m + (n % 10 == 1) * r
            r += n % 10 * m
            m *= 10
            n /= 10
        return ones


if __name__ == "__main__":
    obj = Solution()
    print(obj.countDigitOne(13))  # expect: 6
    print(obj.countDigitOne(0))  # expect: 0
