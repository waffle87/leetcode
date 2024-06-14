# 1092. Shortest Common Supersequence

"""
given two strings 's1' and 's2', return the shortest string that has both
s1 and s2 as subsequences. if there are multiple valid strings, return
any of them. a string 's' is a supersequence if string 't' if deleting some
number of characters from 't' (possibly 0) results in string 's'.
"""


class Solution(object):
    def lcs(self, s1, s2):
        n, m = len(s1), len(s2)
        dp = [["" for i in range(m + 1)] for j in range(n + 1)]
        for i in range(n):
            for j in range(m):
                if s1[i] == s2[j]:
                    dp[i + 1][j + 1] = dp[i][j] + s1[i]
                else:
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1], key=len)
        return dp[-1][-1]

    def shortestCommonSupersequence(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: str
        """
        ans, i, j = "", 0, 0
        for c in self.lcs(s1, s2):
            while s1[i] != c:
                ans += s1[i]
                i += 1
            while s2[j] != c:
                ans += s2[j]
                j += 1
            ans += c
            i, j = i + 1, j + 1
        return ans + s1[i:] + s2[j:]


if __name__ == "__main__":
    obj = Solution()
    print(obj.shortestCommonSupersequence(s1="abac", s2="cab"))
    print(obj.shortestCommonSupersequence(s1="aaaaaaaa", s2="aaaaaaaa"))
