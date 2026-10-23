# 3644. Maximum K to Sort a Permutation

"""
you are given an integer array 'nums' of length 'n' where 'nums' is a
permutation of the numbers in the range '[0 ... n - 1]'. you may swap
elements at indices 'i' and 'j' only if 'nums[i] & nums[j] == k' where '&'
denote the bitwise and operation. return the maximum value of 'k' such that
the array can be sorted in non-decreasing order using any number of such
swaps. if 'nums' is already sorted, return 0.
"""

from functools import reduce
from operator import and_


class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        return max(reduce(and_, (j for i, j in enumerate(nums) if j != i), -1), 0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.sortPermutation(nums=[0, 3, 2, 1]))
    print(obj.sortPermutation(nums=[0, 1, 3, 2]))
    print(obj.sortPermutation(nums=[3, 2, 1, 0]))
