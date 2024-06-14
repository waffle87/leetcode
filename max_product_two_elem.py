# 1464. Maximum Product of Two Elements in an Array
import math

"""
given the array of integers 'nums', you will choose two different indices 'i'
and 'j' of thatarray. return the maximum value of '(nums[i] - 1)  (nums[j] -
1)'
"""


class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max1 = max2 = -math.inf
        for n in nums:
            if n > max1:
                max2 = max1
                max1 = n
            elif n > max2:
                max2 = n
        return (max1 - 1) * (max2 - 1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxProduct([3, 4, 5, 2]))
    print(obj.maxProduct([1, 5, 4, 5]))
    print(obj.maxProduct([3, 7]))
