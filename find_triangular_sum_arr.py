# 2221. Find Triangular Sum of an Array
from math import comb

"""
you are given a 0-indexed integer array 'nums', where 'nums[i]' is a digit
between 0 and 9 inclusive. the triangular sum of 'nums' is the value of the
only element present in 'nums' after the following process concludes: let
'nums' comprise of 'n' elements. if 'n == 1', end the process. otherwise,
create a new 0-indexed integer array 'new_nums' of length 'n - 1'. for each
index 'i' where '0 <= i < n - 1', assign the value of 'new_nums[i]' as
'(nums[i] + nums[i + 1]) % 10'. replace the array 'nums' with 'new_nums', and
repeat the entire process starting again.
"""


class Solution(object):
    def triangularSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(n * comb(len(nums) - 1, i) for i, n in enumerate(nums)) % 10


if __name__ == "__main__":
    obj = Solution()
    print(obj.triangularSum(nums=[1, 2, 3, 4, 5]))
    print(obj.triangularSum(nums=[5]))
