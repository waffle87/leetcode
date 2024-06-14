# 162. Find Peak Element

"""
a peak element is an element that is strictly greater than its neighbours.
given a 0 indexed array 'nums', find a peak element and return its index. if
the array contains multiple peaks, return the index to any of the peaks. you
may imagine that 'nums[-1] = nums[n] = -inf' in other words, an element is
always considered to be strictly greater than a neighbour that is outside the
array. you must write an algorithm that runs in 'O(log n)' time.
"""


class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 0, len(nums) - 1
        while left < right - 1:
            mid = (left + right) / 2
            if nums[mid] > nums[mid + 1] and nums[mid] > nums[mid - 1]:
                return mid
            if nums[mid] < nums[mid + 1]:
                left = mid + 1
            else:
                right = mid - 1
        return left if nums[left] >= nums[right] else right


if __name__ == "__main__":
    obj = Solution()
    print(obj.findPeakElement(nums=[1, 2, 3, 1]))
    print(obj.findPeakElement(nums=[1, 2, 1, 3, 5, 6, 4]))
