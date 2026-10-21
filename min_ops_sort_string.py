# 3863. Minimum Operations to Sort a String

"""
you are given a string 's' consisting of lowercase english letters. in one
operation, you can select any substring of 's' that is not the entire string
and sort it in non-descending alphabetical order. return the minimum number
of operations required to make 's' sorted in non-descending order. if it is
not possible, return -1.
"""

from itertools import pairwise


class Solution:
    def minOperations(self, s: str) -> int:
        if len(s) == 2 and s[0] > s[1]:
            return -1
        for i, j in pairwise(s):
            if i > j:
                break
            else:
                return 0
        mn, mx = min(s[1:-1]), max(s[1:-1])
        left, right = s[0], s[~0]
        if left <= min(right, mn) or right >= max(left, mx):
            return 1
        elif right >= mn or left <= mx:
            return 2
        else:
            return 3


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations(s="dog"))
    print(obj.minOperations(s="card"))
    print(obj.minOperations(s="gf"))
