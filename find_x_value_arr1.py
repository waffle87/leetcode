# 3524. Find X Value of Array I

"""
you are given an array of positive integers 'nums', and a positive integer
'k'. you are allowed to perform an operation once on 'nums' where in each
operation you can remove any non-overlapping prefix and suffix from 'nums'
such that 'nums' remains non-empty. you need to find the x-value of 'nums'
which is the nmber of ways to perform this operation so that the product of
the remaining elements leaves a remainder of 'x' when divided by 'k'.
"""


class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        ans = [0] * k
        dp = [[0] * k for _ in range(n)]
        for i in range(n):
            dp[i][nums[i] % k] += 1
            if i > 0:
                for r in range(k):
                    rem = (r * nums[i]) % k
                    dp[i][rem] += dp[i - 1][r]
        for i in range(n):
            for r in range(k):
                ans[r] += dp[i][r]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.resultArray(nums=[1, 2, 3, 4, 5], k=3))
    print(obj.resultArray(nums=[1, 2, 4, 8, 16, 32], k=4))
    print(obj.resultArray(nums=[1, 1, 2, 1, 1], k=2))
