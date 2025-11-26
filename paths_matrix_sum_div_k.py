# 2435. Paths in Matrix Whose Sum Is Divisible by K

"""
you are given a 0-indexed 'm x n' integer matrix 'grid' and an integer 'k'.
you are currently at position '(0, 0)' and you want to reach point '(m - 1, n
-1)' moving only down or right. return the number of paths where the sum of
the elements on the path is divisble by 'k'. since the answer may be very
large, return it modulo 10^9 + 7.
"""


class Solution(object):
    def numberOfPaths(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: int
        """
        mod, m, n = 10**9 + 7, len(grid), len(grid[0])
        prev = [[0] * k for _ in range(n)]
        curr = [[0] * k for _ in range(n)]
        total = 0
        for j in range(n):
            total = (total + grid[0][j]) % k
            prev[j][total] = 1
        total = grid[0][0] % k
        for i in range(1, m):
            total = (total + grid[i][0]) % k
            curr[0] = [0] * k
            curr[0][total] = 1
            for j in range(1, n):
                curr[j] = [0] * k
                val = grid[i][j]
                for r in range(k):
                    new = (r + val) % k
                    curr[j][new] = (prev[j][r] + curr[j - 1][r]) % mod
            prev, curr = curr, prev
        return prev[n - 1][0]


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfPaths(grid=[[5, 2, 4], [3, 0, 5], [0, 7, 2]], k=3))
    print(obj.numberOfPaths(grid=[[0, 0]], k=5))
    print(obj.numberOfPaths(grid=[[7, 3, 4, 9], [2, 3, 6, 2], [2, 3, 7, 0]], k=1))
