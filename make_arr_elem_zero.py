# 3354. Make Array Elements Equal to Zero
from itertools import accumulate

"""
you are given an integer array 'nums'. start by selecting a starting position
'curr' such that 'nums[curr] == 0' and choose a movement direction of either
left or right. after that, you repeat the following process: if 'curr' is out
of the range '[0, n - 1]', this process ends. if 'nums[curr] == 0', move in
the current direction by incrementing 'curr' if you are moving right, or
decrmenting 'curr' if you are moving left. else if 'nums[curr] > 0',
decrement 'nums[curr] by 1', reverse your movement direction, take a step in
the new direction. a selection of the initial position 'curr' and movement
direction is considered valid if every element in 'nums' becomes 0 by the end
of the process. return the number of possible valid sections.
"""


class Solution(object):
    def countValidSelections(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        prefix = list(accumulate(nums, initial=0))
        ans, s = 0, prefix[-1]
        for i, j in zip(nums, prefix):
            j *= 2
            if i != 0:
                continue
            if s == j:
                ans += 2
            if abs(s - j) == 1:
                ans += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countValidSelections(nums=[1, 0, 2, 0, 3]))
    print(obj.countValidSelections(nums=[2, 3, 4, 0, 4, 1, 0]))
