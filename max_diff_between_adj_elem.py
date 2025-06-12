# 3423. Maximum Difference Between Adjacent Elements in a Circular Array

"""
given a circular array 'nums', find the maximum absolute difference between
adjacent elements. note, in a circular array, the first and last elements are
adjacent.
"""


class Solution(object):
    def maxAdjacentDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        ans = abs(nums[0] - nums[n - 1])
        for i in range(1, n):
            curr = abs(nums[i - 1] - nums[i])
            ans = max(ans, curr)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxAdjacentDistance(nums=[1, 2, 4]))
    print(obj.maxAdjacentDistance(nums=[-5, -10, -5]))
