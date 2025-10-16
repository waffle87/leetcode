# 2598. Smallest Missing Non-negative Integer After Operations

"""
you are given a 0-indexed integer array 'nums' and an integer 'value'. in one
operation, you can add or subtract 'value' from any element of 'nums'. the
mex (minimum excluded) of an array is the smallest non-negative integer in
it. return the mex of 'nums' after applying the mentioned operation any
number of times.
"""


class Solution(object):
    def findSmallestInteger(self, nums, value):
        """
        :type nums: List[int]
        :type value: int
        :rtype: int
        """
        rem = [0] * value
        for x in nums:
            curr = (x % value + value) % value
            rem[curr] += 1
        ans = 0
        while rem[ans % value]:
            rem[ans % value] -= 1
            ans += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findSmallestInteger(nums=[1, -10, 7, 13, 6, 8], value=5))
    print(obj.findSmallestInteger(nums=[1, -10, 7, 13, 6, 8], value=7))
