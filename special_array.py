# 3151. Special Array I

"""
an array is considered special if every pair of its adjacent elements
contains two numbers with different parity. you are given an array of
integers 'nums'. return 'true' if 'nums' is a special array, otherwise return
'false'.
"""


class Solution(object):
    def isArraySpecial(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        for i in range(1, len(nums)):
            if (nums[i - 1] & 1) ^ (nums[i] & 1) == 0:
                return False
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.isArraySpecial(nums=[1]))
    print(obj.isArraySpecial(nums=[2, 1, 4]))
    print(obj.isArraySpecial(nums=[4, 3, 1, 6]))
