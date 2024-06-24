# 995. Minimum Number of K Consecutive Bit Flips

"""
given a binary array 'nums', and an integer 'k'. a k-bit flip is choosing a
subarray of length 'k' from 'nums' and simultaneously changing every 0 in the
subarray to 1, and every 1 in the subarray to 0. return the minimum number of
k-bit flips required so that there is no 0 in the array. if it is not
possible, return -1. a subarray is a contiguous part of an array.
"""


class Solution(object):
    def minKBitFlips(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        curr, ans, n = 0, 0, len(nums)
        for i in range(len(nums)):
            if i >= k and nums[i - k] > 1:
                nums[i - k] -= 2
                curr -= 1
            if curr & 1 ^ nums[i] == 0:
                if i + k > len(nums):
                    return -1
                nums[i] += 2
                curr += 1
                ans += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minKBitFlips(nums=[0, 1, 0], k=1))
    print(obj.minKBitFlips(nums=[1, 1, 0], k=2))
    print(obj.minKBitFlips(nums=[0, 0, 0, 1, 0, 1, 1, 0], k=3))
