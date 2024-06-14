# 795. Number of Subarrays with Bounded Maximum

"""
given an integer array 'nums' and two integers 'left' and 'right', return the
number of contiguous non empty subarrays such that the value of the maximum
array element in that subarray is in the range '[left, right]'. the test
cases are generated such that the answer will fit into a 32 bit integer.
"""


class Solution(object):
    def numSubarrayBoundedMax(self, nums, left, right):
        """
        :type nums: List[int]
        :type left: int
        :type right: int
        :rtype: int
        """
        ans, prev, dp = 0, -1, 0
        for i in range(len(nums)):
            if nums[i] < left and i > 0:
                ans += dp
            if nums[i] > right:
                dp = 0
                prev = i
            if left <= nums[i] <= right:
                dp = i - prev
                ans += dp
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.numSubarrayBoundedMax(nums=[2, 1, 4, 3], left=2, right=3))
    print(obj.numSubarrayBoundedMax(nums=[2, 9, 2, 5, 6], left=2, right=8))
