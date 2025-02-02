# 1542. Find Longest Awesome Substring

"""
you are given a string 's'. an awesome substring is a non-empty substring of
's' such that we can make any number of swaps in order to make it a
palindrome. return the length of the maximum length awesome substring of 's'.
"""


class Solution(object):
    def longestAwesome(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans, mask = 0, 0
        dp = [-1] + [len(s)] * 1023
        for i in range(len(s)):
            mask ^= 1 << (ord(s[i]) - 48)
            for j in range(11):
                check = 1023 & (mask ^ (1 << j))
                ans = max(ans, i - dp[check])
            dp[mask] = min(dp[mask], i)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestAwesome(s="3242415"))
    print(obj.longestAwesome(s="12345678"))
    print(obj.longestAwesome(s="213123"))
