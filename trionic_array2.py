# 3640. Trionic Array II
from itertools import pairwise

"""
you are given an integer array 'nums' of length 'n'. a trionic subarray is a
contiguous subarray 'nums[l ... r]' for which there exists indices 'nums[l
... p]' is stricly increasing, 'nums[p ... q]' is strictly decreasing, and
'nums[p ... r]' is strictly increasing. return the maximum sum of any trionic
subarray in 'nums'.
"""


class Solution(object):
    def maxSumTrionic(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l, p, q = 0, 0, 0
        ans = len(nums), float("-inf")
        cnt, prev = nums[0], float("inf")
        for i, (left, right) in enumerate(pairwise(nums)):
            if left > right:
                cnt += right
                if prev > left:
                    continue
                p = i
                while (l < q) or (l < p - 1 and nums[l] < 0):
                    cnt -= nums[l]
                    l += 1
            elif left < right:
                cnt += right
                if prev > left:
                    q = i
                if l < p < q <= i and cnt > ans:
                    ans = cnt
            elif left == right:
                cnt, l = right, i + 1
            prev = left
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxSumTrionic(nums=[0, -2, -1, -3, 0, 2, -1]))
    print(obj.maxSumTrionic(nums=[1, 4, 2, 7]))
