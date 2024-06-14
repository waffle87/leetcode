# 1922. Count Good Numbers

"""
a digit string is good if the digits (0-indexed) at even indices are even and
the digits at odd indices are prime (2,3,5,or 7). for example 2582 is good
because the digits 2 and 8 at even positions are even and the digits 5 and 2
at odd positions are prime. however, 3245 is not good because 3 is at an even
index, but is not even. given an integer 'n', return the total number of good
digit strings of length 'n'. since the answer may be large, return it modulo
1e9+7. a digit string is a string consisting of digits 0 through 9 that may
contain leading zeros.
"""


class Solution(object):
    def countGoodNumbers(self, n):
        """
        :type n: int
        :rtype: int
        """
        cnt, x = 5 ** (n % 2), 20
        for _ in range(n // 2):
            cnt = cnt * x % (10**9 + 7)
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.countGoodNumbers(1))
    print(obj.countGoodNumbers(4))
    print(obj.countGoodNumbers(50))
