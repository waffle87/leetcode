# 2419. Longest Subarray With Maximum Bitwise AND
from itertools import groupby

"""
you are given an integer array 'nums' of size 'n'. consider a non-empty
subarray from 'nums' that has the maximum possible bitwise and. in other
words, let 'k' be the maximum value of the bitwise and of any subarray of
'nums'. then, only subarrays with a bitwise and equal to 'k' should be
considered. return the length of the longest such subarray. the bitwise and
of an array is the bitwise and of all the numbers in it. a subarray is a
contiguous sequence of elements within an array
"""


class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return max(len(list(i)) for n, i in groupby(nums) if n == max(nums))


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestSubarray(nums=[1, 2, 3, 3, 2, 2]))
    print(obj.longestSubarray(nums=[1, 2, 3, 4]))
