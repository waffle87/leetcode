# 2270. Number of Ways to Split Array

"""
you are given a 0-indexed integer array 'nums' of lenght 'n'. 'nums' contains
a valid split at index 'i' if the following are true: the sum of the first 'i
+ 1' elements is greater than or equal to the sum of the last 'n - i - 1'
elements, and there is at least one element to the right of 'i'. return the
number of valid splits in 'nums'.
"""


class Solution(object):
    def waysToSplitArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        end, start = 0, 0
        for i in range(0, len(nums)):
            end += nums[i]
        ans = 0
        for i in range(0, len(nums) - 1):
            start += nums[i]
            end -= nums[i]
            if start >= end:
                ans += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.waysToSplitArray(nums=[10, 4, -8, 7]))
    print(obj.waysToSplitArray(nums=[2, 3, 1, 0]))
