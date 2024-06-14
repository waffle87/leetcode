# 678. Valid Parenthesis String

"""
given a string 's' containing only three types of characters, return true if
's' is valid. the following rules define a valid string: any left parenthesis
must have a corresponding right parenthesis. any right parenthesis must have
a corresponding left parenthesis. left parenthesis must go before the
corresponding right parenthesis. start could be treated as a single right
parenthesis, a single left parenthesis, or an empty string.
"""


class Solution(object):
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        cmin, cmax = 0, 0
        for i in s:
            cmax = cmax - 1 if i == ")" else cmax + 1
            cmin = cmin + 1 if i == "(" else max(cmin - 1, 0)
            if cmax < 0:
                return False
        return cmin == 0


if __name__ == "__main__":
    obj = Solution()
    print(obj.checkValidString("()"))
    print(obj.checkValidString("(*)"))
    print(obj.checkValidString("(*))"))
