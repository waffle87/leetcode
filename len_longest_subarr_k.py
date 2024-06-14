# 2958. Length of Longest Subarray With at Most K Frequency
from collections import Counter

"""
given an integer array 'nums' and an integer 'k'. the frequency of an element
x is the number of times it occurs in an array. an array is called good if
the frequency of each element in this array is less than or equal to 'k'.
return the length of the longest good subarray of 'nums' a subarray is a
contiguous non empty sequence of elements within an array
"""


class Solution(object):
    def maxSubarrayLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        cnt = Counter()
        ans, i = 0, 0
        for j in range(len(nums)):
            cnt[nums[j]] += 1
            while cnt[nums[j]] > k:
                cnt[nums[i]] -= 1
                i += 1
            ans = max(ans, j - i + 1)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxSubarrayLength(nums=[1, 2, 3, 1, 2, 3, 1, 2], k=2))
    print(obj.maxSubarrayLength(nums=[1, 2, 1, 2, 1, 2, 1, 2], k=1))
    print(obj.maxSubarrayLength(nums=[5, 5, 5, 5, 5, 5, 5], k=4))
