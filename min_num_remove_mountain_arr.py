# 1671. Minimum Number of Removals to Make Mountain Array
from bisect import bisect_left

"""
you may recall that an array 'arr' is a mountain array if and only if
'arr.length >= 3', there exists soome index 'i' with '0 < i < arr.length - 1'
such that 'arr[0] < arr[1] <... < arr[i - 1]' and 'arr[i] > arr[i + 1] > ...
> arr[length - 1]'. given an integer array 'nums', return the minimum number
of elements to remove to make 'nums' a mountain array
"""


class Solution(object):
    def minimumMountainRemovals(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        def lis(nums):
            dp = [10**10] * (len(nums) + 1)
            lens = [0] * len(nums)
            for i, j in enumerate(nums):
                lens[i] = bisect_left(dp, j) + 1
                dp[lens[i] - 1] = j
            return lens

        l1, l2 = lis(nums), lis(nums[::-1])[::-1]
        ans, n = 0, len(nums)
        for i in range(n):
            if l1[i] >= 2 and l2[i] >= 2:
                ans = max(ans, l1[i] + l2[i] - 1)
        return n - ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumMountainRemovals(nums=[1, 3, 1]))
    print(obj.minimumMountainRemovals(nums=[2, 1, 1, 5, 6, 2, 3, 1]))
