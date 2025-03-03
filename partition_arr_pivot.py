# 2161. Partition Array According to Given Pivot

"""
you are given a 0-indexed integer array 'nums' and an integer 'pivot'.
rearrange 'nums' such that the following conditions are satisfied: every
element less than 'pivot' appears befor every element greater than 'pivot',
every element equal to 'pivot' appears in between the elements less than and
greater than 'pivot', the relative order of the elments less than 'pivot' and
the elements greater than 'pivot' is maintained. return 'nums' after the
rearrangement
"""


class Solution(object):
    def pivotArray(self, nums, pivot):
        """
        :type nums: List[int]
        :type pivot: int
        :rtype: List[int]
        """
        ans = [0] * len(nums)
        left, right = 0, len(nums) - 1
        for i, j in zip(range(len(nums)), range(len(nums) - 1, -1, -1)):
            if nums[i] < pivot:
                ans[left] = nums[i]
                left += 1
            if nums[j] > pivot:
                ans[right] = nums[j]
                right -= 1
        while left <= right:
            ans[left] = pivot
            left += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.pivotArray(nums=[9, 12, 5, 10, 14, 3, 10], pivot=10))
    print(obj.pivotArray(nums=[-3, 4, 3, 2], pivot=2))
