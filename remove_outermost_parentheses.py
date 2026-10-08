# 1021. Remove Outermost Parentheses

"""
a valid parentheses string is either "", "( + A + )", or 'A + B' where 'A'
and 'B' re valid parentheses strings and '+' represents string concatenation.
a valid parentheses string 's' is pimitive if it is non empyt and there does
not exist a way to split it into 's = A + B' with 'A' and 'B' nonempty valid
parentheses strings. given a valid parentheses string 's' consider its
primitive decomposition. return 's' after removing the outermost parentheses
of every primitve string in the primitve decomposition of 's'.
"""


class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        ans, level = [], 0
        for i in s:
            if (i == "(" and level > 0) or (i == ")" and level > 1):
                ans.append(i)
            level += (i == "(") - (i == ")")
        return "".join(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.removeOuterParentheses(s="(()())(())"))
    print(obj.removeOuterParentheses(s="(()())(())(()(()))"))
    print(obj.removeOuterParentheses(s="()()"))
