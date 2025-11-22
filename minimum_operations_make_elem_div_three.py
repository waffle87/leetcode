# 3190. Find Minimum Operations to Make All Elements Divisible by Three

"""
you are given an ineger array 'nums'. in one operation, you can add or
subtract 1 from any element of 'nums' return the minimum number of operations
to make all elements of 'nums' divisible by 3
"""


class Solution(object):
    def minimumOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(i % 3 > 0 for i in nums)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumOperations(nums=[1, 2, 3, 4]))
    print(obj.minimumOperations(nums=[3, 6, 9]))
