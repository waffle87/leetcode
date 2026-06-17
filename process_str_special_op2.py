# 3614. Process String with Special Operations II

"""
you are given a string 's' consisting of lowercase english letters and the
special characters '*', '#', and '%'. you are also given an integer 'k'.
build a new string 'result' by processing 's' according to the following
rules from left to right: if the letter is a lowercase english letter append
it to 'result'. a '*' removes the last character from 'result'. a '#'
duplicates the current 'result' and appends it to itself. a '%' reverses the
current 'result'. return the k'th character of the final string 'result'. if
'k' is out of the bounds of 'result', return '.'.
"""


class Solution:
    def processStr(self, s: str, k: int) -> str:
        l, p = 0, k
        for c in s:
            if c == "*":
                if l > 0:
                    l -= 1
            elif c == "#":
                l *= 2
            elif c == "%":
                pass
            else:
                l += 1
        if k >= l:
            return "."
        for c in s[::-1]:
            if c == "*":
                l += 1
            elif c == "#":
                if p >= l // 2:
                    p -= l // 2
                l = l // 2
            elif c == "%":
                p = (l - 1) - p
            else:
                if l == p + 1:
                    return c
                l -= 1
        return s[p]


if __name__ == "__main__":
    obj = Solution()
    print(obj.processStr(s="a#b%*", k=1))
    print(obj.processStr(s="cd%#*#", k=3))
    print(obj.processStr(s="z*#", k=0))
