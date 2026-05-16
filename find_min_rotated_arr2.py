# 154. Find Minimum in Rotated Sorted Array II

"""
suppose an array of length 'n' sorted in ascending order is rotated between 1
and 'n' times. given the sorted rotated array 'nums' that may contain
duplicates, return the minimum changes of this array. you must decrease the
overall operation steps as much as possible.
"""


class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] > nums[right]:
                left = mid + 1
            elif nums[mid] < nums[right]:
                right = mid
            else:
                right -= 1
        return nums[left]


if __name__ == "__main__":
    obj = Solution()
    print(obj.findMin(nums=[1, 3, 5]))
    print(obj.findMin(nums=[2, 2, 2, 0, 1]))
