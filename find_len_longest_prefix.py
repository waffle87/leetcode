# 3043. Find the Length of the Longest Common Prefix

"""
given two arrays with positive integers 'arr1' and 'arr2'. a prefix of a
positive integer is an integer formed by one or more of its digits, starting
from its leftmost digit. a common prefix of two integers 'a' and 'b' is an
integer 'c' such that is a prefix of both a and b. for example 6555359 and
56554 have a common prefix 565 while q223 and 43456 do not have a common
prefix. return the length of the longest common prefix among all pairs. if no
common prefix exists among them, return 0.
"""


class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        return max(
            map(
                len,
                (f := lambda e: {str(v)[:i] for v in e for i in range(9)})(arr1)
                & f(arr2),
            )
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestCommonPrefix(arr1=[1, 10, 100], arr2=[1000]))
    print(obj.longestCommonPrefix(arr1=[1, 2, 3], arr2=[4, 4, 4]))
