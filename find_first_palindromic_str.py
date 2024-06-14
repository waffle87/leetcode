# 2108. Find First Palindromic String in the Array

"""
given an array of strings 'words', return the first palindromic string in the
array. if there is no such string, return an empty string. a string is a
palindromic if it reads the same forward and backward.
"""


class Solution(object):
    def firstPalindrome(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        for w in words:
            if w == w[::-1]:
                return w
        return ""


if __name__ == "__main__":
    obj = Solution()
    print(obj.firstPalindrome(words=["abc", "car", "ada", "racecar", "cool"]))
    print(obj.firstPalindrome(words=["notapalindrome", "racecar"]))
    print(obj.firstPalindrome(words=["def", "ghi"]))
