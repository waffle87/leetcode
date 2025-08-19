# 2348. Number of Zero-Filled Subarrays

"""
given integer array 'nums', return number of subarrays filled with zero. a
subarray is a contiguous non-empty sequence of elements from within an array
"""


class Solution(object):
    def zeroFilledSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt, streak = 0
        for i in nums:
            if i == 0:
                streak += 1
                cnt += streak
            else:
                streak = 0
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.zeroFilledSubarray(nums=[1, 3, 0, 0, 2, 0, 0, 4]))
    print(obj.zeroFilledSubarray(nums=[0, 0, 0, 2, 0, 0]))
    print(obj.zeroFilledSubarray(nums=[2, 10, 2019]))
