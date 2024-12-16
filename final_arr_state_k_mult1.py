# 3264. Final Array State After K Multiplication Operations I
import heapq

"""
you are given an integer array 'nums', an integer 'k', and an integer
'multiplier'. you need to perform 'k' operations on 'nums'. in each
operation, find the minimum value 'x' in 'nums'. if there are multiple
occurences of the minimum value, select the one that appears first. replace
the selected minimum value 'x' with 'x  multiplier'. return an integer array
denoting the final state of 'nums' after performing all 'k' operations
"""


class Solution(object):
    def getFinalState(self, nums, k, multiplier):
        """
        :type nums: List[int]
        :type k: int
        :type multiplier: int
        :rtype: List[int]
        """
        n = len(nums)
        pq = [(nums[i], i) for i in range(n)]
        heapq.heapify(pq)
        while k > 0:
            i, j = heapq.heappop(pq)
            nums[j] = i * multiplier
            heapq.heappush(pq, (i * multiplier, j))
            k -= 1
        return nums


if __name__ == "__main__":
    obj = Solution()
    print(obj.getFinalState(nums=[2, 1, 3, 5, 6], k=5, multiplier=2))
    print(obj.getFinalState(nums=[1, 2], k=3, multiplier=4))
