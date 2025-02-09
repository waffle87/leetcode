# 2364. Count Number of Bad Pairs
from collections import defaultdict

"""
you are given a 0-indexed integer array 'nums'. a pair of indices '(i, j)' is
a bad pair if 'i < j' and 'j - i != nums[j] - nums[i]'. return the total
number of bad pairs in 'nums'.
"""


class Solution(object):
    def countBadPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mp, ans = defaultdict(int), 0
        for i in range(len(nums)):
            ans += i - mp[nums[i] - i]
            mp[nums[i] - i] += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countBadPairs(nums=[4, 1, 3, 3]))
    print(obj.countBadPairs(nums=[1, 2, 3, 4, 5]))
