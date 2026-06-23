# 3699. Number of ZigZag Arrays I

"""
you are given three integers. a zigzag array of length 'n' is defined as
follows: each element lies in the '[l, r]', no two adjacent elements are
equal, and no three consecutive elements form a strickly increasing or
decreasing sequence. return the totla number of valid zigzag arrays. since
the answer may be very large, return it modulo 10^9+7.
"""


class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        mod = 10**9 + 7
        m = r - l + 1
        dp = [1] * m
        for i in range(2, n + 1):
            dp.reverse()
            total = 0
            for j in range(m):
                dp[j], total = total, (total + dp[j]) % mod
        return (sum(dp) % mod << 1) % mod


if __name__ == "__main__":
    obj = Solution()
    print(obj.zigZagArrays(n=3, l=4, r=5))
    print(obj.zigZagArrays(n=3, l=1, r=3))
