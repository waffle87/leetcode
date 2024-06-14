# 300. Longest Increasing Subsequence

"""
given an integer array 'nums', return the length of the longest strictly
increasing subsequence.
"""


class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        dp = [1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)


if __name__ == "__main__":
    obj = Solution()
    print(obj.lengthOfLIS(nums=[10, 9, 2, 5, 3, 7, 101, 18]))  # expect: 4
    print(obj.lengthOfLIS(nums=[0, 1, 0, 3, 2, 3]))  # expect: 4
    print(obj.lengthOfLIS(nums=[7, 7, 7, 7, 7, 7, 7]))  # expect: 1
