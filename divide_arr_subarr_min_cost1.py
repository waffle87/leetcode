# 3010. Divide an Array Into Subarrays With Minimum Cost I
import heapq

"""
you are given an array of integers 'nums' of length 'n'. the cost of an array
is the value of its first element. you need to divide 'nums' into 3 disjoint
contiguous subarrays. return the minimum possible sum of the cost of these
subarrays.
"""


class Solution(object):
    def minimumCost(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        h = []
        heapq.heappush(h, -nums[1])
        heapq.heappush(h, -nums[2])
        for i in nums[3:]:
            heapq.heappushpop(h, -i)
        return nums[0] - h[0] - h[1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumCost(nums=[1, 2, 3, 12]))
    print(obj.minimumCost(nums=[5, 4, 3]))
    print(obj.minimumCost(nums=[10, 3, 1, 1]))
