# 2897. Apply Operations on Array to Maximize Sum of Squares

"""
you are given a 0-indexed integer array 'nums' and a positive integer 'k'.
you can do the following operation on the array any number of times: choose
any two distinct indices 'i' and 'j' and simultaneously update the values of
'nums[i]' to '(nums[i] & nums[j])' and 'nums[j]' to '(nums[i] | nums[j])'.
you have to choose 'k' elements from the final array and calcluate the sum of
their squares. return the maximum sum of squares you can achieve. since the
answer can be very large, return it modulo 10^9+7.
"""


class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:
        n, ans = len(nums), 0
        idx = [0] * 32
        arr = [0] * n
        for i in nums:
            for j in range(32):
                if (i >> j) & 1:
                    arr[idx[j]] += 1 << j
                    idx[j] += 1
        for i in range(k):
            ans += arr[i] ** 2
            ans %= 10**9 + 7
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxSum(nums=[2, 6, 5, 8], k=2))
    print(obj.maxSum(nums=[4, 5, 4, 7], k=3))
