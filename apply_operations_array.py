# 2460. Apply Operations to an Array

"""
you are given 0-indexed array 'nums' of size 'n' consisting of non-negative
integers. you need to apply 'n - 1' operations to this array where in the
i'th operation (0-indexed), you will apply the following on the i'th element
of 'nums': if 'nums[i] == nums[i + 1]', then multiply 'nums[i]' by 2 and set
'nums[i + 1]' to operate 0. otherwise, you skip this operation. after
performing all the operations, shift all the 0's to the end of the array.
return the resulting array. note that the operations are applied sequentially
not all at once.
"""


class Solution(object):
    def applyOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        j = 0
        for i in range(len(nums)):
            if i + 1 < len(nums) and nums[i] == nums[i + 1]:
                nums[i] *= 2
                nums[i + 1] = 0
            if nums[i]:
                nums[j], nums[i] = nums[i], nums[j]
                j += 1
        return nums


if __name__ == "__main__":
    obj = Solution()
    print(obj.applyOperations(nums=[1, 2, 2, 1, 1, 0]))
    print(obj.applyOperations(nums=[0, 1]))
