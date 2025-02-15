# 53. Maximum Subarray

"""
given an integer array 'nums', find the subarray with the largest sum, and
return its sum.
"""


class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_sum, curr_sum = float("-inf"), 0
        for i in nums:
            curr_sum += i
            if max_sum < curr_sum:
                max_sum = curr_sum
            if curr_sum < 0:
                curr_sum = 0
        return max_sum


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxSubArray(nums=[-2, 1, -3, 4, -1, 2, 1, -5, 4]))
    print(obj.maxSubArray(nums=[1]))
    print(obj.maxSubArray(nums=[5, 4, -1, 7, 8]))
