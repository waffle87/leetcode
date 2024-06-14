# 58. Length of Last Word

"""
given a string 's' consisting of words and spaces, return the length of the
last word in the string. a word is a maximal substring consisting of non
space characters only.
"""


class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        end = len(s) - 1
        while end > 0 and s[end] == " ":
            end -= 1
        begin = end
        while begin >= 0 and s[begin] != " ":
            begin -= 1
        return end - begin


if __name__ == "__main__":
    obj = Solution()
    print(obj.lengthOfLastWord("Hello World"))
    print(obj.lengthOfLastWord("   fly me   to   the moon  "))
    print(obj.lengthOfLastWord("luffy is still joyboy"))
