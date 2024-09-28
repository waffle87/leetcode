# 2461. Maximum Sum of Distinct Subarrays With Length K

"""
you are given an integer array 'nums' and an integer 'k'. find the maximum
subarray sum of all the subarrays of 'nums' that meet the following
conditions. the length of the subarray is 'k' and all the elements of the
subarray are distinct. return the maximum subarray of all the subarrays that
meet the conditions. if no subarray meets the conditions, return 0. a
subarray is a contiguous non empty sequence of elements within an array
"""


class Solution(object):
    def maximumSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        ans, curr, pos, dup = 0, 0, [-1] * 100001, -1
        for i in range(0, len(nums)):
            curr += nums[i]
            if i >= k:
                curr -= nums[i - k]
            dup = max(dup, pos[nums[i]])
            if i - dup >= k:
                ans = max(ans, curr)
            pos[nums[i]] = i
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumSubarraySum(nums=[1, 5, 4, 2, 9, 9, 9], k=3))
    print(obj.maximumSubarraySum(nums=[4, 4, 4], k=3))
