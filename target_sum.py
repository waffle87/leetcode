# 494. Target Sum
from collections import Counter

"""
given an integer array 'nums' and an integer 'target'. you want to buildan
expression out of numbers by adding oneof the symbols '+' and '-' before each
integer in nums awnd then concatenate all the integers. for example if 'nums
= [2,1]', you can adda '+' before '2' and '-' before '1' and concatenate them
to build the expression '+2-1'. return the number of different
expressionsthat you can build, which evaluates to 'target'.
"""


class Solution(object):
    def findTargetSumWays(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        cnt = Counter({0: 1})
        for x in nums:
            step = Counter()
            for y in cnt:
                step[y + x] += cnt[y]
                step[y - x] += cnt[y]
            cnt = step
        return cnt[target]


if __name__ == "__main__":
    obj = Solution()
    print(obj.findTargetSumWays(nums=[1, 1, 1, 1, 1], target=3))
    print(obj.findTargetSumWays(nums=[1], target=1))
