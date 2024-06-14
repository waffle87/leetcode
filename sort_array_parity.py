# 905. Sort Array By Parity

"""
given an integer array 'nums', move all the even integers at the beginning of
the array followed by all the odd integers. return any array that satisfies
this condition
"""

class Solution(object):
    def sortArrayByParity(self, nums):
        left = 0
        for i in range(len(nums)):
            if nums[i] % 2 == 0:
                nums[left], nums[i] = nums[i], nums[left]
                left += 1
        return nums
