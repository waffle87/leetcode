# 1760. Minimum Limit of Balls in a Bag
from bisect import bisect_left

"""
given an integer array 'nums' where the i'th bag contains
'nums[i]' balls. also given an integer 'max_operations'.
you can perform the following operation at most 'max_operations'
times; take any bag of balls and divide it into two new bags
with a positive number of balls. the penalty is the maximum
number of balls in a bag. you want to minimise your penalty
after the operations. return the minimum possible penalty.
"""


class Solution(object):
    def minimumSize(self, nums, maxOperations):
        """
        :type nums: List[int]
        :type maxOperations: int
        :rtype: int
        """
        return (
            bisect_left(
                range(1, max(nums) + 1),
                0,
                key=lambda x: maxOperations - sum((k - 1) // x for k in nums),
            )
            + 1
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumSize(nums=[9], maxOperations=2))
    print(obj.minimumSize(nums=[2, 4, 8, 2], maxOperations=4))
