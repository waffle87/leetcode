# 3471. Find the Largest Almost Missing Integer

"""
you are given an integer array 'nums' and an integer 'k'. an integer 'x' is
almost missing from 'nums' if 'x' appears in exactly one subarray of size 'k'
within 'nums'. return the largest almost missing integer from 'nums'. if no
such integer exists, return -1. a subarray is a contiguous sequence of
elements within an array.
"""


class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        freq = [0] * 51
        for i in nums:
            freq[i] += 1
        ans, n = -1, len(nums)
        for i, j in enumerate(nums):
            if k == n or (freq[j] == 1 and (k == 1 or not i or i + 1 == n)):
                ans = max(ans, j)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.largestInteger(nums=[3, 9, 2, 1, 7], k=3))
    print(obj.largestInteger(nums=[3, 9, 7, 2, 1, 7], k=4))
    print(obj.largestInteger(nums=[0, 0], k=1))
