# 3876. Construct Uniform Parity Array II
from functools import reduce

"""
you are given an array 'nums1' of 'n' distinct integers. you want to
construct another array 'nums2' of length 'n' such that the elements in
'nums2' are either all odd or all even. for each index 'i', you must choose
exactly one of the following: 'nums2[i] = nums1[i]', or 'nums2[i] = nums1[i]
- nums1[j]' for any index 'j != i' such that 'nums1[i] - nums1[j] >= 1'.
return true if it is possible to construct such an array, otherwise return
false.
"""


class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        return (min(nums1) & 1) == 1 or (reduce(or_, nums1) & 1) == 0


if __name__ == "__main__":
    obj = Solution()
    print(obj.uniformArray(nums1=[1, 4, 7]))
    print(obj.uniformArray(nums1=[2, 3]))
    print(obj.uniformArray(nums1=[4, 6]))
