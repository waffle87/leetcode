# 2370. Longest Ideal Subsequence

"""
given a string 's' consisting of lowercase letters and an integer 'k', we
call a string 't' ideal if the following conditions are satisfied. 't' is a
subsequence of the string 's'. the absolute difference in the alphabet order
of every two adjacent letters in 't' is less than or equal to 'k'. return the
length of the longest ideal sting. a subsequence is a string that can be
derived from another string by deleting some or no characters without
changing the order of the remaining characters. note that the alphabet order
is not cyclic. for example, the absolute difference in the alphabet order of
'a' and 'z' is 25, not 1.
"""


class Solution(object):
    def longestIdealString(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        dp = [0] * 128
        for c in s:
            i = ord(c)
            dp[i] = max(dp[i - k : i + k + 1]) + 1
        return max(dp)


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestIdealString("acfbd", 2))  # expect: 4
    print(obj.longestIdealString("abcd", 3))  # expect: 4
