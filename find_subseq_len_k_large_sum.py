# 2099. Find Subsequence of Length K With the Largest Sum
import heapq

"""
you are given an integer array 'nums' and an integer 'k'. you want to find a
subsequence of 'nums' of length 'k' that has the largest sum. return any such
subsequence as an integer array of length 'k'. a subsequence is an array that
can be derived from another array by deleting some or no elements without
changing the order of the remaining elements.
"""


class Solution(object):
    def maxSubsequence(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        heap = []
        for i, j in enumerate(nums):
            heapq.heappush(heap, (j, i))
            if len(heap) > k:
                heapq.heappop(heap)
        return [i[0] for i in sorted(heap, key=lambda x: x[1])]


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxSubsequence(nums=[2, 1, 3, 3], k=2))
    print(obj.maxSubsequence(nums=[-1, -2, 3, 4], k=3))
    print(obj.maxSubsequence(nums=[3, 4, 3, 3], k=2))
