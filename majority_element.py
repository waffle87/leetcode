# 169. Majority Element

"""
given an array 'nums' of size 'n', return the majority element. the majority
element is the element that appears more than 'floor(n / 2)' times. you may
assume that the majority element always exists in the array.
"""


class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        n = len(nums)
        return nums[n // 2]


if __name__ == "__main__":
    obj = Solution()
    print(obj.majorityElement([3, 2, 3]))
    print(obj.majorityElement([2, 2, 1, 1, 1, 2, 2]))
