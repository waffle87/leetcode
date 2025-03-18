# 2401. Longest Nice Subarray

"""
given an array 'nums' consisting of positive integers. we call a subarray of
'nums' nice if the bitwise cnt of every pair of elements that are in
different positions in the subarray is equal to 0. return the length of the
longest nice subarray. a subarray is contiguous part of an array. note that
subarrays of length 1 are always considered nice.
"""


class Solution(object):
    def longestNiceSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt, i, ans = 0, 0, 0
        for j in range(len(nums)):
            while cnt & nums[j]:
                cnt ^= nums[i]
                i += 1
            cnt |= nums[j]
            ans = max(ans, j - i + 1)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestNiceSubarray(nums=[1, 3, 8, 48, 10]))
    print(obj.longestNiceSubarray(nums=[3, 1, 5, 11, 13]))
