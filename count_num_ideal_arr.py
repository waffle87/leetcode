# 2338. Count the Number of Ideal Arrays
from collections import Counter
from math import comb

"""
you are given two integers 'n' and 'maxValue' which are used to describe an
ideal array. a 0-indexed integer array 'arr' of length 'n' is considered
ideal if the following conditions hold true: every 'arr[i]' is a value from 1
to 'maxValue' for '0 <= i < n', and every 'arr[i]' is divisble by 'arr[i -
1]'. return the number of distinct ideal arrays of length 'n'. since the
answer may be very large, return it modulo 10^9+7.
"""


class Solution(object):
    def idealArrays(self, n, maxValue):
        """
        :type n: int
        :type maxValue: int
        :rtype: int
        """
        ans = maxValue
        freq = {i: 1 for i in range(1, maxValue + 1)}
        for i in range(1, n):
            tmp = Counter()
            for j in freq:
                for k in range(2, maxValue // j + 1):
                    ans += comb(n - 1, i) * freq[j]
                    tmp[k * j] += freq[j]
            freq = tmp
            ans %= 10**9 + 7
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.idealArrays(n=2, maxValue=5))
    print(obj.idealArrays(n=5, maxValue=3))
