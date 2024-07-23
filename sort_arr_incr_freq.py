# 1636. Sort Array by Increasing Frequency
from collections import Counter

"""
given an array of integers 'nums', sort the array in increasing order based
on the frequency of the values. if multiple values have the same frequency,
sort them in decreasing order. return the sorted array.
"""


class Solution(object):
    def frequencySort(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        cnt = Counter(nums)
        return sorted(nums, key=lambda n: (cnt[n], -n))


if __name__ == "__main__":
    obj = Solution()
    print(obj.frequencySort(nums=[1, 1, 2, 2, 2, 3]))
    print(obj.frequencySort(nums=[2, 3, 1, 3, 2]))
    print(obj.frequencySort(nums=[-1, 1, -6, 4, 5, -6, 1, 4, 1]))
