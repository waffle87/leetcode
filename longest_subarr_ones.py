# 1493. Longest Subarray of 1's After Deleting One Element

"""
given a binary array 'nums', you should delete one element from it. return
the size of the longest non-empty subarray containing only 1's in the
resulting array. return 0 if there is no such subarray.
"""


class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, zeros, ans = 0, 0, 0
        for right in range(len(nums)):
            if nums[right] == 0:
                zeros += 1
            while zeros > 1:
                if nums[left] == 0:
                    zeros -= 1
                left += 1
            ans = max(ans, right - left)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestSubarray(nums=[1, 1, 0, 1]))
    print(obj.longestSubarray(nums=[0, 1, 1, 1, 0, 1, 1, 0, 1]))
    print(obj.longestSubarray(nums=[1, 1, 1]))
