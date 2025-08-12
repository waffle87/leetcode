# 2787. Ways to Express an Integer as Sum of Powers

"""
given two positive integer 'n' and 'x'. return the number of ways 'n' can be
expressed as the sum of the x'th power of unique positive integers, in other
words, the number of sets of unique integers. since the result can be very
large, return it modulo 10^9+7..
"""


class Solution(object):
    def numberOfWays(self, n, x):
        """
        :type n: int
        :type x: int
        :rtype: int
        """
        mod = 10**9 + 7
        powers, i = [], 1
        while True:
            curr = pow(i, x)
            if curr > n:
                break
            powers.append(curr)
            i += 1
        dp = [0] * (n + 1)
        dp[0] = 1
        for i in powers:
            for j in range(n, i - 1, -1):
                dp[j] = (dp[j] + dp[j - i]) % mod
        return dp[n]


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfWays(n=10, x=2))
    print(obj.numberOfWays(n=4, x=1))
