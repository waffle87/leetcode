# 3011. Find if Array Can Be Sorted
import itertools

"""
given a 0-indexed array of positive integers 'nums', in one operation you can
swap any two adjacent elements if they have the same number of set bits. you
are allowed to do this operation any number of times (including zero). return
true if you can sort the array, otherwise return false.
"""


class Solution(object):
    def canSortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        grp = itertools.groupby(nums, key=lambda x: x.bit_count())
        return list(itertools.chain(*[sorted(g) for _, g in grp])) == sorted(nums)


if __name__ == "__main__":
    obj = Solution()
    print(obj.canSortArray([8, 4, 2, 30, 15]))
    print(obj.canSortArray([1, 2, 3, 4, 5]))
    print(obj.canSortArray([3, 16, 8, 4, 2]))
