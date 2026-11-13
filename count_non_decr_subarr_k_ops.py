# 3420. Count Non-Decreasing Subarrays After K Operations

"""
you are given an array 'nums' of 'n' integers and an integer 'k'. for each
sbuarray of 'nums', you can apply up to 'k' operations on it. in each
operation, you incremenet any element of the subarray by 1. note that each
subarray is considered independently, meaning changes made to one subarray do
not persist to another. return the number of subarrays that you can make
non-decreasing after performing at most 'k' operations. an array is said to
be non decreasing if each element is greater than or equal to its previous
element
"""

from collections import deque


class Solution:
    def countNonDecreasingSubarrays(self, nums: list[int], k: int) -> int:
        starts = deque()
        ans, water, r = 0, 0, len(nums) - 1
        for l in reversed(range(len(nums))):
            x = nums[l]
            while starts and nums[starts[0]] <= x:
                s = starts.popleft()
                end = starts[0] if starts else r + 1
                water += (x - nums[s]) * (end - s)
            starts.appendleft(l)
            while water > k:
                water -= nums[starts[-1]] - nums[r]
                if starts[-1] == r:
                    starts.pop()
                r -= 1
            ans += r - l + 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countNonDecreasingSubarrays(nums=[6, 3, 1, 2, 4, 4], k=7))
    print(obj.countNonDecreasingSubarrays(nums=[6, 3, 1, 3, 6], k=4))
