# 150. Evaluate Reverse Polish Notation

"""
given an array of strings 'tokens' that represents an arithmetic expression
in a reverse polish notation. evaluate the expression. return an integer that
represents the value of the expression. note that the valid operators are + -
and /. each operand may be an integer or another expression. the division
between two integers always truncates toward zero. there will not any
division by zero. the input represents a valid arithmetic expression in
reverse polish notation. the answer and all intermediate calculations can be
represented in a 32 bit integer.
"""


class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        for t in tokens:
            if t not in "+-*/":
                stack.append(int(t))
            else:
                r, l = stack.pop(), stack.pop()
                if t == "+":
                    stack.append(l + r)
                elif t == "-":
                    stack.append(l - r)
                elif t == "*":
                    stack.append(l * r)
                else:
                    stack.append(int(float(l) / r))
        return stack.pop()


if __name__ == "__main__":
    obj = Solution()
    print(obj.evalRPN(tokens=["2", "1", "+", "3", "*"]))
    print(obj.evalRPN(tokens=["4", "13", "5", "/", "+"]))
    print(
        obj.evalRPN(
            tokens=["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
        )
    )
