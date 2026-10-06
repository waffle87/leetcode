# 921. Minimum Add to Make Parentheses Valid

"""
a parentheses string is valid if and only if it is empty string, it can be
written as AB (A concatenated with B), where A and B are valid strings, or it
can be written as (A) where A is a valid string. you are given a parentheses
string 's'. in one move you can insert a parentheses at any position of the
string. return the minimum number of moves required to make 's' valid
"""


class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        open, close = 0, 0
        for i in s:
            if i == "(":
                open += 1
            elif open > 0:
                open -= 1
            else:
                close += 1
        return open + close


if __name__ == "__main__":
    obj = Solution()
    print(obj.minAddToMakeValid(s="())"))
    print(obj.minAddToMakeValid(s="((("))
