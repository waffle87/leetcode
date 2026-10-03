# 32. Longest Valid Parentheses

"""
given a string containing just the characters '(' and ')', return the length
of the longest valid parentheses substring.
"""


class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack, ans = [-1], 0
        for i in range(len(s)):
            if s[i] == "(":
                stack.append(i)
            else:
                stack.pop()
                if len(stack) == 0:
                    stack.append(i)
                else:
                    ans = max(ans, i - stack[-1])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestValidParentheses(s="(()"))
    print(obj.longestValidParentheses(s=")()())"))
    print(obj.longestValidParentheses(s=""))
