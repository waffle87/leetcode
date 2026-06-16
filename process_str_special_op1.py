# 3612. Process String with Special Operations I

"""
you are given a string 's' containing lowercase english letters and the
special characters '*', '#', and '%'. build a new string 'result' by
processing 's' according to the following rules from left to right: if the
letter is a lowercase english letter append it to 'result'. a '*' removes the
last character from 'result'. a '#' duplicates the current 'result' and
appends it to itself. a '%' reverses the current 'result'. return the
resulting string.
"""


class Solution:
    def processStr(self, s: str) -> str:
        ans = ""
        for c in s:
            if c == "*":
                ans = ans[:-1]
            elif c == "#":
                ans += ans
            elif c == "%":
                ans = ans[::-1]
            else:
                ans += c
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.processStr(s="a#b%*"))
    print(obj.processStr(s="z*#"))
