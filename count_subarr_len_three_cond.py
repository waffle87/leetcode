# 3392. Count Subarrays of Length Three With a Condition

"""
given an integer array 'nums', return the number of subarrays of length 3
such that the sum of the first and third number equals exactly half of the
second number.
"""


class Solution(object):
    def countSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(l + r << 1 == m for l, m, r in zip(nums, nums[1:], nums[2:]))


if __name__ == "__main__":
    obj = Solution()
    print(obj.countSubarrays(nums=[1, 2, 1, 4, 1]))
    print(obj.countSubarrays(nums=[1, 1, 1]))
