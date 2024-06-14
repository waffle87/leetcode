# 713. Subarray Product Less Than K

"""
given an array of integers 'nums' and an integer 'k', return the number of
contiguous subarrays where the product of all the elements in the subarray is
strictly less than 'k'.
"""


class Solution(object):
    def numSubarrayProductLessThanK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        left, prod, cnt = 0, 1, 0
        for right in range(len(nums)):
            prod *= nums[right]
            while prod >= k and left <= right:
                prod /= nums[left]
                left += 1
            cnt += right - left + 1
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.numSubarrayProductLessThanK([10, 5, 2, 6], 100))
    print(obj.numSubarrayProductLessThanK([1, 2, 3], 0))
