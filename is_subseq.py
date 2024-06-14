# 392. Is Subsequence

"""
given two strings 's' and 't', return 'true' if 's' is a subsequnce of 't' or
'false' otherwise. a subsequnce of a string is a new string that is formed
from the original string by deleting some (can be none) of the characters
without disturbing the relative positions of the remaining characters (ie.
"ace" is a subsequnce of "abcde", while "aec" is not).
"""


class Solution(object):
    def isSubsequence(self, s, t):
        if len(s) > len(t):
            return False
        if len(s) == 0:
            return True
        subsequnce = 0
        for i in range(0, len(t)):
            if subsequnce <= len(s) - 1:
                # print(s[subsequnce])
                if s[subsequnce] == t[i]:
                    subsequnce += 1
        return subsequnce == len(s)


if __name__ == "__main__":
    obj = Solution()
    print(obj.isSubsequence("abc", "ahbgdc"))  # expect: True
    print(obj.isSubsequence("axc", "ahbgdc"))  # expect: False
