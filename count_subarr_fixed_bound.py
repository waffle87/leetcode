# 2444. Count Subarrays With Fixed Bounds

"""
given an integer array 'nums' and two integer 'mink' and 'maxk'. a fixed
bound subarray of 'nums' is a subarray that satisfies the following
conditions. the minimum value in the subarray is equal to 'mink' and the
maximum value in the subarray is equal to 'maxk'. return the number of fixed
bound subarrays. a subarray is a contiguous part of an array.
"""


class Solution(object):
    def countSubarrays(self, nums, minK, maxK):
        """
        :type nums: List[int]
        :type minK: int
        :type maxK: int
        :rtype: int
        """
        ans, prev_min, prev_max, bad = 0, -1, -1, -1
        for i, a in enumerate(nums):
            if not minK <= a <= maxK:
                bad = i
            if a == minK:
                prev_min = i
            if a == maxK:
                prev_max = i
            ans += max(0, min(prev_min, prev_max) - bad)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countSubarrays(nums=[1, 3, 5, 2, 7, 5], minK=1, maxK=5))  # expect: 2
    print(obj.countSubarrays(nums=[1, 1, 1, 1], minK=1, maxK=1))  # expect: 10
