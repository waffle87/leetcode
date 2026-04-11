# 3702. Longest Subsequence With Non-Zero Bitwise XOR
from functools import reduce
from operator import xor
from typing import List

"""
you are given an integer array 'nums'. return the length of the longest
subsequence in 'nums' whose bitwise xor is non zero. if no such subsequence
exists, return 0.
"""


class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        n = len(nums)
        if max(nums) == 0:
            return 0
        if reduce(xor, nums) == 0:
            return n - 1
        return n


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestSubsequence(nums=[1, 2, 3]))
    print(obj.longestSubsequence(nums=[2, 3, 4]))
