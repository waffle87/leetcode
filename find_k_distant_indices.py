# 2200. Find All K-Distant Indices in an Array
import bisect

"""
you are given a 0-indexed integer array 'nums' and two integers 'key' and 'k'
a k-distant index is an index 'i' of 'nums' for which there exists at least
one index 'j' such that '|i - j| <= k' and 'nums[j] == key'. return a list of
all k-distant indices sorted in increasing order
"""


class Solution(object):
    def findKDistantIndices(self, nums, key, k):
        """
        :type nums: List[int]
        :type key: int
        :type k: int
        :rtype: List[int]
        """
        keys = [i for (i, j) in enumerate(nums) if j == key]
        ans = set(keys)
        for i in range(len(nums)):
            idx = bisect.bisect_left(keys, i)
            if 0 <= idx < len(keys) and abs(i - keys[idx]) <= k:
                ans.add(i)
            if 0 < idx <= len(keys) and abs(i - keys[idx - 1]) <= k:
                ans.add(i)
        return sorted(list(ans))


if __name__ == "__main__":
    obj = Solution()
    print(obj.findKDistantIndices(nums=[3, 4, 9, 1, 3, 9, 5], key=9, k=1))
    print(obj.findKDistantIndices(nums=[2, 2, 2, 2, 2], key=2, k=2))
