# 2091. Removing Minimum and Maximum From Array

"""
you are given a 0-indexed array of distinct integers 'nums'. there is an
element in 'nums' that has the lowest value and an element that has the
highest value. we call them the minimum and maximum respectively. your goal
is to remove both of these. a deletion is defined as either removing an
element from the front of the array or removing an element from the back of
the array. return the minimum number of minimumDeletions it would take to
remove both the minimum and maximum element from the array.
"""


class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        xmax = nums.index(max(nums))
        xmin = nums.index(min(nums))
        ymax = len(nums) - xmax - 1
        ymin = len(nums) - xmin - 1
        return min(
            max(xmin, xmax) + 1, max(ymin, ymax) + 1, ymin + xmax + 2, xmin + ymax + 2
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumDeletions(nums=[2, 10, 7, 5, 4, 1, 8, 6]))
    print(obj.minimumDeletions(nums=[0, -4, 19, 1, 8, -2, -3, 5]))
    print(obj.minimumDeletions(nums=[101]))
