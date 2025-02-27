# 873. Length of Longest Fibonacci Subsequence
from collections import defaultdict

"""
a sequence 'x1, x2, ..., xn' is fibonacci like if 'n >= 3' and 'x_i + x_i + 1
== x_i + 2' for all 'i + 2 <= n'. given a strictly increasing 'arr' of
positive integers forming a sequence, return the length of the longest
fibonacci like subsequence of 'arr'. if one does not exist, return 0. a
subsequence is derived from another sequence 'arr' by deleting any number of
elements (including none) from 'arr', without changing the order of the
remaining elements.
"""


class Solution(object):
    def lenLongestFibSubseq(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        dp, s = defaultdict(int), set(arr)
        for i in range(len(arr)):
            for j in range(i):
                if arr[i] - arr[j] < arr[j] and arr[i] - arr[j] in s:
                    dp[arr[j], arr[i]] = dp.get((arr[i] - arr[j], arr[j]), 2) + 1
        return max(dp.values() or [0])


if __name__ == "__main__":
    obj = Solution()
    print(obj.lenLongestFibSubseq(arr=[1, 2, 3, 4, 5, 6, 7, 8]))
    print(obj.lenLongestFibSubseq(arr=[1, 3, 7, 11, 12, 14, 18]))
