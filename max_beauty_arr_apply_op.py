# 2779. Maximum Beauty of an Array After Applying Operation

"""
you are given a 0-indexed array 'nums' and a non-negative integer 'k'. in one
operation you can do the following: choose an index 'i' that hasn't been
chosen before from the range '[0, nums.len - 1]', replace 'nums[i]' with any
integer from the range '[nums[i] - k, nums[i] + k]'. the beauty of the array
is the length of the longest subsequence consisting of equal elements. return
the maximum possible beauty of the array 'nums' after applying the operation
any number of times. note that you can apply the operation to each index only
once. a subsequence of an array is a new array generate from the original
array by deleting some elements (possibly none) without changing the order of
the remaining elements.
"""


class Solution(object):
    def maximumBeauty(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        i = 0
        for j in range(len(nums)):
            if nums[j] - nums[i] > k * 2:
                i += 1
        return j - i + 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumBeauty(nums=[4, 6, 1, 2], k=2))
    print(obj.maximumBeauty(nums=[1, 1, 1, 1], k=10))
