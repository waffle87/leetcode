# 1800. Maximum Ascending Subarray Sum

"""
given an array of positive integers 'nums', return the maximum possible sum
of an ascending subarray in 'nums'. a subarray is defined as a contiguous
sequence of numbers in an array.
"""


class Solution(object):
    def maxAscendingSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans, sum = 0, nums[0]
        for i in range(len(nums)):
            if nums[i] <= nums[i - 1]:
                ans = max(ans, sum)
                sum = 0
            sum += nums[i]
        return max(ans, sum)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxAscendingSum(nums=[10, 20, 30, 5, 10, 50]))
    print(obj.maxAscendingSum(nums=[10, 20, 30, 40, 50]))
    print(obj.maxAscendingSum(nums=[12, 17, 15, 13, 10, 11, 12]))
