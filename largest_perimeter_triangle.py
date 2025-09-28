# 976. Largest Perimeter Triangle

"""
given an integer array 'nums', return the largest perimeter of a triangle
with a non-zero area, formed from three of these lengths. if it is impossible
to form any triangle of a non-zero area, return 0.
"""


class Solution(object):
    def largestPerimeter(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = sorted(nums)[::-1]
        for i in range(len(nums) - 2):
            if nums[i] < nums[i + 1] + nums[i + 2]:
                return nums[i] + nums[i + 1] + nums[i + 2]
        return 0


if __name__ == "__main__":
    obj = Solution()
    print(obj.largestPerimeter(nums=[2, 1, 2]))
    print(obj.largestPerimeter(nums=[3, 2, 3, 4]))
