# 2134. Minimum Swaps to Group All 1's Together II

"""
a swap is defined as taking two distinct position in an array and swapping
the values in them. a circular array is defined as an array where we consider
the first element and the last element to adjacent. given a binary circular
array 'nums', return the minimum number of swaps required to group all 1's
preent in the array together at any location.
"""


class Solution(object):
    def minSwaps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ones, nums = nums.count(1), nums + nums
        x, curr_ones = 0, 0
        for i in range(len(nums)):
            if i >= ones and nums[i - ones]:
                x -= 1
            if nums[i] == 1:
                x += 1
            curr_ones = max(x, curr_ones)
        return ones - curr_ones


if __name__ == "__main__":
    obj = Solution()
    print(obj.minSwaps(nums=[0, 1, 0, 1, 1, 0, 0]))
    print(obj.minSwaps(nums=[0, 1, 1, 1, 0, 0, 1, 1, 0]))
    print(obj.minSwaps(nums=[1, 1, 0, 0, 1]))
