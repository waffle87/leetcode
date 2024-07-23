# 2750. Ways to Split Array Into Good Subarrays

"""
given a binary array 'nums'. a subarray of an array is good if it contains
exactly one element with the value 1. return an integer denoting the number
of ways to split the array 'nums' into good subarrays. as the number may be
too large, return it 10^9+7. a subarray is contiguous non empty sequence of
elements within an array.
"""


class Solution(object):
    def numberOfGoodSubarraySplits(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans, lo = 0, -1
        for hi, i in enumerate(nums):
            if i == 1:
                if ans == 0:
                    ans = 1
                else:
                    ans *= hi - lo
                    ans %= 10**9 + 7
                lo = hi
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfGoodSubarraySplits(nums=[0, 1, 0, 0, 1]))
    print(obj.numberOfGoodSubarraySplits(nums=[0, 1, 0]))
