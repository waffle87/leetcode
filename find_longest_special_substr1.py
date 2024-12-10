# 2981. Find Longest Special Substring That Occurs Thrice I
from collections import defaultdict
from itertools import groupby

"""
you are given a string 's' that consists of lowercase english letters. a
string is called special if it is made up of only a single character. for
example, the string 'abc' is not special, whereas the strongs 'ddd', 'zz',
and 'f' are special. return the length of the longest special substring of
's' which occrs at least thrice, or -1 if no special substring occrs at least
thrice. a substring is a contiguous non-empty sequence of characters within a
string
"""


class Solution(object):
    def maximumLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = defaultdict(int)
        substr = ["".join(sub) for _, sub in groupby(s)]
        for sub in substr:
            d[sub] += 1
            if len(sub) > 1:
                d[sub[1:]] += 2
            if len(sub) > 2:
                d[sub[2:]] += 3
        return max(map(len, filter(lambda x: d[x] > 2, d)), default=-1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumLength(s="aaaa"))
    print(obj.maximumLength(s="abcdef"))
    print(obj.maximumLength(s="abcaba"))
