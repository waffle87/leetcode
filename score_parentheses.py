# 856. Score of Parentheses

"""
given the balanced parentheses string '', return the score of the string.
the score of a balanced parentheses string is based on the following rules:
'()' has a score of 1, 'AB' has a score of A + B where A and B are valid
parentheses strings, and '(A)' has a score of '2  A' where A is the balanced
parentheses string.
"""


class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        ans, balance = 0, 0
        for i, j in enumerate(s):
            if j == "(":
                balance += 1
            else:
                balance -= 1
                if s[i - 1] == "(":
                    ans += 1 << balance
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.scoreOfParentheses(s="()"))
    print(obj.scoreOfParentheses(s="(())"))
    print(obj.scoreOfParentheses(s="()()"))
