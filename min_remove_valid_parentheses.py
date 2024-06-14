# 1249. Minimum Remove to Make Valid Parentheses

"""
given a string s of '(' and ')' and lowercase english characters. your task
is to remove the minimum number of parentheses so that the resulting
parentheses string is valid and return any valid string. formally, a
parentheses string is valid if and only if it is the empty string, contains
only lowercase characters, or it can be written as AB where A and B are valid
strings, or it can be written as (A) where A is a valid string.
"""


class Solution(object):
    def minRemoveToMakeValid(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = list(s)
        stack = []
        for i, c in enumerate(s):
            if c == "(":
                stack.append(i)
            elif c == ")":
                if stack:
                    stack.pop()
                else:
                    s[i] = ""
        while stack:
            s[stack.pop()] = ""
        return "".join(s)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minRemoveToMakeValid(s="lee(t(c)o)de)"))
    print(obj.minRemoveToMakeValid(s="a)b(c)d"))
    print(obj.minRemoveToMakeValid(s="))(("))
