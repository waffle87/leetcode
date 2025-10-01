# 2232. Minimize Result by Adding Parentheses to Expression

"""
you are given a 0-indexed string 'expression' of the form 'num1+num2' where
'num1' and 'num2' represent integers. add a pair of parentheses to
'expression' such that after the addition of parentheses, 'expression' is a
valid mathematical expression and evaluates to the smallest possible value.
the left parenthesis must be added to the left of '+', and the right
parenthesis must be added to the right of '+'. return 'expression' after
adding a pair of parentheses such that 'expression' evaluates to the smallest
possible value. if multiple answers that yield the same result, return any of
them.
"""


class Solution(object):
    def minimizeResult(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        left, right = expression.split("+")
        value = lambda s: eval(s.replace("(", "*(").replace(")", ")*").strip("*"))
        l = [left[0:i] + "(" + left[i:] for i in range(len(left))]
        r = [right[0:i] + ")" + right[i:] for i in range(1, len(right) + 1)]
        return min([i + "+" + j for i in l for j in r], key=value)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimizeResult(expression="247+38"))
    print(obj.minimizeResult(expression="12+34"))
    print(obj.minimizeResult(expression="999+999"))
