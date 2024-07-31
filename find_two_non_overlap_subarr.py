# 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
from itertools import accumulate

"""
you are given an array of integers 'arr' and an integer 'target'. you have to
find two non overlapping subarrays of 'arr' each with a sum equal to
'target'. there can be multiple answers so you have to finmd an answer where
the sum of the lengths of the two subarrays is minimum. return the minimum
sum of the lengths of the two required subarrays or return -1 if you cannot
find such two subarrays.
"""


class Solution(object):
    def minSumOfLengths(self, arr, target):
        """
        :type arr: List[int]
        :type target: int
        :rtype: int
        """
        prefix = {0: -1}
        curr_bestl = [float("inf")] * len(arr)
        ans, best = float("inf"), float("inf")
        for i, curr in enumerate(accumulate(arr)):
            if curr - target in prefix:
                end = prefix[curr - target]
                if end > -1:
                    ans = min(ans, i - end + curr_bestl[end])
                best = min(best, i - end)
            curr_bestl[i] = best
            prefix[curr] = i
        return -1 if ans == float("inf") else ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minSumOfLengths(arr=[3, 2, 2, 4, 3], target=3))
    print(obj.minSumOfLengths(arr=[7, 3, 4, 7], target=7))
    print(obj.minSumOfLengths(arr=[4, 3, 2, 6, 2, 3, 4], target=6))
