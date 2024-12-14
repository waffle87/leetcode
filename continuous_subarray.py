# 2762. Continuous Subarrays

"""
you are given a 0-indexed integer array 'nums'. a subarray of 'nums' is
called continuous if: let 'i', 'i + 1', ..., 'j' be the indices in the
subarray. then, for each pair of indices 'i <= i_1, i_2 <= j', '0 <= |
nums[i_1] - nums[i_2]| <= 2'. return the total number of continuous
subarrays. a subarray is a contiguous non-empty sequence of elements within
an array
"""


class Solution(object):
    def continuousSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i, ans, d = 0, 0, dict()
        for j, n in enumerate(nums):
            t = d.copy()
            for k, v in t.items():
                if abs(k - n) > 2:
                    i = max(i, v + 1)
                    d.pop(k)
            d[n] = j
            ans += j - i + 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.continuousSubarrays(nums=[5, 4, 2, 4]))
    print(obj.continuousSubarrays(nums=[1, 2, 3]))
