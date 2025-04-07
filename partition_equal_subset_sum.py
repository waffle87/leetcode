# 416. Partition Equal Subset Sum

"""
given an integer array 'nums', return true if you can partition the array
into two subsets such that the sum of the elements in both subsets is equal
or false otherwise
"""


class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        dp = [[-1 for _ in range(((sum(nums) >> 1) + 1))] for _ in range(n)]

        def memo(sm, idx):
            if sm == 0:
                return True
            if idx >= len(nums):
                return False
            if dp[idx][sm] != -1:
                return True if dp[idx][sm] == 1 else False
            pick, no_pick = False, False
            if nums[idx] <= sm:
                pick = memo(sm - nums[idx], idx + 1)
            no_pick = memo(sm, idx + 1)
            dp[idx][sm] = 1 if pick or no_pick else 0
            return True if dp[idx][sm] == 1 else False

        return False if (sum(nums) & 1) else memo(sum(nums) >> 1, 0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.canPartition(nums=[1, 5, 11, 5]))
    print(obj.canPartition(nums=[1, 2, 3, 5]))
