# 3105. Longest Strictly Increasing or Strictly Decreasing Subarray

"""
you are given an array of integers 'nums'. return the legnth of the longest
subarray of 'nums' which is either strictly increasing or strictly
decreasing.
"""


class Solution(object):
    def longestMonotonicSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n, ans, inc, dec = len(nums), 1, 1, 1
        for i in range(1, n):
            a, b = nums[i] > nums[i - 1], nums[i] < nums[i - 1]
            inc = a * inc + 1
            dec = b * dec + 1
            ans = max(ans, dec, inc)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestMonotonicSubarray(nums=[1, 4, 3, 3, 2]))
    print(obj.longestMonotonicSubarray(nums=[3, 3, 3, 3]))
    print(obj.longestMonotonicSubarray(nums=[3, 2, 1]))
