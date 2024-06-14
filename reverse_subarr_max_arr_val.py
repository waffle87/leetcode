# 1330. Reverse Subarray To Maximize Array Value

"""
given an intger array 'nums'. the value of this array is defined as the sum
of '| nums[i] - nums[i + 1] |' for all '0 <= i < nums.len - 1'. you are
allowed to select any subarray of the given array and reverse it. you can
perform this operation only once. find maximum possible value of the final
array.
"""


class Solution(object):
    def maxValueAfterReverse(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        total, sum, min2, max2 = 0, 0, float("inf"), -float("inf")
        for a, b in zip(nums, nums[1:]):
            total += abs(a - b)
            sum = max(sum, abs(nums[0] - b) - abs(a - b))
            sum = max(sum, abs(nums[-1] - a) - abs(a - b))
            min2, max2 = min(min2, max(a, b)), max(max2, min(a, b))
        return total + max(sum, (max2 - min2) * 2)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxValueAfterReverse(nums=[2, 3, 1, 5, 4]))
    print(obj.maxValueAfterReverse(nums=[2, 4, 9, 24, 2, 1, 10]))
