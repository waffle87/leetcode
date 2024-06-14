# 409. Longest Palindrome

"""
given a sting 's' which consists of lowercase or uppercase letters, return
the length of the longest palindrome that can be built with those letters.
letters are case sensitive for example "Aa" is not considered a palindrome
"""


class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        odd_cnt, d = 0, {}
        for c in s:
            if c in d:
                d[c] += 1
            else:
                d[c] = 1
            if d[c] % 2 == 1:
                odd_cnt += 1
            else:
                odd_cnt -= 1
        if odd_cnt > 1:
            return len(s) - odd_cnt + 1
        return len(s)


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestPalindrome("abccccdd"))
    print(obj.longestPalindrome("a"))
