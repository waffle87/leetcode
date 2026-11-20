# 3041. Maximize Consecutive Elements in an Array After Modification
from collections import defaultdict


class Solution:
    def maxSelectedElements(self, nums: list[int]) -> int:
        dp = defaultdict(int)
        for i in sorted(nums):
            dp[i + 1] = dp[i] + 1
            dp[i] = dp[i - 1] + 1
        return max(dp.values())


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxSelectedElements(nums=[2, 1, 5, 1, 1]))
    print(obj.maxSelectedElements(nums=[1, 4, 7, 10]))
