# 2501. Longest Square Streak in an Array
from math import isqrt

"""
you are given an integer array 'nums'. a subsequence of 'nums' is called a
square streak if the length of the subsequence is at least 2 and after
sorting the subsequence, each element (except the first element) is the
square of the previous number. return the length of the longest square streak
in 'nums', or '-1' otherwise. a subsequence is an array that can be derived
from another array by deleting some or no elements without changing the order
of the remaining elements.
"""


class Solution(object):
    def longestSquareStreak(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mp, ans = {}, -1
        nums.sort()
        for i in nums:
            sqrt = isqrt(i)
            if sqrt * sqrt == i and sqrt in mp:
                mp[i] = mp[sqrt] + 1
                ans = max(ans, mp[i])
            else:
                mp[i] = 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestSquareStreak(nums=[4, 3, 6, 16, 8, 2]))
    print(obj.longestSquareStreak(nums=[2, 3, 5, 6, 7]))
