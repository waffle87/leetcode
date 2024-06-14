# 1143. Longest Common Subsequence

"""
given two strings 'text1' and 'text2', return the length of their longest
common subsequence. if there is no common subsequence, return 0. a
subsequence of a string is a new string generated from the original string
with some characers (can be none) deleted without changing the relative order
of the remaining characters. a common subsequence of two strings is a
subsequence that is common to both strings.
"""


class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
        dp = [[0] * (len(text2) + 1) for _ in range(len(text1) + 1)]
        for i, c in enumerate(text1):
            for j, d in enumerate(text2):
                dp[i + 1][j + 1] = (
                    1 + dp[i][j] if c == d else max(dp[i][j + 1], dp[i + 1][j])
                )
        return dp[-1][-1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestCommonSubsequence("abcde", "ace"))  # expect: 3
    print(obj.longestCommonSubsequence("abc", "abc"))  # expect: 3
    print(obj.longestCommonSubsequence("abc", "def"))  # expect: 0
