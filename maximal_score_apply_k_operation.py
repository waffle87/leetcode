# 2530. Maximal Score After Applying K Operations
import heapq
from math import ceil

"""
you are given a 0-indexed integer array 'nums' and an integer 'k'. you have a
starting score of 0. in one operation you can choose an index 'i' such that
'0 <= i < nums.length', increase your score by 'nums[i]', and replace
'nums[i]' with 'ceil(nums[i] / 3)'. return the maximum possible score you can
attain after applying exactly 'k' operations. the ceiling function
'ceil(val)' is the least integer greater than or equal to 'val'.
"""


class Solution(object):
    def maxKelements(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        pq = [-n for n in nums]
        heapq.heapify(pq)
        score = 0
        while k > 0:
            element = -heapq.heappop(pq)
            score += element
            heapq.heappush(pq, -ceil(element / 3))
            k -= 1
        return score


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxKelements(nums=[10, 10, 10, 10, 10], k=5))
    print(obj.maxKelements(nums=[1, 10, 3, 3, 3], k=3))
