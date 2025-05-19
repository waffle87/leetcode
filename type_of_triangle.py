# 3024. Type of Triangle

"""
you are given a 0-indexed integer array 'nums' of size 3 which can form the
sides of a triangle. return a string representing the type of triangle that
can be formed, or none if it cannot form a triangle.
"""


class Solution(object):
    def triangleType(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        nums.sort()
        if nums[2] >= nums[0] + nums[1]:
            return "none"
        if nums[0] == nums[2]:
            return "equilateral"
        if nums[0] == nums[1] or nums[1] == nums[2]:
            return "isosceles"
        return "scalene"


if __name__ == "__main__":
    obj = Solution()
    print(obj.triangleType(nums=[3, 3, 3]))
    print(obj.triangleType(nums=[3, 4, 5]))
