# 844. Backspace String Compare
from functools import reduce

"""
given two strings 's' and 't', return 'true' if they are equal when both are
typed into empty text editors. '#' means a backspace character. note that
after backspacing an empty text, the text will continue empty.
"""


class Solution(object):
    def back(self, res, c):
        if c != "#":
            res.append(c)
        elif res:
            res.pop()
        return res

    def backspaceCompare(self, s, t):
        return reduce(self.back, s, []) == reduce(self.back, t, [])


if __name__ == "__main__":
    obj = Solution()
    print(obj.backspaceCompare(s="ab#c", t="ad#c"))  # expect: 1
    print(obj.backspaceCompare(s="ab##", t="c#d#"))  # expect: 1
    print(obj.backspaceCompare(s="a#c", t="b"))  # expect: 0
