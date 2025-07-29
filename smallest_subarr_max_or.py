# 2411. Smallest Subarrays With Maximum Bitwise OR

"""
you are given a 0-indexed array 'nums' of length 'n', consisting of
non-negative integers. for each index 'i' from 0 to 'n - 1', you must
determine the size of the minimum sized non-empty subarray of 'nums' starting
at 'i' that has the maximum possible bitwise or. the bitwosee or of an array
is the bitwise or of all the numbers in it. return an integer array 'answer'
of size 'n' where 'answer[i]' is the length of the minimum sized subarray
starting at 'i' with maximum bitwise or. a subarray is a contiguous non-empty
sequence of elements within an array.
"""


class Solution(object):
    def smallestSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        prev = [0] * 32
        n = len(nums)
        ans = [0] * n
        for i in range(n - 1, -1, -1):
            for j in range(32):
                if nums[i] & (1 << j):
                    prev[j] = i
            ans[i] = max(1, max(prev) - i + 1)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.smallestSubarrays(nums=[1, 0, 2, 1, 3]))
    print(obj.smallestSubarrays(nums=[1, 2]))
