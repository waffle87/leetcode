# 3512. Minimum Operations to Make Array Sum Divisible by K

"""
you are given an integer array 'nums' and an integer 'k'. you can perform the
following operation any number of times: select an index 'i' and replace
'nums[i]' with 'nums[i] - 1'. return the minimum number of operations to make
the sum of the array divisible by 'k'.
"""


class Solution(object):
    def minOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return sum(nums) % k


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations(nums=[3, 9, 7], k=5))
    print(obj.minOperations(nums=[4, 1, 3], k=4))
    print(obj.minOperations(nums=[3, 2], k=6))
