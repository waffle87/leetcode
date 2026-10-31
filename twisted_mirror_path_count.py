# 3665. Twisted Mirror Path Count


class Solution:
    def uniquePaths(self, grid: list[list[int]]) -> int:
        mat = [[[1, 1], [1, 1]], [[0, 1], [1, 0]]]
        mod = 10**9 + 7
        n, ans = len(grid[0]), 0
        dp = [0] * n
        for i in grid:
            ans = 0
            for j, k in enumerate(i):
                top = dp[j]
                dp[j] = (ans * mat[k][1][0] + top * mat[k][1][1]) % mod
                ans = (ans * mat[k][0][0] + top * mat[k][0][1]) % mod
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.uniquePaths(grid=[[0, 1, 0], [0, 0, 1], [1, 0, 0]]))
    print(obj.uniquePaths(grid=[[0, 0], [0, 0]]))
    print(obj.uniquePaths(grid=[[0, 1, 1], [1, 1, 0]]))
