# 2784. Check if Array is Good

"""
you are given an integer array 'nums'. we consider an array good if it is a
permutation of an array 'base[n]'. 'base[n] = [1,2, ..., n - 1, n]'. return
true if the given array is good, otherwise return false. note: a permutation
of integers represents an arrangement of these numbers.
"""


class Solution:
    def isGood(self, nums: List[int]) -> bool:
        n = len(nums)
        nums = sorted(nums)
        expect = list(range(1, n)) + [n - 1]
        return expect == nums


if __name__ == "__main__":
    obj = Solution()
    print(obj.isGood(nums=[2, 1, 3]))
    print(obj.isGood(nums=[1, 3, 3, 2]))
    print(obj.isGood(nums=[1, 1]))
    print(obj.isGood(nums=[3, 4, 4, 1, 2, 1]))
