# 2425. Bitwise XOR of All Pairings
from functools import reduce
from operator import xor

"""
you are given two 0-indexed arrays 'nums1' and 'nums2', consisting of
non-negative integers. there exists another array, 'nums3', which contains
the bitwise xor of all pairings of integers between 'nums1' and 'nums2'
(every integer in 'nums1' is paired with every integer in 'nums2' exactly
once). return the bitwise xor of all integers in 'nums3'
"""


class Solution(object):
    def xorAllNums(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        return (len(nums1) % 2 * reduce(xor, nums2)) ^ (
            len(nums2) % 2 * reduce(xor, nums1)
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.xorAllNums(nums1=[2, 1, 3], nums2=[10, 2, 5, 0]))
    print(obj.xorAllNums(nums1=[1, 2], nums2=[3, 4]))
