# 22. Generate Parentheses

"""
given 'n' pairs of parentheses, write a function to generate all combinations
of well-formed parentheses.
"""


class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        ans = []

        def dfs(left, right, s):
            if len(s) == n * 2:
                ans.append(s)
                return
            if left < n:
                dfs(left + 1, right, s + "(")
            if right < left:
                dfs(left, right + 1, s + ")")

        dfs(0, 0, "")
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.generateParenthesis(n=3))
    print(obj.generateParenthesis(n=1))
