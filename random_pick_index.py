# 398. Random Pick Index
from random import randint

"""
given an integer array 'nums' with possible duplicates, randomly output the
index of a given 'target' numbber. you can assume that the given target
number must exist in the array. implement the 'Solution' class: 'Solution(int
[] nums)' initiliases the object with the array 'nums', 'int pick(int
target)' picks a random index 'i' from 'nums' where 'nums[i] == target'. if
there are multiple valid 'i's, then each index should have an equal
probability
"""


class Solution(object):
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums = nums

    def pick(self, target):
        """
        :type target: int
        :rtype: int
        """
        cnt, res = 0, None
        for i, n in enumerate(self.nums):
            if n == target:
                cnt += 1
                if (randint(0, cnt) % cnt) == 0:
                    res = i
        return res


if __name__ == "__main__":
    obj = Solution([1, 2, 3, 3, 3, 3])
    print(obj.pick(3))
    print(obj.pick(1))
    print(obj.pick(3))
