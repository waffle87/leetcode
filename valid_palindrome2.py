# 680. Valid Palindrome II

"""
given a string 's', return 'true' if the 's' can be palindrome after deleting
at most one charater from it.
"""


class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        left, right = 0, len(s) - 1
        while left < right:
            if s[left] != s[right]:
                one, two = s[left:right], s[left + 1 : right + 1]
                return one == one[::-1] or two == two[::-1]
            left, right = left + 1, right - 1
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.validPalindrome("aba"))  # expect: True
    print(obj.validPalindrome("abca"))  # expect: True
    print(obj.validPalindrome("abc"))  # expect: False
