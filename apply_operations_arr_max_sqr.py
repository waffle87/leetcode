# 2897. Apply Operations on Array to Maximize Sum of Squares
from collections import Counter

"""
you are given a 0-indexed integer array 'nums' and a positive integer 'k'.
you can do the following operation on the array any number of times: choose
any two distinct indices 'i' and 'j' and simultaneously update the values of
'nums[i]' to '(nums[i] & nums[j])' and 'nums[j]' to '(nums[i] | nums[j])'.
you have to choose 'k' elements from the final array and calcluate the sum of
their squares. return the maximum sum of squares you can achieve. since the
answer can be very large, return it modulo 10^9+7.
"""


class Solution(object):
    def maxSum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        cnt = Counter(i for j in nums for i in range(32) if j & (1 << i))
        return sum(sum((cnt[i] > j) << i for i in range(32)) ** 2 for j in range(k)) % (
            10**9 + 7
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxSum(nums=[2, 6, 5, 8], k=2))
    print(obj.maxSum(nums=[4, 5, 4, 7], k=3))
