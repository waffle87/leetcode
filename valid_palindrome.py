# 125. Valid Palindrome

"""
a phrase is a palindrome if, after converting all uppercase letters into
lowercase letters, and removing all non-alphanumeric characters, it reads the
same forward and backward. alphanumeric characters include only letters and
numbers. given a string 's', return true if it is a palindrome, or false
otherwise.
"""


class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        l, r = 0, len(s) - 1
        while l < r:
            while l < r and not s[l].isalnum():
                l += 1
            while l < r and not s[r].isalnum():
                r -= 1
            if s[l].lower() != s[r].lower():
                return False
            l += 1
            r -= 1
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.isPalindrome(s="A man, a plan, a canal: Panama"))
    print(obj.isPalindrome(s="race a car"))
    print(obj.isPalindrome(s=" "))
