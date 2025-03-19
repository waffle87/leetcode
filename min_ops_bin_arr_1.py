# 3191. Minimum Operations to Make Binary Array Elements Equal to One I

"""
you are given a binary array 'nums'. you can do the following operation on
the array any number of times (possibly zero): choose any three consecutive
elements from the array and flip all of them. flipping an element means
changing its value from 0 to 1, and from 1 to 0. return the minimum number of
operations required needed to make all elements in 'nums' equal to 1. if it
is impossible, return -1.
"""


class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt, n = 0, len(nums)
        for i in range(n - 2):
            if nums[i] == 0:
                nums[i] ^= 1
                nums[i + 1] ^= 1
                nums[i + 2] ^= 1
                cnt += 1
        return cnt if nums[n - 2] == 1 and nums[n - 1] == 1 else -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations(nums=[0, 1, 1, 1, 0, 0]))
    print(obj.minOperations(nums=[0, 1, 1, 1]))
