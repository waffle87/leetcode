# 1464. Maximum Product of Two Elements in an Array
from heapq import nlargest

"""
given the array of integers 'nums', you will choose two different indices 'i'
and 'j' of thatarray. return the maximum value of '(nums[i] - 1)  (nums[j] -
1)'
"""


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        return ((x := nlargest(2, nums))[0] - 1) * (x[1] - 1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxProduct(nums=[3, 4, 5, 2]))
    print(obj.maxProduct(nums=[1, 5, 4, 5]))
    print(obj.maxProduct(nums=[3, 7]))
