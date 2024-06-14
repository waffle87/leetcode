# 3110. Score of a String

"""
you are given a string 's'. the score of a string is defined as the sume of
the absolute different between the ascii values of adjacent characters.
return the score of 's'.
"""


class Solution(object):
    def scoreOfString(self, s):
        """
        :type s: str
        :rtype: int
        """
        return sum(abs(ord(s[i]) - ord(s[i + 1])) for i in range(len(s) - 1))


if __name__ == "__main__":
    obj = Solution()
    print(obj.scoreOfString("hello"))
    print(obj.scoreOfString("zaz"))
