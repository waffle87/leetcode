# 1865. Finding Pairs With a Certain Sum
from collections import Counter

"""
you are given two integer arrays 'nums1' and 'nums2'. you are tasked to
implement a data structure that supports queries of two types: add a positive
integer to an element of a given index in the array 'nums2', count the number
of pairs '(i, j)' such that 'nums1[i] + nums2[i]' equals a given ('0 <= i <
nums1.length' and '0 <= j < nums2.length') implement the 'FindSumPairs'
class.
"""


class FindSumPairs(object):
    def __init__(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        """
        self.nums1_dict = Counter(nums1)
        self.nums2_dict = Counter(nums2)
        self.nums2 = nums2

    def add(self, index, val):
        """
        :type index: int
        :type val: int
        :rtype: None
        """
        prev = self.nums2[index]
        self.nums2[index] += val
        self.nums2_dict[prev] -= 1
        self.nums2_dict[prev + val] += 1

    def count(self, tot):
        """
        :type tot: int
        :rtype: int
        """
        ans = 0
        for i, j in self.nums1_dict.items():
            ans += j * self.nums2_dict[tot - i]
        return ans


if __name__ == "__main__":
    obj = FindSumPairs(nums1=[1, 1, 2, 2, 2, 3], nums2=[1, 4, 5, 2, 5, 4])
    print(obj.count(7))
    print(obj.add(3, 2))
    print(obj.count(8))
    print(obj.count(4))
    print(obj.add(0, 1))
    print(obj.add(1, 1))
    print(obj.count(7))
