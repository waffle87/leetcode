# 432. Count Partitions with Even Sum Difference

"""
you are given an integer array 'nums' of length 'n'. a partition is defined
as an index 'i' where '0 <= i < n - 1', splitting the array into two
non-empty subarrays such that left subarray contains indices '[0, i]' and the
right subarray contains indices '[i + 1, n - 1]'. return the number of
partitions where the difference between the sum of the left and right
subarrays is even.
"""


class Solution(object):
    def countPartitions(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        parity = nums.pop() & 1
        for i in nums:
            parity ^= i & 1
        return (parity ^ 1) * len(nums)


if __name__ == "__main__":
    obj = Solution()
    print(obj.countPartitions(nums=[10, 10, 3, 7, 6]))
    print(obj.countPartitions(nums=[1, 2, 2]))
    print(obj.countPartitions(nums=[2, 4, 6, 8]))
