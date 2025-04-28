# 2302. Count Subarrays With Score Less Than K

"""
the score of an array is defined as the product of its sum and its length.
given a positive integer array 'nums' and an integer 'k', return the number
of non-empty subarrays of 'nums' whose score is strictly less than 'k'. a
subarray is a contiguous sequence of elements within an array.
"""


class Solution(object):
    def countSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        ans, curr, i = 0, 0, 0
        for j in range(len(nums)):
            curr += nums[j]
            while curr * (j - i + 1) >= k:
                curr -= nums[i]
                i += 1
            ans += j - i + 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countSubarrays(nums=[2, 1, 4, 3, 5], k=10))
    print(obj.countSubarrays(nums=[1, 1, 1], k=5))
