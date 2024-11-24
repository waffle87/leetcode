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
        total_sum = sum(nums)
        if total_sum & 1:
            return False
        half_sum, dp = total_sum // 2, 1
        for n in nums:
            dp |= dp << n
        return dp & 1 << half_sum


if __name__ == "__main__":
    obj = Solution()
    print(obj.canPartition(nums=[1, 5, 11, 5]))
    print(obj.canPartition(nums=[1, 2, 3, 5]))
