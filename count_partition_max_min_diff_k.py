# 3578. Count Partitions With Max-Min Difference at Most K
from collections import deque

"""
you are given an integer array 'nums' and an integer 'k'. your task is to
partition 'nums' into one or more non-empty contiguous segments such that in
each segment, the difference between its maximum and minimum elements is at
most 'k'. return the total number of ways to partition 'nums' under this
condition. since the answer may be too large, return it modulo 10^9 + 7.
"""


class Solution(object):
    def countPartitions(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n, mod = len(nums), 10**9 + 7
        dp = [0] * (n + 1)
        dp[0] = 1
        mx, mn = deque(), deque()
        left, total = 0, 0
        for right in range(n):
            while mx and nums[mx[-1]] <= nums[right]:
                mx.pop()
            while mn and nums[mn[-1]] >= nums[right]:
                mn.pop()
            mx.append(right)
            mn.append(right)
            while nums[mx[0]] - nums[mn[0]] > k:
                if mx[0] == left:
                    mx.popleft()
                if mn[0] == left:
                    mn.popleft()
                total = (total - dp[left]) % mod
                left += 1
            total = (total + dp[right]) % mod
            dp[right + 1] = total
        return dp[n]


if __name__ == "__main__":
    obj = Solution()
    print(obj.countPartitions(nums=[9, 4, 1, 3, 7], k=4))
    print(obj.countPartitions(nums=[3, 3, 4], k=0))
