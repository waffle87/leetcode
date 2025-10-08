# 2300. Successful Pairs of Spells and Potions
from bisect import bisect_left
from math import ceil

"""
given two positive integer arrays 'spells' and 'potions', of length n and m
respectively where 'spells[i]' represents the strength of the i'th spell and
'potions[j] represents the strength of the j'th potion. also given an integer
success. a spell and potion pair is considered successful if the product of
their strengths is at least 'success'. return an integer array 'pairs' of
lengthn where 'pairs[i]' is the number of potions that will form a successful
pair with the i'th spell.
"""


class Solution(object):
    def successfulPairs(self, spells, potions, success):
        """
        :type spells: List[int]
        :type potions: List[int]
        :type success: int
        :rtype: List[int]
        """
        potions.sort()
        n, ans = len(potions), []
        for i in spells:
            req = ceil(success / i)
            if req > potions[-1]:
                ans.append(0)
                continue
            idx = bisect_left(potions, req)
            ans.append(n - idx)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.successfulPairs(spells=[5, 1, 3], potions=[1, 2, 3, 4, 5], success=7))
    print(obj.successfulPairs(spells=[3, 1, 2], potions=[8, 5, 8], success=16))
