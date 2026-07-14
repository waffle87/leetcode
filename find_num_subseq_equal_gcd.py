# 3336. Find the Number of Subsequences With Equal GCD
from math import gcd
from typing import List

"""
you are given an integer array 'nums'. your task is to find the number of
pairs of non-empty subsequences '(seq1, seq2)' of 'nums' that satisfy the
following conditions. the subsequences 'seq1' and 'seq2' are disjoint,
meaning no index of 'nums' is common between them. the gcd of the element of
'seq1' is equal to the gcd of the elements of 'seq2'. return the total number
of such pairs. since the answer may be very large, return it modulo 10^9 + 7.
"""


class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        def dfs(i, a, b):
            if i == len(nums):
                return 1 if a == b else 0
            mod = 10**9 + 7
            return (
                dfs(i + 1, a, b)
                + dfs(i + 1, gcd(a, nums[i]), b)
                + dfs(i + 1, a, gcd(b, nums[i]))
            ) % mod

        return dfs(0, 0, 0) - 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.subsequencePairCount(nums=[1, 2, 3, 4]))
    print(obj.subsequencePairCount(nums=[10, 20, 30]))
    print(obj.subsequencePairCount(nums=[1, 1, 1, 1]))
