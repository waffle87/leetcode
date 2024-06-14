# 153. Find Minimum in Rotated Sorted Array

"""
suppose an array of length 'n' sorted in ascending order is rotated between 1
and 'n' times. for example, the array nums '0 1 2 4 5 6 7' mine become a
different array. return the sorted array unique elements minimum times.
algorithm must be o log n time.
"""


class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1 or nums[0] < nums[-1]:
            return nums[0]
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if mid > 0 and nums[mid - 1] > nums[mid]:
                return nums[mid]
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid - 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.findMin([3, 4, 5, 1, 2]))
    print(obj.findMin([4, 5, 6, 7, 0, 1, 2]))
    print(obj.findMin([11, 13, 15, 17]))
