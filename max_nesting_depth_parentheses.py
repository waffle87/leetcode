# 1614. Maximum Nesting Depth of the Parentheses

"""
given a valid parentheses string 's', return the nestign depth of 's'. the
nesting depth is the maximum number of nested parentheses.
"""

from itertools import accumulate


class Solution:
    def maxDepth(self, s: str) -> int:
        return max(accumulate(1 if i == "(" else -1 if i == ")" else 0 for i in s))


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxDepth("(1+(2*3)+((8)/4))+1"))
    print(obj.maxDepth("(1)+((2))+(((3)))"))
