# 2945. Find Maximum Non-decreasing Array Length
from itertools import accumulate
from bisect import bisect_left

"""
you are given a 0-indexed integer array 'nums'. you can perform any number of
operations, where each operation involves selecting a subarray of the array
and replacing it with the sum of its elements. for example, if the given
array is '[1, 3, 5, 6]' and you select '[3, 5]', the array will convert to
'[1, 8, 6]'. return the maximum length of a non-decreasing array that can be
made after applying the aforementioned operations. a subarray is a contiguous
non-empty sequence of elements within an array
"""


class Solution(object):
    def findMaximumLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        acc = list(accumulate(nums, initial=0))
        pre = [0] * (n + 2)
        dp = [0] * (n + 1)
        i = 0
        for j, k in enumerate(nums, 1):
            i = max(i, pre[j])
            dp[j] = dp[i] + 1
            l = bisect_left(acc, acc[j] * 2 - acc[i])
            pre[l] = j
        return dp[n]


if __name__ == "__main__":
    obj = Solution()
    print(obj.findMaximumLength(nums=[5, 2, 2]))
    print(obj.findMaximumLength(nums=[1, 2, 3, 4]))
    print(obj.findMaximumLength(nums=[4, 3, 2, 6]))
