# 1458. Max Dot Product of Two Subsequences

"""
given two arrays 'nums1, nums2'. return the maximum dot product between
non-empty subsequences of nums1 and nums2 with the same length. a subsequence
of an array is a new array which is formed from the original array by
deleting some (can be none) of the characters without disturbing the relative
positions of the remaining characters.
"""


class Solution(object):
    def maxDotProduct(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        n, m = len(nums1), len(nums2)
        dp = [[0] * m for i in range(n)]
        for i in range(n):
            for j in range(m):
                dp[i][j] = nums1[i] * nums2[j]
                if i and j:
                    dp[i][j] += max(dp[i - 1][j - 1], 0)
                    if i:
                        dp[i][j] = max(dp[i][j], dp[i - 1][j])
                    if j:
                        dp[i][j] = max(dp[i][j], dp[i][j - 1])
        return dp[-1][-1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxDotProduct(nums1=[2, 1, -2, 5], nums2=[3, 0, -6]))
    print(obj.maxDotProduct(nums1=[3, -2], nums2=[2, -6, 7]))
    print(obj.maxDotProduct(nums1=[-1, -1], nums2=[1, 1]))
