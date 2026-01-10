# 712. Minimum ASCII Delete Sum for Two Strings

"""
given two strings 's1' and 's2', return the lowest ascii sum of the deleted
characters to make two strings equal
"""


class Solution(object):
    def minimumDeleteSum(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        n, m = len(s1), len(s2)
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + ord(s1[i - 1])
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        total = 0
        for i in s1:
            total += ord(i)
        for i in s2:
            total += ord(i)
        return total - dp[n][m] * 2


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumDeleteSum(s1="sea", s2="eat"))
    print(obj.minimumDeleteSum(s1="delete", s2="leet"))
