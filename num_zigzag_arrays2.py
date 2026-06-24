# 3700. Number of ZigZag Arrays II

"""
you are given three integers. a zigzag array of length 'n' is defined as
follows: each element lies in the range '[l, r]', no two adjacent elements
are equal, and no three consecutive elements form a strictly increasing or
decreasing sequence. return the total number of valid zigzag arrays. since
the ans may be large, return it modulo 10^9+7.
"""


class Solution:
    mod = 10**9 + 7

    def matrix_multiply(self, a, b):
        n = len(a)
        res = [[0] * n for _ in range(n)]
        for row in range(n):
            for mid in range(n):
                if a[row][mid] == 0:
                    continue

                for col in range(n):
                    res[row][col] = (
                        res[row][col] + a[row][mid] * b[mid][col]
                    ) % self.mod

        return res

    def matrix_power(self, matrix, power):
        n = len(matrix)
        res = [[1 if row == col else 0 for col in range(n)] for row in range(n)]
        while power:
            if power & 1:
                res = self.matrix_multiply(res, matrix)
            matrix = self.matrix_multiply(matrix, matrix)
            power >>= 1
        return res

    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        val_cnt = r - l + 1
        dp = list(range(val_cnt))
        trans = [[0] * val_cnt for _ in range(val_cnt)]
        for row in range(1, val_cnt):
            for col in range(val_cnt - row, val_cnt):
                trans[row][col] = 1
        pow_trans = self.matrix_power(trans, n - 2)
        ans = 0
        for row in range(val_cnt):
            for col in range(val_cnt):
                ans = (ans + pow_trans[row][col] * dp[col]) % self.mod
        return (ans * 2) % self.mod


if __name__ == "__main__":
    obj = Solution()
    print(obj.zigZagArrays(n=3, l=4, r=5))
    print(obj.zigZagArrays(n=3, l=1, r=3))
