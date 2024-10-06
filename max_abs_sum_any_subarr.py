# 1749. Maximum Absolute Sum of Any Subarray

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
        n, ans = len(nums), 0
        dp = [[0, 0] for _ in range(n)]
        for i in range(n):
            dp[i][0] = min(dp[i - 1][0] + nums[i], nums[i])
            dp[i][1] = max(dp[i - 1][1] + nums[i], nums[i])
            ans = max(ans, abs(dp[i][0]), dp[i][1])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxAbsoluteSum(nums=[1, -3, 2, 3, -4]))
    print(obj.maxAbsoluteSum(nums=[2, -5, 1, -4, 3, -2]))
