# 3381. Maximum Subarray Sum With Length Divisible by K
from itertools import accumulate

"""
you are given an array of integers 'nums' and an integer 'k'. return the
maximum sum of a subarray of 'nums', such that the size of the subarray is
divisble by 'k'.
"""


class Solution(object):
    def maxSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        pre, ans = k * [float("inf")], float("-inf")
        pre[-1] = 0
        for i, j in enumerate(accumulate(nums)):
            ans = max(ans, j - pre[i % k])
            pre[i % k] = min(pre[i % k], j)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxSubarraySum(nums=[1, 2], k=1))
    print(obj.maxSubarraySum(nums=[-1, -2, -3, -4, -5], k=4))
    print(obj.maxSubarraySum(nums=[-5, 1, 2, -3, 4], k=2))
