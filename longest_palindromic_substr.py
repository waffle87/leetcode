# 5. Longest Palindromic Substring

"""
given a string 's', return the longest palindromic substring in 's'
"""


class Solution(object):
    def helper(self, s, l, r):
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return s[l + 1 : r]

    def longestPalindrome(self, s):
        ans = ""
        for i in range(len(s)):
            tmp = self.helper(s, i, i)
            if len(tmp) > len(ans):
                ans = tmp
            tmp = self.helper(s, i, i + 1)
            if len(tmp) > len(ans):
                ans = tmp
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestPalindrome("babad"))  # expect: bab
    print(obj.longestPalindrome("cbbd"))  # expect: bb
