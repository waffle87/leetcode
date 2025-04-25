# 2845. Count of Interesting Subarrays
from collections import Counter

"""
you are given a 0-indexed integer array 'nums', an integer 'modulo', and an
integer 'k'. your task is to find the count of the subarrays that are
interesting. a subarray 'nums[l..r]' is interesting if the following
condition holds: let 'cnt' be the number of indices 'i' in the range '[l, r]'
such that 'nums[i] % modulo == k'. then 'cnt % modulo == k'. return an
integer denoting the count of interesting subarrays.
"""


class Solution(object):
    def countInterestingSubarrays(self, nums, modulo, k):
        """
        :type nums: List[int]
        :type modulo: int
        :type k: int
        :rtype: int
        """
        ans, cnt = 0, 0
        m = Counter({0: 1})
        for i in nums:
            cnt = (cnt + (1 if i % modulo == k else 0)) % modulo
            ans += m[(cnt - k) % modulo]
            m[cnt] += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countInterestingSubarrays(nums=[3, 2, 4], modulo=2, k=1))
    print(obj.countInterestingSubarrays(nums=[3, 1, 9, 6], modulo=3, k=0))
