# 2971. Find Polygon With the Largest Perimeter

"""
given an arry of positive integers 'nums' of length 'n'. a polygon is a
closed plane figure that has at least 3 sides. the longest side of a polygon
is smaller than the sum of its other sides. conversely, if you have 'k (k >=
3)' positive real numbers then there always exists a polygon with 'k' sides
whose lengths are 'a1,a2,...ak'. the perimeter of a polygon is the sum of
lengths of its sides. return the largest possible perimeter of a polygon
whose sides can be formed from 'nums' or '-1' if it is not possible to create
a polygon.
"""


class Solution(object):
    def largestPerimeter(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        curr = sum(nums)
        while nums and curr <= nums[-1] * 2:
            curr -= nums.pop()
        return sum(nums) if len(nums) > 2 else -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.largestPerimeter(nums=[5, 5, 5]))
    print(obj.largestPerimeter(nums=[1, 12, 1, 2, 5, 50, 3]))
    print(obj.largestPerimeter(nums=[5, 5, 50]))
