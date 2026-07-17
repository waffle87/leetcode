# 3312. Sorted GCD Pair Queries

"""
you are given an integer array 'nums' of length 'n' and an integer array
'queries'. let 'gcd_pairs' denote an array obtained by calculating the gcd of
all possible '(nums[i], nums[j])' where '0 <= i < j < n' and then sorting
these values in ascending order. for each query 'queries[i]', you need to
find the element at index 'queries[i]' in 'gcd_pairs'. return an integer
array 'answer' where 'answer[i]' is the value at 'gcd_pairs[queries[i]]' for
each query.
"""

from bisect import bisect_right
from itertools import accumulate
from typing import List


class Solution:
    def gcdValues(self, nums: List[int], queries: List[int]) -> List[int]:
        max_val = max(nums)
        gcd = [0] * (max_val + 1)
        freq = [0] * (max_val + 1)
        for i in nums:
            freq[i] += 1
        for i in range(max_val, 0, -1):
            total = sum(freq[i::i])
            gcd[i] = total * (total - 1) // 2 - sum(gcd[i::i])
        gcd = list(accumulate(gcd))
        return [bisect_right(gcd, i) for i in queries]


if __name__ == "__main__":
    obj = Solution()
    print(obj.gcdValues(nums=[2, 3, 4], queries=[0, 2, 2]))
    print(obj.gcdValues(nums=[4, 4, 2, 1], queries=[5, 3, 1, 0]))
    print(obj.gcdValues(nums=[2, 2], queries=[0, 0]))
