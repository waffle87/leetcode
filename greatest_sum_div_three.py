# 1262. Greatest Sum Divisible by Three

"""
given an integer array 'nums', return the maximum possible sum of elements of
the array such that it is divisible by three
"""


class Solution(object):
    def maxSumDivThree(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = [[0, 0, 0], [0, float("-inf"), float("-inf")]]
        for i, j in enumerate(nums):
            k = j % 3
            for m in range(3):
                prev = (3 + m - k) % 3
                take = j + dp[(i + 1) & 1][prev]
                skip = dp[(i + 1) & 1][m]
                dp[i & 1][m] = max(take, skip)
        return max(0, dp[(len(nums) - 1) & 1][0])


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxSumDivThree(nums=[3, 6, 5, 1, 8]))
    print(obj.maxSumDivThree(nums=[4]))
    print(obj.maxSumDivThree(nums=[1, 2, 3, 4, 4]))
