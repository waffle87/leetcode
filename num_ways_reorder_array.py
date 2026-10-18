# 1569. Number of Ways to Reorder Array to Get Same BST

"""
given an array 'nums' that represents a permutation of integers from '1 to
n'. we are going to construct a binary search tree (BST) by inserting the
elements of 'nums' in order into an initially empty BST. find the number of
different ways to reorder 'nums' so that the constructed BST is identical to
that formed from the original array 'nums'. for example given 'nums =
[2,1,3]', we will have 2 as the root, 1 as a left child, and three as a right
child. the array [2,3,1] also yields the same BST, but '[3,2,1]' yields a
different BST. return the number of ways to reorder 'nums' such that the BST
formed is identical to the original BST formed from 'nums'. since the answer
may be large, return it modulo 10^9+7
"""

from math import comb


class Solution:
    def numOfWays(self, nums: list[int]) -> int:
        def helper(nums):
            if len(nums) < 3:
                return 1
            left = [i for i in nums if i < nums[0]]
            right = [i for i in nums if i > nums[0]]
            return (
                comb(len(left) + len(right), len(right)) * helper(left) * helper(right)
            )

        return (helper(nums) - 1) % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    print(obj.numOfWays(nums=[2, 1, 3]))
    print(obj.numOfWays(nums=[3, 4, 5, 1, 2]))
    print(obj.numOfWays(nums=[1, 2, 3]))
