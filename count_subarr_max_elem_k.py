# 2962. Count Subarrays Where Max Element Appears at Least K Times

"""
given an integer array 'nums' and a positive integer 'k'. return the number
of subarrays where the maximum element of 'nums' appears at least 'k' times
in that subarray. a subarray is a contiguous sequence of elements within an
array.
"""


class Solution(object):
    def countSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        m = max(nums)
        ans, curr, i = 0, 0, 0
        for j in range(len(nums)):
            curr += nums[j] == m
            while curr >= k:
                curr -= nums[i] == m
                i += 1
            ans += i
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countSubarrays(nums=[1, 3, 2, 3, 3], k=2))  # expect: 6
    print(obj.countSubarrays(nums=[1, 4, 2, 1], k=3))  # expect: 0
