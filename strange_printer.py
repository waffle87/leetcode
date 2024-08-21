# 664. Strange Printer

"""
there is a strange printer with the following two special properties:
- the printer can only print a sequence of the same character each time
- at each turn, the printer can print new characters starting from and eding
at any place and will cover the origin existing characters given a string
's', return the minimum number of turns the printer needed to print it.
"""


class Solution(object):
    def strangePrinter(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            dp[i][i] = 1
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    dp[i][j] = dp[i][j - 1]
                else:
                    dp[i][j] = dp[i][j - 1] + 1
                    for k in range(i, j):
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j])
        return dp[0][n - 1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.strangePrinter("aaabbb"))
    print(obj.strangePrinter("aba"))
