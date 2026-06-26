# 3739. Count Subarrays With Majority Element II
from bisect import bisect_left
from typing import List

"""
you are given an integer array 'nums' and an integer 'target'. return the
number of subarrays of 'nums' in which 'target' is the majority element. the
majority element of a subarray is the element that appears strictly more than
half of the times in that subarray.
"""


class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        freq = [1 if i == target else -1 for i in nums]
        pre, vis, ans = 0, [0], 0
        for i in freq:
            pre += i
            idx = bisect_left(vis, pre)
            ans += idx
            vis.insert(idx, pre)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countMajoritySubarrays(nums=[1, 2, 2, 3], target=2))
    print(obj.countMajoritySubarrays(nums=[1, 1, 1, 1], target=1))
    print(obj.countMajoritySubarrays(nums=[1, 2, 3], target=4))
