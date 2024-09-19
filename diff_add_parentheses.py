# 241. Different Ways to Add Parentheses

"""
given a string 'expression' of numbers and operators, return all possible
results from computing all the different possible ways to group numbers and
operators. you may return the answer in any order. the test cases are
generated such that the output values fit in a 32-bit integer and the number
of different results does not exceed 10^4
"""


class Solution(object):
    def dfs(self, expression, m):
        if expression in m:
            return m[expression]
        if expression.isdigit():
            m[expression] = int(expression)
            return [int(expression)]
        res = []
        for i, j in enumerate(expression):
            if j in "+-*":
                l = self.diffWaysToCompute(expression[:i])
                r = self.diffWaysToCompute(expression[i + 1 :])
                res.extend(eval(str(x) + j + str(y)) for x in l for y in r)
        m[expression] = res
        return res

    def diffWaysToCompute(self, expression):
        """
        :type expression: str
        :rtype: List[int]
        """
        m = {}
        return self.dfs(expression, m)


if __name__ == "__main__":
    obj = Solution()
    print(obj.diffWaysToCompute(expression="2-1-1"))
    print(obj.diffWaysToCompute(expression="2*3-4*5"))
