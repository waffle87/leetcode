# 2150. Find All Lonely Numbers in the Array
from collections import Counter

"""
you are given an integer array 'nums'. a number 'x' is lonely when it appears
only once, and no adjacent numbers (ie. 'x + 1' and 'x - 1') appear in the
array. return all lonely numbers in 'nums'. you may return the answer in any
order
"""


class Solution(object):
    def findLonely(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        m = Counter(nums)
        return [n for n in nums if m[n] == 1 and m[n - 1] + m[n + 1] == 0]


if __name__ == "__main__":
    obj = Solution()
    print(obj.findLonely(nums=[10, 6, 5, 8]))
    print(obj.findLonely(nums=[1, 3, 5, 3]))
