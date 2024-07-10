# 1968. Array With Elements Not Equal to Average of Neighbors

"""
you are given a 0-indexed array 'nums' of distinct integers. you want to
rearrange the elements in the array such that every element in the rearranged
array is not equal to the average of its neighbors. more formally the
rearranged array should have the property such that for every 'i' in the
range '1 <= nums.len - 1', '(nums[i - 1] + nums[i + 1]) / 2' is not equal to
'nums[i]'. return any rearrangement of 'nums' that meets the requirements.

"""


class Solution(object):
    def rearrangeArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums.sort()
        for i in range(1, len(nums), 2):
            nums[i], nums[i - 1] = nums[i - 1], nums[i]
        return nums


if __name__ == "__main__":
    obj = Solution()
    print(obj.rearrangeArray(nums=[1, 2, 3, 4, 5]))
    print(obj.rearrangeArray(nums=[6, 2, 0, 9, 7]))
