# 1012. Numbers With Repeated Digits
from math import perm

"""
given an integer 'n', return the number of positive integers in range '[1,
n]' that have at least one repeated digit.
"""


class Solution(object):
    def numDupDigitsAtMostN(self, n):
        """
        :type n: int
        :rtype: int
        """
        l = list(map(int, str(n + 1)))
        m = len(l)
        ans = sum(9 * perm(9, i) for i in range(m - 1))
        s = set()
        for i, j in enumerate(l):
            for k in range(i == 0, j):
                if not k in s:
                    ans += perm(9 - i, n - i - 1)
            if j in s:
                break
            s.add(j)
        return n - ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.numDupDigitsAtMostN(20))
    print(obj.numDupDigitsAtMostN(100))
    print(obj.numDupDigitsAtMostN(1000))
