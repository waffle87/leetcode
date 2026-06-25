# 3737. Count Subarrays With Majority Element I
from typing import List

"""
you are given an integer array 'nums' and an integer 'target'. return the
number of subarrays of 'nums' in which 'target' is the majority element. the
majority element of a subarray is the element that appears strictly more than
half of the times in that subarray.
"""


class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        pre = [0] * (2 * n + 1)
        pre[n] = 1
        cnt, pre_sum, ans = n, 0, 0
        for i in nums:
            if i == target:
                pre_sum += pre[cnt]
                cnt += 1
                pre[cnt] += 1
            else:
                cnt -= 1
                pre_sum -= pre[cnt]
                pre[cnt] += 1
            ans += pre_sum
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countMajoritySubarrays(nums=[1, 2, 2, 3], target=2))
    print(obj.countMajoritySubarrays(nums=[1, 1, 1, 1], target=1))
    print(obj.countMajoritySubarrays(nums=[1, 2, 3], target=4))
