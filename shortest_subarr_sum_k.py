# 862 Shortest Subarray with Sum at Least K
from collections import deque

"""
given an integer array 'nums' and an integer 'k' return the length of the
shortest non empty subarray of 'nums' with a sum of at least 'k'. if there is
no such subarray, return -1. a subarray is a contiguous part of an array
"""


class Solution(object):
    def shortestSubarray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        dq = deque([[0, 0]])
        ans, curr = float("inf"), 0
        for i, j in enumerate(nums):
            curr += j
            while dq and curr - dq[0][1] >= k:
                ans = min(ans, i + 1 - dq.popleft()[0])
            while dq and curr <= dq[-1][1]:
                dq.pop()
            dq.append([i + 1, curr])
        return ans if ans < float("inf") else -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.shortestSubarray(nums=[1], k=1))
    print(obj.shortestSubarray(nums=[1, 2], k=4))
    print(obj.shortestSubarray(nums=[2, -1, 2], k=3))
