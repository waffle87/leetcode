# 594. Longest Harmonious Subsequence
from collections import Counter

"""
we define a harmonious array as an array where the difference between its
maximum value and its minimum value is exactly 1. given an integer array
'nums', return the length of the its longest harmonious subsequnce among all
its possible subsequnces.
"""


class Solution(object):
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        c = Counter(nums)
        return max((c[i] + c[i + 1]) * (c[i + 1] != 0) for i in c)


if __name__ == "__main__":
    obj = Solution()
    print(obj.findLHS(nums=[1, 3, 2, 2, 5, 2, 3, 7]))
    print(obj.findLHS(nums=[1, 2, 3, 4]))
    print(obj.findLHS(nums=[1, 1, 1, 1]))
