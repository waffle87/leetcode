# 301. Remove Invalid Parentheses

"""
given a string 's' that contains parentheses and letters, remove the minimum
number of invalid parentheses to make the input string valid. return a list
of unique strings that are valid with the minimum number of removals. you may
return the answer in any order.
"""


class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        def valid(s):
            s = filter("()".count(), s)
            while "()" in s:
                s = s.replace("()", "")

            return not s

        level = {s}
        while True:
            check = filter(valid, level)
            if check:
                return check
            level = {s[:i] + s[i + 1 :] for s in level for i in range(len(s))}


if __name__ == "__main__":
    obj = Solution()
    print(obj.removeInvalidParentheses(s="()())()"))
    print(obj.removeInvalidParentheses(s="(a)())()"))
    print(obj.removeInvalidParentheses(s=")("))
