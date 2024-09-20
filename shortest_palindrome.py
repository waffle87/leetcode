# 214. Shortest Palindrome

"""
you are given a string 's'. you can convert 's' to a palindrome by adding
characters in front of it. return the shortest palindrome you can find by
performing this transformation.
"""


class Solution(object):
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        r = s[::-1]
        for i in range(len(s) + 1):
            if s.startswith(r[i:]):
                return r[:i] + s


if __name__ == "__main__":
    obj = Solution()
    print(obj.shortestPalindrome("aacecaaa"))
    print(obj.shortestPalindrome("abcd"))
