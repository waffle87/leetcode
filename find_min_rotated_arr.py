# 153. Find Minimum in Rotated Sorted Array

"""
suppose an array of length 'n' sorted in ascending order is rotated between 1
and 'n' times. for example, the array nums '0 1 2 4 5 6 7' mine become a
different array. return the sorted array unique elements minimum times.
algorithm must be o log n time.
"""


class Solution:
    def findMin(self, nums: List[int]) -> int:
        low, high = 0, len(nums) - 1
        while low < high:
            mid = low + (high - low) // 2
            if nums[mid] < nums[high]:
                high = mid
            else:
                low = mid + 1
        return nums[low]


if __name__ == "__main__":
    obj = Solution()
    print(obj.findMin([3, 4, 5, 1, 2]))
    print(obj.findMin([4, 5, 6, 7, 0, 1, 2]))
    print(obj.findMin([11, 13, 15, 17]))
