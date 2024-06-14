# 1531. String Compression II

"""
run-length encoding is a string compression method that works by replacing
consecutive identical characters (repeated 2 or more times) with the
concatenation of the characters and the number marking the count of the
characters (length of run). for example tocompress the string "aabccc", we
replace "aa" by "a2" and replace "ccc" by "c3". thus the compressed string
becomes "a2bc3". notice that in this problem we are not adding '1' after
single characters. given a string 's' and an integer 'k'. you needed to
delete at most 'k' characters from 's' such that the run-length encoded
version of 's' has minimum length. find the minimum length of the run-length
encoded version of 's' after deleting at most 'k' characters
"""


class Solution(object):
    def getLengthOfOptimalCompression(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        n = len(s)
        m = k
        dp = [[float("inf")] * 110 for _ in range(110)]
        for i in range(1, n + 1):
            for j in range(min(i + 1, m + 1)):
                needRemove = 0
                groupCount = 0
                dp[i][j] = float("inf")
                if j > 0:
                    dp[i][j] = dp[i - 1][j - 1]
                for k in range(i, 0, -1):
                    if s[k - 1] != s[i - 1]:
                        needRemove += 1
                    else:
                        groupCount += 1
                    if needRemove > j:
                        break
                    if groupCount == 1:
                        dp[i][j] = min(dp[i][j], dp[k - 1][j - needRemove] + 1)
                    elif groupCount < 10:
                        dp[i][j] = min(dp[i][j], dp[k - 1][j - needRemove] + 2)
                    elif groupCount < 100:
                        dp[i][j] = min(dp[i][j], dp[k - 1][j - needRemove] + 3)
                    else:
                        dp[i][j] = min(dp[i][j], dp[k - 1][j - needRemove] + 4)
        return dp[n][m]


if __name__ == "__main__":
    obj = Solution()
    print(obj.getLengthOfOptimalCompression("aaabcccd", 2))  # expect: 4
    print(obj.getLengthOfOptimalCompression("aabbaa", 2))  # expect: 2
    print(obj.getLengthOfOptimalCompression("aaaaaaaaaaa", 0))  # expect: 3
