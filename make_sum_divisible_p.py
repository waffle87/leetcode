# 1590. Make Sum Divisible by P

"""
given an array of positive integers 'nums', remove the smallest subarray
(possibly empty) such that the sum of the remaining elements is divisible by
'p'. it is not allowed to remove the whole array. return the length of the
smallest subarray that you need to remove, or -1 if it is impossible. a
subarray is defined as a contiguous block of elements in the array.
"""


class Solution(object):
    def minSubarray(self, nums, p):
        """
        :type nums: List[int]
        :type p: int
        :rtype: int
        """
        req = sum(nums) % p
        dp, curr = {0: -1}, 0
        ans = n = len(nums)
        for i, j in enumerate(nums):
            curr = (curr + j) % p
            dp[curr] = i
            if (curr - req) % p in dp:
                ans = min(ans, i - dp[(curr - req) % p])
        return ans if ans < n else -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.minSubarray(nums=[3, 1, 4, 2], p=6))
    print(obj.minSubarray(nums=[6, 3, 5, 2], p=9))
    print(obj.minSubarray(nums=[1, 2, 3], p=3))
