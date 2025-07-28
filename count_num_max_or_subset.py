# 2044. Count Number of Maximum Bitwise-OR Subsets
from collections import Counter

"""
given an integer array 'nums', find the maximum possible bitwise or of a
subset of 'nums' and return the number of different non-empty subsets with
the maximum bitwise or. an array 'a' is a subset of an array 'b' if 'a' can
be obtained from 'b' by deleting some (possibly zero) elements of 'b'. two
subsets are considered different if the indices of the elements chosen are
different. the bitwise or of an array 'a' is equal to 'a[0] | a[1] | ... |
a[a.length - 1]'
"""


class Solution(object):
    def countMaxOrSubsets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = Counter([0])
        for i in nums:
            for k, v in dp.items():
                dp[k | i] += v
        return dp[max(dp)]


if __name__ == "__main__":
    obj = Solution()
    print(obj.countMaxOrSubsets(nums=[3, 1]))
    print(obj.countMaxOrSubsets(nums=[2, 2, 2]))
    print(obj.countMaxOrSubsets(nums=[3, 2, 1, 5]))
