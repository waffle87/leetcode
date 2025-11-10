# 3542. Minimum Operations to Convert All Elements to Zero

"""
you are given an array 'nums' of size 'n' consisting of non-negative
integers. your task is to apply some (possibly zero) operations on the array
so that all elements become 0. in one operation, you can select a subarray
'[i, j]' where '0 <= i <= j < n' and set all occurences of the minimum
non-negative integer in that subarray to zero. return the minimum number of
operations required to make all elements in the array 0
"""


class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        memo = [0] * (len(nums) + 1)
        top, ans = 0, 0
        for i in nums:
            while memo[top] > i:
                top -= 1
                ans += 1
            if memo[top] != i:
                top += 1
                memo[top] = i
        return ans + top


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations(nums=[0, 2]))
    print(obj.minOperations(nums=[3, 1, 2, 1]))
    print(obj.minOperations(nums=[1, 2, 1, 2, 1, 2]))
