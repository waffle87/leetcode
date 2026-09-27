# 1190. Reverse Substrings Between Each Pair of Parentheses

"""
you are given a string 's' that consists of lower case english letters and
brackets. reverse the strings in each pair of matching parentheses, starting
from the innermost one. your result should not contain any brackets.
"""


class Solution:
    def reverseParentheses(self, s: str) -> str:
        n = len(s)
        link, stack = [0] * n, []
        for i, j in enumerate(s):
            if j == "(":
                stack.append(i)
            elif j == ")":
                k = stack.pop()
                link[i] = k
                link[k] = i
        ans, dir, i = [], 1, 0
        while i < n:
            c = s[i]
            if c == "(" or c == ")":
                i = link[i]
                dir = -dir
            else:
                ans.append(c)
            i += dir
        return "".join(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.reverseParentheses(s="(abcd)"))
    print(obj.reverseParentheses(s="(u(love)i)"))
    print(obj.reverseParentheses(s="(ed(et(oc))el)"))
