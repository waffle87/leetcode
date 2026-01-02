# 1525. Number of Good Ways to Split a String
from collections import Counter

"""
you are given a string 's'. a split is called good if you can split 's' into
two non-empty strings 's_left' and 's_right' where their concatenation is
equal to 's' (ie. 's_left + s_right = s') and the number of distinct letters
in 's_left' and 's_right' is the same. return the number of good splits you
can make in 's'.
"""


class Solution(object):
    def numSplits(self, s):
        """
        :type s: str
        :rtype: int
        """
        l_map, r_map, cnt = Counter(), Counter(), 0
        for i in s:
            l_map[i] += 1
            r_map[i] -= 1
            if r_map[i] == 0:
                del r_map[i]
            if len(l_map) == len(r_map):
                cnt += 1
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.numSplits(s="aacaba"))
    print(obj.numSplits(s="abcd"))
