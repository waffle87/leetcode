# 238. Product of Array Except Self
from functools import reduce

"""
given an integer array 'nums' return an array 'answer' such that 'answer[i]'
is equal to the product of all the elements of 'nums' except 'nums[i]'. the
product of any prefix or suffix of 'nums' is guaranteed to fit in a 32-bit
integer. you must write an algorithm that runs in O(n) time and without the
division operation.
"""


class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        prod, zero_cnt = reduce(lambda a, b: a * (b if b else 1), nums, 1), nums.count(
            0
        )
        if zero_cnt > 1:
            return [0] * len(nums)
        for i, c in enumerate(nums):
            if zero_cnt:
                nums[i] = 0 if c else prod
            else:
                nums[i] = prod // c
        return nums


if __name__ == "__main__":
    obj = Solution()
    print(obj.productExceptSelf([1, 2, 3, 4]))
    print(obj.productExceptSelf([-1, 1, 0, -3, 3]))
