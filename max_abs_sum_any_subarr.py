# 1749. Maximum Absolute Sum of Any Subarray
from itertools import accumulate

"""
you are given an integer array 'nums'. the absolute sum of a subarray '[nums,
nums[i + 1], ..., nums[r]]' is 'abs(nums, nums[i], ..., nums[r])'. return the
maximum absolute sum of any (possibly empty) subarray of 'nums'. note that
'abs(x)' is defined as follows: if 'x' is negative integer, then 'abs(x) =
-x'. if 'x' is a non negative integer, then 'abs(x) = x'
"""


class Solution(object):
    def maxAbsoluteSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return max(accumulate(nums, initial=0)) - min(accumulate(nums, initial=0))


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxAbsoluteSum(nums=[1, -3, 2, 3, -4]))
    print(obj.maxAbsoluteSum(nums=[2, -5, 1, -4, 3, -2]))
