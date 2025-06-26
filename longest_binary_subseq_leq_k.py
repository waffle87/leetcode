# 2311. Longest Binary Subsequence Less Than or Equal to K

"""
you are given a binary string 's' and a positive integer 'k'. return the
length of the longest subsequence of 's' that makes up a binary number less
than or equal to 'k'. note the subsequence can contain leading zeros, the
empty string is considered to be equal to 0, and a subsequence is a string
that can be derived from another string by deleting some or no characters
without changing the order of the remaining characters.
"""


class Solution(object):
    def longestSubsequence(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        i = 0
        while int(s[-i - 1 :], 2) <= k and i < 32 and i < len(s):
            i += 1
        return s[:-i].count("0") + i


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestSubsequence(s="1001010", k=5))
    print(obj.longestSubsequence(s="00101001", k=1))
