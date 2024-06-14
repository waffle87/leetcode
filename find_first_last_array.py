# 34. Find First and Last Position of Element in Sorted Array

"""
given an array of integers 'nums' sorted in non-decreasing order, find the
starting ending position of a given 'target' value. if target is not found in
the array, return '[-1, -1]'. you must write an algorithm with O(log n)
runtime complexity
"""

class Solution(object):
    def searchRange(self, nums, target):
            low, high = 0, len(nums) - 1
            index = -1
            while low <= high:
                mid = (low + high) // 2
                if nums[mid] == target:
                    index = mid
                    if left:
                        high = mid - 1
                    else:
                        low = mid + 1
                elif nums[mid] < target:
                    low = mid + 1
                else:
                    high = mid - 1
            return index

        left_index = binary_search(nums, target, left=True)
        right_index = binary_search(nums, target, left=False)

        return [left_index, right_index]
