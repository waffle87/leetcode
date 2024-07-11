# 1190. Reverse Substrings Between Each Pair of Parentheses

"""
you are given a string 's' that consists of lower case english letters and
brackets. reverse the strings in each pair of matching parentheses, starting
from the innermost one. your result should not contain any brackets.
"""


class Solution(object):
    def reverseParentheses(self, s):
        """
        :type s: str
        :rtype: str
        """
        ans = [""]
        for c in s:
            if c == "(":
                ans.append("")
            elif c == ")":
                ans[len(ans) - 2] += ans.pop()[::-1]
            else:
                ans[-1] += c
        return "".join(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.reverseParentheses(s="(abcd)"))
    print(obj.reverseParentheses(s="(u(love)i)"))
    print(obj.reverseParentheses(s="(ed(et(oc))el)"))
