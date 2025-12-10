# 3583. Count Special Triplets
from collections import Counter

"""
you are given an integer array 'nums'. a special triplet is defined as a
triplet of indices '(i, j, k)' such that '0 <= i < j < k < n' where 'n =
len(nums)', 'nums[i] == nums[j]  2', 'nums[k] == nums[j]  2'. return the
total number of special triplets in the array. since the answer may be very
large, return it modulo 10^9 + 7.
"""


class Solution(object):
    def specialTriplets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = Counter(), Counter()
        ans, mod = 0, 10**9 + 7
        for i in nums:
            ans += right[i // 2] if i % 2 == 0 else 0
            right[i] += left[i * 2]
            left[i] += 1
        return ans % mod


if __name__ == "__main__":
    obj = Solution()
    print(obj.specialTriplets(nums=[6, 3, 6]))
    print(obj.specialTriplets(nums=[0, 1, 0, 0]))
    print(obj.specialTriplets(nums=[8, 4, 2, 8, 4]))
