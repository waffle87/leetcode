# 1752. Check if Array Is Sorted and Rotated

"""
given an array 'nums', return 'true' if the array was originally sorted in
non-decreasing order, then rotated some number of positions (including zero).
otherwise return 'false'. there may be duplicates in the original array.
note: an array 'a' rotated by 'x' positions results in an array 'b' of the
same length such that 'a[i] == b[(i + x) % a.len]'.
"""


class Solution(object):
    def check(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return sum(a > b for a, b in zip(nums, nums[1:] + nums[:1])) <= 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.check(nums=[3, 4, 5, 1, 2]))
    print(obj.check(nums=[2, 1, 3, 4]))
    print(obj.check(nums=[1, 2, 3]))
