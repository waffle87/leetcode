# 3514. Number of Unique XOR Triplets II
from typing import List

"""
you are given an integer array 'nums'. an xor triplet is defined as the xor
of three elements 'nums[i] ^ nums[j] ^ nums[k]' where 'i <= j <= k'. return
the number of unique xor triplet values from all possible triplets '(i, j,
k)'.
"""


class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        max_xor, n = 2048, len(nums)
        pair = [False] * max_xor
        triplet = [False] * max_xor
        for i in range(n):
            for j in range(i, n):
                pair[nums[i] ^ nums[j]] = True
        for i in range(max_xor):
            if not pair[i]:
                continue
            for j in nums:
                triplet[i ^ j] = True
        return sum(triplet)


if __name__ == "__main__":
    obj = Solution()
    print(obj.uniqueXorTriplets(nums=[1, 3]))
    print(obj.uniqueXorTriplets(nums=[6, 7, 8, 9]))
