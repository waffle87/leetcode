# 1513. Number of Substrings With Only 1s

"""
given a binary string 's', return the number of substrings with all
characters 1's since the answer may be too large, return it modulo 1e9+7.
"""


class Solution(object):
    def numSub(self, s):
        """
        :type s: str
        :rtype: int
        """
        return sum(len(a) * (len(a) + 1) / 2 for a in s.split("0")) % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    print(obj.numSub("0110111"))
    print(obj.numSub("101"))
    print(obj.numSub("111111"))
