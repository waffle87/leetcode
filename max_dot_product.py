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
        n, m = len(nums1), len(nums2)
        dp = [[0] * (m) for in xrange(n)]
        for i in xrange(n):
            for j in xrange(m):
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
    print(obj.maxDotProduct([2,1,-2,5], [3,0,-6])) # expect: 18
    print(obj.maxDotProduct([3,-2],[2,-6,7])) # expect: 21
    print(obj.maxDotProduct([-1,-1],[1,1])) # expect: -1
