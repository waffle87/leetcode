# 3364. Minimum Positive Sum Subarray

"""
you are given an integer array 'nums' and two integers 'l' and 'r'. your task
is to find the minimum sum of a subarrray whose size is between 'l' and 'r'
(inclusive) and whose sum is greater than 0. return the minimum sum of such a
subarray. if no such subarray exists, return -1.
"""

from bisect import bisect_left, insort
from itertools import accumulate


class Solution:
    def minimumSumSubarray(self, nums: list[int], l: int, r: int) -> int:
        pre = [0, *accumulate(nums)]
        best, starts, w = float("inf"), [], r - l + 1
        for t, curr in enumerate(pre[l:]):
            insort(starts, pre[t])
            if t >= w:
                del starts[bisect_left(starts, pre[t - w])]
            k = bisect_left(starts, curr)
            if k and curr - starts[k - 1] < best:
                best = curr - starts[k - 1]
        return -1 if best == float("inf") else best


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumSumSubarray(nums=[3, -2, 1, 4], l=2, r=3))
    print(obj.minimumSumSubarray(nums=[-2, 2, -3, 1], l=2, r=3))
    print(obj.minimumSumSubarray(nums=[1, 2, 3, 4], l=2, r=4))
