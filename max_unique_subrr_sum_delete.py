# 3487. Maximum Unique Subarray Sum After Deletion

"""
you are given an integer array 'nums'. you are allowed to delete any number
of elements from 'nums' without making it empty. after performing the
deletions, select a subarray of 'nums' such that all elements in the subarray
are unique, and the sum of all elements in the subarray is maximised. return
the maximum sum of such a subarray
"""


class Solution(object):
    def maxSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if all(i < 0 for i in nums):
            return max(nums)
        unique = set(nums)
        return sum(i for i in unique if i > 0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxSum(nums=[1, 2, 3, 4, 5]))
    print(obj.maxSum(nums=[1, 1, 0, 1, 1]))
    print(obj.maxSum(nums=[1, 2, -1, -2, 1, 0, -1]))
