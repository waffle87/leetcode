# 1558. Minimum Numbers of Function Calls to Make Target Array

"""
you are given an integer array 'nums'. you have an integer array 'arr' of the
same length with all values set to 0 initially. you also have the following
'modify' function. you want to use the modify function to covnert 'arr' to
'nums' using the minimum number of calls. return the minimum number of
function calls to make 'nums' from 'arr'. the test cases are generated such
that the answer fits in a 32 bit signed integer.
"""


class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(bin(i).count("1") for i in nums) + len(bin(max(nums))) - 3


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations(nums=[1, 5]))
    print(obj.minOperations(nums=[2, 2]))
    print(obj.minOperations(nums=[4, 2, 5]))
