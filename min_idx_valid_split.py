# 2780. Minimum Index of a Valid Split
from collections import Counter

"""
an element 'x' of an integer array 'arr' of length 'm' is dominant if more
than half the elements of 'arr' have a value of 'x'. you are given a
0-indexed integer array 'nums' of length 'n' with one dominant element. you
can split 'nums' at an index 'i' into two arrays 'nums[0, ..., i]' and
'nums[i + 1, ..., n - 1]', but the split is only valid if '0 <= i < - 1' and
the two arrays have the same dominant element. return the minimum index of a
valid split. if no split exists, return -1.
"""


class Solution(object):
    def minimumIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dominant, cnt = max(Counter(nums).items(), key=lambda x: x[1])
        left, split = 0, 2 * cnt - len(nums)
        if split < 2:
            return -1
        for i, j in enumerate(nums):
            left += 2 * (j == dominant)
            if 1 < left - i <= split:
                return i


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumIndex(nums=[1, 2, 2, 2]))
    print(obj.minimumIndex(nums=[2, 1, 3, 1, 1, 1, 7, 1, 2, 1]))
    print(obj.minimumIndex(nums=[3, 3, 3, 3, 7, 2, 2]))
