# 3350. Adjacent Increasing Subarrays Detection II

"""
given an array 'nums' of 'n' integers, your task is to find the maximum value
of 'k' for which there exists two adjacent subarrays of length 'k' each, such
that both subarrays are strictly increasing. specifically, check if there are
two subarrays of length 'k' starting at indices 'a' and 'b' where both
subarrays are strictly increasing, and the subarrays must be adjacent,
meaning 'b = a + k'. return the maximum possible value of 'k'. a subarrays is
a contiguous non-empty sequence of elements within an array
"""


class Solution(object):
    def maxIncreasingSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n, ans = len(nums), 0
        up, pre = 1, 0
        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                up += 1
            else:
                pre = up
                up = 1
            half = up >> 1
            m = min(pre, up)
            candidate = max(half, m)
            if candidate > ans:
                ans = candidate
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxIncreasingSubarrays(nums=[2, 5, 7, 8, 9, 2, 3, 4, 3, 1]))
    print(obj.maxIncreasingSubarrays(nums=[1, 2, 3, 4, 4, 4, 4, 5, 6, 7]))
