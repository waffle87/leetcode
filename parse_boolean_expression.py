# 1106. Parsing A Boolean Expression

"""
a boolean expression is an expression that evaluates to either 'true' or
'false'. it can be one of the following shapes:
- 't' that evaluates to true
- 'f' that evaluates to false
- '!(subExpr)' that evalutes to the logical not of the inner expression
'subExpr'
- '&(subExpr1, subExpr2, ..., subExprn)' that evalutes to the logical AND of
the inner expressions 'subExpr1, subExpr2, ..., subExprn' where 'n >= 1'
- '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of
the inner expressions 'subExpr1, subExpr2, ..., subExprn' where 'n >= 1'
given a string 'expression' that represents a boolean expression, return the
evaluation of that expression
"""


class Solution(object):
    def parseBoolExpr(self, expression):
        """
        :type expression: str
        :rtype: bool
        """
        stack = []
        for c in expression:
            if c == ")":
                seen = set()
                while stack[-1] != "(":
                    seen.add(stack.pop())
                stack.pop()
                op = stack.pop()
                stack.append(
                    all(seen)
                    if op == "&"
                    else any(seen)
                    if op == "|"
                    else not seen.pop()
                )
            elif c != ",":
                stack.append(True if c == "t" else False if c == "f" else c)
        return stack.pop()


if __name__ == "__main__":
    obj = Solution()
    print(obj.parseBoolExpr(expression="&(|(f))"))
    print(obj.parseBoolExpr(expression="|(f,f,f,t)"))
    print(obj.parseBoolExpr(expression="!(&(f,t))"))
