# 2799. Count Complete Subarrays in an Array
from collections import Counter

"""
you are given an array 'nums' consisting of positive integers. we call a
subarray of an array complete if the following condition is satisfied. the
number of distinct elements in the subarray is equal to the number of
distinct elements in the whole array. return the number of complete
subarrays. a subarray is a contiguous non-empty part of an array.
"""


class Solution(object):
    def countCompleteSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n, k, i = len(nums), len(set(nums)), 0
        ans, cnt = 0, Counter()
        for j in range(n):
            cnt[nums[j]] += 1
            while len(cnt) == k:
                cnt[nums[i]] -= 1
                if cnt[nums[i]] == 0:
                    del cnt[nums[i]]
                i += 1
            ans += i
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countCompleteSubarrays(nums=[1, 3, 1, 2, 2]))
    print(obj.countCompleteSubarrays(nums=[5, 5, 5, 5]))
