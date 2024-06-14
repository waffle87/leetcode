# 977. Squares of a Sorted Array

"""
given an integer array 'nums' sorted in non-decreasing order, return an array
of the squares sorted in non-decreasing order.
"""


class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = [None for _ in nums]
        left, right = 0, len(nums) - 1
        for i in range(len(nums) - 1, -1, -1):
            if abs(nums[left]) > abs(nums[right]):
                ans[i] = nums[left] ** 2
                left += 1
            else:
                ans[i] = nums[right] ** 2
                right -= 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.sortedSquares(nums=[-4, -1, 0, 3, 10]))
    print(obj.sortedSquares(nums=[-7, -3, 2, 3, 11]))
