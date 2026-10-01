# 20. Valid Parentheses

"""
given a string 's' containing just the characters '(, ), {, }, [, ]',
determine if the input string is valid. a input string is valid if open
brackets must be closed by the same type of brackets. open brackets must be
closed in the correct order. every close bracket has a corresponding open
bracket of the same type.
"""


class Solution:
    def isValid(self, s: str) -> bool:
        while len(s) > 0:
            n = len(s)
            s = s.replace("()", "").replace("{}", "").replace("[]", "")
            if n == len(s):
                return False
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.isValid(s="()"))
    print(obj.isValid(s="()[]{}"))
    print(obj.isValid(s="(]"))
