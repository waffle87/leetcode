# 632. Smallest Range Covering Elements from K Lists
import heapq

"""
you have 'k' lists of sorted integers in non decreasing order. find the
smallest range that includes at least one number from each of the 'k' lists.
we define the range '[a, b]' is smaller than the range '[c, d]' if 'b - a < d
- c' or 'a < c' if 'b - a == d - c'
"""


class Solution(object):
    def smallestRange(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
        pq = [(row[0], i, 0) for i, row in enumerate(nums)]
        ans = -1e9, 1e9
        right = max(row[0] for row in nums)
        while pq:
            left, i, j = heapq.heappop(pq)
            if right - left < ans[1] - ans[0]:
                ans = left, right
            if j + 1 == len(nums[i]):
                return ans
            v = nums[i][j + 1]
            right = max(right, v)
            heapq.heappush(pq, (v, i, j + 1))


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.smallestRange(nums=[[4, 10, 15, 24, 26], [0, 9, 12, 20], [5, 18, 22, 30]])
    )
    print(obj.smallestRange(nums=[[1, 2, 3], [1, 2, 3], [1, 2, 3]]))
