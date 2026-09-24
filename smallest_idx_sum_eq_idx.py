# 3550. Smallest Index With Digit Sum Equal to Index

"""
you are given an integer array 'nums'. return the smallest index 'i' such
that the sum of the digits of 'nums[i]' is equal to 'i'. if no such index
exists, return -1.
"""


class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for i, x in enumerate(nums):
            digit_sum = 0
            while x > 0:
                x, r = divmod(x, 10)
                digit_sum += r
            if digit_sum == i:
                return i
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.smallestIndex(nums=[1, 3, 2]))
    print(obj.smallestIndex(nums=[1, 10, 11]))
    print(obj.smallestIndex(nums=[1, 2, 3]))
