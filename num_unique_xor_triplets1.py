# 3513. Number of Unique XOR Triplets I
from typing import List

"""
you are given an integer array 'nums' of length 'n', where 'nums' is a
permutation of the numbers in the range '[1, n]'. a xor triplet is defined as
the xor of three elements 'nums[i] ^ nums[j] ^ nums[k]' where 'i <= j <= k'.
return the number of unique xor triplet values from each possible triplets
'(i, j, k)'.
"""


class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        n = len(nums)
        return 1 << (n.bit_length() - 3 // (n + 1))


if __name__ == "__main__":
    obj = Solution()
    print(obj.uniqueXorTriplets(nums=[1, 2]))
    print(obj.uniqueXorTriplets(nums=[3, 1, 2]))
