# 2563. Count the Number of Fair Pairs
import bisect

"""
given a 0 indexed integer array 'nums' of size 'n', and two integers 'lower'
and 'upper', return the number of fair pairs. pair '(i, j)' is fair is '0 <=
i < j < n' and 'lower <= nums[i] + nums[j] <= upper'
"""


class Solution(object):
    def countFairPairs(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        nums.sort()
        ans = 0
        for i in range(len(nums) - 1, -1, -1):
            a = bisect.bisect_left(nums, lower - nums[i], i + 1)
            b = bisect.bisect_right(nums, upper - nums[i], i + 1)
            ans += b - a
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countFairPairs(nums=[0, 1, 7, 4, 4, 5], lower=3, upper=6))
    print(obj.countFairPairs(nums=[1, 7, 9, 2, 5], lower=11, upper=11))
