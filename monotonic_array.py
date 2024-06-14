# 896. Monotonic Array

"""
an array is monotonic if it is either monotone increasing or monotone
decreasing. an array 'nums' is monotone increasing if for all 'i <= j,
nums[i] <= nums[j]'. an array 'nums' is monotone decreasing if for all 'i <=
j, nums[i] >= nums[j]'. given an integer array 'nums', return 'true' if the
given array is monotonic, or 'false' otherwise.
"""


class Solution(object):
    def isMonotonic(self, nums):
        increasing = True
        decreasing = True
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                decreasing = False
            elif nums[i] < nums[i - 1]:
                increasing = False
        return increasing or decreasing


if __name__ == "__main__":
    obj = Solution()
    print(obj.isMonotonic([1, 2, 2, 3]))  # expect: True
    print(obj.isMonotonic([6, 5, 4, 4]))  # expect: True
    print(obj.isMonotonic([1, 3, 2]))  # expect: False
