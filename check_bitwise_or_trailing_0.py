# 2980. Check if Bitwise OR Has Trailing Zeros

"""
given an array of positive integers 'nums'. you have to check if it is
possible to select two or more elements in the array such that the bitwise or
of the selected elements has at least one trailing zero in its binary
representation. return true if it is possible to select two or more elements
whose bitwise or has trailing zeros, return false otherwise.
"""


class Solution(object):
    def hasTrailingZeros(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        cnt = 0
        for i in range(len(nums)):
            if not (nums[i] % 2):
                cnt += 1
                if cnt == 2:
                    return True
        return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.hasTrailingZeros(nums=[1, 2, 3, 4, 5]))
    print(obj.hasTrailingZeros(nums=[2, 4, 8, 16]))
    print(obj.hasTrailingZeros(nums=[1, 3, 5, 7, 9]))
