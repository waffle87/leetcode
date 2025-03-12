# 2529. Maximum Count of Positive Integer and Negative Integer
from bisect import bisect_left

"""
given an array 'nums' sorted in non-decreasing order, return the maximum
between the number of positive integers and he number of negative integers.
note that '0' is neither positive nor negative.
"""


class Solution(object):
    def maximumCount(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return max(bisect_left(nums, 0), len(nums) - bisect_left(nums, 1))


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumCount(nums=[-2, -1, -1, 1, 2, 3]))
    print(obj.maximumCount(nums=[-3, -2, -1, 0, 0, 1, 2]))
    print(obj.maximumCount(nums=[5, 20, 66, 1314]))
