# 2466. Count Ways To Build Good Strings
from collections import Counter

"""
given the integers 'zero, one, low, and high', we can construct a string by
starting with an empty string, and then at each step perform either of the
following opperations:
- append the character 0 'zero' times
- append the character 1 'one' times
this can be performed any number of times. a good string is a string
constructed by the above process having a length between 'low' and 'high'
(inclusive). return the number of different good strings that can be
constructed. return modulo 10^9+7.
"""


class Solution(object):
    def countGoodStrings(self, low, high, zero, one):
        """
        :type low: int
        :type high: int
        :type zero: int
        :type one: int
        :rtype: int
        """
        dp = Counter({0: 1})
        mod = 10**9 + 7
        for i in range(1, high + 1):
            dp[i] = (dp[i - zero] + dp[i - one]) % mod
        return sum(dp[i] for i in range(low, high + 1)) % mod


if __name__ == "__main__":
    obj = Solution()
    print(obj.countGoodStrings(3, 3, 1, 1))
    print(obj.countGoodStrings(2, 3, 1, 2))
