# 3201. Find the Maximum Length of Valid Subsequence I
from itertools import groupby

"""
you are given an integer array 'nums'. a subsequence 'sub' of 'nums' with
length 'x' is called valid if it satisfies '(sub[0] + sub[1]) % 2 == (sub[1]
+ sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2'. return the legnth of
the longest valid subsequences of 'nums'. a subsequence is an array that can
be derived from another array by deleting some or no elements without
changing the order of the remaining elements.
"""


class Solution(object):
    def maximumLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = [i % 2 for i in nums]
        return max(nums.count(0), nums.count(1), len(list(groupby(nums))))


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumLength(nums=[1, 2, 3, 4]))
    print(obj.maximumLength(nums=[1, 2, 1, 1, 2, 1, 2]))
    print(obj.maximumLength(nums=[1, 3]))
