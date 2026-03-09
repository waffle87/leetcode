# 3129. Find All Possible Stable Binary Arrays I

"""
you are given 3 positive integers 'zero', 'one', and 'limit'. a binary array
'arr' is called stable if the number of occurences of 0 in 'arr' is exactly
0, the number of occurences of 1 in 'arr' is exactly 'one', and each subarray
of 'arr' with a size greater than 'limit' must contain both 0 and 1. return
the total number of stable binary arrays. since the answer may be very large,
return it modulo 10^9 + 7.
"""


class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        mod = 10**9 + 7

        dp0 = [[0] * (one + 1) for _ in range(zero + 1)]
        dp1 = [[0] * (one + 1) for _ in range(zero + 1)]
        for i in range(1, min(zero, limit) + 1):
            dp0[i][0] = 1
        for j in range(1, min(one, limit) + 1):
            dp1[0][j] = 1
        for i in range(1, zero + 1):
            for j in range(1, one + 1):
                dp0[i][j] = (
                    sum(dp1[i - k][j] for k in range(1, min(limit, i) + 1)) % mod
                )
                dp1[i][j] = (
                    sum(dp0[i][j - k] for k in range(1, min(limit, j) + 1)) % mod
                )
        return (dp0[zero][one] + dp1[zero][one]) % mod


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfStableArrays(zero=1, one=1, limit=2))
    print(obj.numberOfStableArrays(zero=1, one=2, limit=1))
    print(obj.numberOfStableArrays(zero=3, one=3, limit=2))
