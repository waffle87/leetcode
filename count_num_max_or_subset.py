# 2044. Count Number of Maximum Bitwise-OR Subsets
from collections import Counter

"""
given an integer array 'nums', find the maximum possible bitwise OR of a
subset of 'nums' and return the number of different non-empty subsets with
the maximum bitwise OR. an array 'a' is a subset of an array 'b' if 'a' can
be obtained from 'b' by deleting some (possibly 0) elements of 'b'. two
subsets are considered different if the indices of the elements chosen are
different. the bitwose OR of an array 'a' is equal to 'a[0] | a[1] | ... |
a[n]' (0-indexed)
"""


class Solution(object):
    def countMaxOrSubsets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = Counter([0])
        for n in nums:
            for i, j in list(dp.items()):
                dp[i | n] += j
        return dp[max(dp)]


if __name__ == "__main__":
    obj = Solution()
    print(obj.countMaxOrSubsets([3, 1]))
    print(obj.countMaxOrSubsets([2, 2, 2]))
    print(obj.countMaxOrSubsets([3, 2, 1, 5]))
