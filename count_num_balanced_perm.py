# 3343. Count Number of Balanced Permutations
from collections import Counter
from math import comb

"""
you are given a string 'num'. a string of digits is called balanced if the
sum of the digits at even indices is equal to the sum of the digits at odd
indices. return the number of distinct permutations of 'num' that are
balanced. since the answer may be very large, return it modulo 10e9+7. a
permutation is a rearrangement of all the characters of a string.
"""


class Solution(object):
    def countBalancedPermutations(self, num):
        """
        :type num: str
        :rtype: int
        """
        mod, n = 10**9 + 7, len(num)
        total = sum(int(i) for i in num)
        if total % 2:
            return 0
        fac = [1] * (n + 1)
        ifac = [1] * (n + 1)
        inv = [1] * (n + 1)
        for i in range(1, n + 1):
            fac[i] = fac[i - 1] * i % mod
        for i in range(2, n + 1):
            inv[i] = mod - (mod // i) * inv[mod % i] % mod
        for i in range(1, n + 1):
            ifac[i] = ifac[i - 1] * inv[i] % mod
        half_sum = total // 2
        half_len = n // 2
        dp = [[0] * (half_len + 1) for _ in range(half_sum + 1)]
        dp[0][0] = 1
        digits = [0] * 10
        for c in num:
            d = int(c)
            digits[d] += 1
            for i in range(half_sum, d - 1, -1):
                for j in range(half_len, 0, -1):
                    dp[i][j] = (dp[i][j] + dp[i - d][j - 1]) % mod
        ans = dp[half_sum][half_len]
        ans = ans * fac[half_len] % mod * fac[n - half_len] % mod
        for cnt in digits:
            ans = ans * ifac[cnt] % mod
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countBalancedPermutations(num="123"))
    print(obj.countBalancedPermutations(num="112"))
    print(obj.countBalancedPermutations(num="12345"))
