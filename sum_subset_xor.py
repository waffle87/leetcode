# 1863. Sum of All Subset XOR Totals
from functools import reduce
from operator import or_

"""
the xor total of an array is defined as the bitwise xor of all its elements
or 0 if the array is empty. given an array 'nums' return the sum of all xor
totals for every subset of 'nums'. an array 'a' is a subset of an array 'b'
if 'a' can be obtained from 'b' by deleting some elements of 'b'.
"""


class Solution(object):
    def subsetXORSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return reduce(or_, nums) << (len(nums) - 1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.subsetXORSum(nums=[1, 3]))
    print(obj.subsetXORSum(nums=[5, 1, 6]))
    print(obj.subsetXORSum(nums=[3, 4, 5, 6, 7, 8]))
