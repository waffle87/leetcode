# 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to
# Limit
from collections import deque

"""
given an array of integers 'nums' and an integer 'limit', return the size of
the longest non empty subarray such that the absolute difference between any
two elements of this subarrays is less than equal or equal to 'limit'
"""


class Solution(object):
    def longestSubarray(self, nums, limit):
        """
        :type nums: List[int]
        :type limit: int
        :rtype: int
        """
        max_d, min_d = deque(), deque()
        n = 0
        for i in nums:
            while len(max_d) and i > max_d[-1]:
                max_d.pop()
            while len(min_d) and i < min_d[-1]:
                min_d.pop()
            max_d.append(i)
            min_d.append(i)
            if max_d[0] - min_d[0] > limit:
                if max_d[0] == nums[n]:
                    max_d.popleft()
                if min_d[0] == nums[n]:
                    min_d.popleft()
                n += 1
        return len(nums) - n


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestSubarray(nums=[8, 2, 4, 7], limit=4))
    print(obj.longestSubarray(nums=[10, 1, 2, 4, 7, 2], limit=5))
    print(obj.longestSubarray(nums=[4, 2, 2, 2, 4, 4, 2, 2], limit=0))
