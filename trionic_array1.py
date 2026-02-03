# 3637. Trionic Array I

"""
you are given an integer array 'nums' of length 'n'. an array is trionic if
there exist indices '0 < p < q < n - 1' such that 'nums[0 ... p]' is strictly
increasing, 'nums[p ... q]' is strictly decreasing, and  'nums[q ... n - 1]'
is strictly increasing. return true if 'nums' is trionic, otherwise return
false.
"""


class Solution(object):
    def isTrionic(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n, i = len(nums), 0
        while i + 1 < n and nums[i] < nums[i + 1]:
            i += 1
        if i == 0 or i == n - 1:
            return False
        p = i
        while i + 1 < n and nums[i] > nums[i + 1]:
            i += 1
        if i == p or i == n - 1:
            return False
        while i + 1 < n and nums[i] < nums[i + 1]:
            i += 1
        return i == n - 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.isTrionic(nums=[1, 3, 5, 4, 2, 6]))
    print(obj.isTrionic(nums=[2, 1, 3]))
