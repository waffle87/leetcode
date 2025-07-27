# 2210. Count Hills and Valleys in an Array
from itertools import groupby

"""
you are given a 0-indexed integer array 'nums'. an index 'i' is part of a
hill in 'nums' if the closest non-equal neighbours of 'i' are smaller than
'nums[i]'. similarly, an index 'i' is part of a valley in 'nums' if the
closest non-equal neighbours of 'i' are larger than 'nums[i]'. adjacent
indices 'i' and 'j' are part of the same hill or valley if 'nums[i] ==
nums[j]'. note that for an index to be part of a hill or valley, it must have
a non-equal neighbour on both the left and right of the index. return the
number of hills and valleys in 'nums'.
"""


class Solution(object):
    def countHillValley(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = [i for i, _ in groupby(nums)]
        return sum(l > m < r or l < m > r for l, m, r in zip(a, a[1:], a[2:]))


if __name__ == "__main__":
    obj = Solution()
    print(obj.countHillValley(nums=[2, 4, 1, 1, 6, 5]))
    print(obj.countHillValley(nums=[6, 6, 5, 5, 4, 1]))
