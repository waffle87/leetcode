# 115. Distinct Subsequences

"""
given two strings 's' and 't', return the number of distinct subsequences of
's' which equals 't'. the test cases are generated so that the answer fits in
a 32-bit signed integer.
"""


class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m, n = len(s), len(t)
        dp = [0] * (n + 1)
        for i in range(1, m + 1):
            prev = 1
            for j in range(1, n + 1):
                curr = dp[j]
                take = 0
                if s[i - 1] == t[j - 1]:
                    take = prev
                not_take = curr
                dp[j] = take + not_take
                prev = curr
        return dp[n]


if __name__ == "__main__":
    obj = Solution()
    print(obj.numDistinct(s="rabbbit", t="rabbit"))
    print(obj.numDistinct(s="babgbag", t="bag"))
