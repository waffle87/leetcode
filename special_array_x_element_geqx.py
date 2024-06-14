# 1608. Special Array With X Elements Greater Than or Equal X

"""
given an array 'nums' of non negative integers. 'nums' is considered special
if there exists a number 'x' such that there are exactly 'x' numbers in
'nums' that are greater than or equal to 'x'. notice that 'x' does not have
to be an element in 'nums'. return 'x' if the array is special, otherwise,
return -1. it can be proven that if 'nums' is special, the value for 'x' is
unique.
"""


class Solution(object):
    def specialArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort(reverse=True)
        i = 0
        while i < len(nums) and nums[i] > i:
            i += 1
        return -1 if i < len(nums) and i == nums[i] else i


if __name__ == "__main__":
    obj = Solution()
    print(obj.specialArray([3, 5]))
    print(obj.specialArray([0, 0]))
    print(obj.specialArray([0, 4, 3, 0, 4]))
