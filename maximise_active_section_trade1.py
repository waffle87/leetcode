# 3499. Maximize Active Section with Trade I

"""
you are given a binary string 's' of length 'n', where '1' represents an
active seciton, and '0' represents an inactive section. you can perform at
most one trade to maximise the number of active sections in 's'. in a trade,
you can convert a contiguous block of '1's that is surrounded by '0's to all
'0's. afterward, convert a contiguous block of '0's that is surrounded by
'1's to all '1's. return the maximum number of active sections in 's' after
making the optimal trade.
"""

from itertools import groupby, pairwise


class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        g = [len(list(j)) for i, j in groupby(s) if i == "0"]
        return s.count("1") + max(map(sum, pairwise(g)), default=0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxActiveSectionsAfterTrade(s="01"))
    print(obj.maxActiveSectionsAfterTrade(s="0100"))
    print(obj.maxActiveSectionsAfterTrade(s="1000100"))
