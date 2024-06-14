# 198. House Robber

"""
you are a professional robber planning to rob houses along a stree. each
house has a certain amount of money stashed, the only constraint topping you
from robbing each of them is that the adjacent houses have security systems
connected and it will automatically contact the police if two adjacent houses
were broken into on the same night. given an integer array 'nums'
representing the amount of money each house has, return the maximum amount of
money you can rob without alerting the police.
"""


class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return nums[0]
        dp = [*nums]
        dp[1] = max(nums[0], nums[1])
        for i in range(2, len(nums)):
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])
        return dp[-1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.rob([1, 2, 3, 1]))
    print(obj.rob([2, 7, 9, 3, 1]))
