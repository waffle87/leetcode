# 3254. Find the Power of K-Size Subarrays I
from collections import deque

"""
you are given an array of integers 'nums' of length 'n' and a positive
integer 'k'. the power of an array is defined as its maximum element if all
its elements are consecutive and sorted in ascending order, -1 otherwise. you
need to find the power of all subarrays of 'nums' of size 'k'. return an
integer array 'results' of size 'n - k + 1' where 'results[i]' is the power
of 'nums[i ... (i + k - 1)]'.
"""


class Solution(object):
    def resultsArray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if k == 1:
            return nums
        n, ans, window = len(nums), [], deque()
        for i in range(n):
            while window and i - window[0] >= k:
                window.popleft()
            if not window or nums[i] - nums[i - 1] == 1:
                window.append(i)
            else:
                window.clear()
                window.append(i)
            if i >= k - 1:
                ans.append(nums[i] if len(window) == k else -1)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.resultsArray(nums=[1, 2, 3, 4, 3, 2, 5], k=3))
    print(obj.resultsArray(nums=[2, 2, 2, 2, 2], k=4))
    print(obj.resultsArray(nums=[3, 2, 3, 2, 3, 2], k=2))
