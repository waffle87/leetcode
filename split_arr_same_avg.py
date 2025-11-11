# 805. Split Array With Same Average

"""
you are given an integer array 'nums'. you should move each element of 'nums'
into one of the two arrays 'a' and 'b' such that 'a' and 'b' are non-empty
and 'average(a) == average(b)'. return true if it is possible to achieve, and
false otherwise. note that for an array 'arr', 'average(arr)' is the sum of
all the elements of the length of 'arr'.
"""


class Solution(object):
    def possible_sum(self, arr):
        subset = 1
        for i in arr:
            subset |= subset << i
        return (subset - 1) ^ (1 << sum(arr))

    def splitArraySameAverage(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n, total = len(nums), sum(nums)
        if n <= 1:
            return False
        transform = [n * i - total for i in nums]
        if 0 in transform:
            return True
        pos = [i for i in transform if i > 0]
        neg = [-i for i in transform if i < 0]
        return bool(self.possible_sum(pos) & self.possible_sum(neg))


if __name__ == "__main__":
    obj = Solution()
    print(obj.splitArraySameAverage(nums=[1, 2, 3, 4, 5, 6, 7, 8]))
    print(obj.splitArraySameAverage(nums=[3, 1]))
