# 961. N-Repeated Element in Size 2N Array

"""
you are given an integer array 'nums' with the following properties:
'nums.length == 2  n', 'nums' contains 'n + 1' unique elements, and exactly
one element of 'nums' is repeated 'n' times. return the element that is
repeated 'n' times.
"""


class Solution(object):
    def repeatedNTimes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return int((sum(nums) - sum(set(nums))) // (len(nums) // 2 - 1))


if __name__ == "__main__":
    obj = Solution()
    print(obj.repeatedNTimes(nums=[1, 2, 3, 3]))
    print(obj.repeatedNTimes(nums=[2, 1, 2, 5, 3, 2]))
    print(obj.repeatedNTimes(nums=[5, 1, 5, 2, 5, 3, 5, 4]))
