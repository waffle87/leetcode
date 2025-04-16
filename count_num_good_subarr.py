# 2537. Count the Number of Good Subarrays
from collections import Counter

"""
given an integer array 'nums' and an integer 'k', return the number of good
subarrays of 'nums'. a subarray 'arr' is good if there are at least 'k' pairs
of indices '(i, j)' such that 'i < j' and 'arr[i] == arr[j]'. a subarray is a
contiguous non-empty sequence of elements within an array.
"""


class Solution(object):
    def countGood(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        ans, i = 0, 0
        cnt = Counter()
        for j in range(len(nums)):
            k -= cnt[nums[j]]
            cnt[nums[j]] += 1
            while k <= 0:
                cnt[nums[i]] -= 1
                k += cnt[nums[i]]
                i += 1
            ans += i
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countGood(nums=[1, 1, 1, 1, 1], k=10))
    print(obj.countGood(nums=[3, 1, 4, 3, 2, 2, 4], k=2))
