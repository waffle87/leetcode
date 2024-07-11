# 1328. Break a Palindrome

"""
given a palindrome string of lowercase english letters 'palindrome' replace
exactly one character with any lowercase english letter so that the resulting
string is not a palindrome and that it is the lexicographically smallest one
possible. return the resulting string. if there is no way to replace a
character to make it not a palindrome, return an empty string.
"""


class Solution(object):
    def breakPalindrome(self, palindrome):
        """
        :type palindrome: str
        :rtype: str
        """
        for i in range(len(palindrome) / 2):
            if palindrome[i] != "a":
                return palindrome[:i] + "a" + palindrome[i + 1 :]
        return palindrome[:-1] + "b" if palindrome[:-1] else ""


if __name__ == "__main__":
    obj = Solution()
    print(obj.breakPalindrome(palindrome="abccba"))
    print(obj.breakPalindrome(palindrome="a"))
