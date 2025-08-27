# 3459. Length of Longest V-Shaped Diagonal Segment

"""
you are given a 2d integer matrix 'grid' of size 'n x m', where each element
is either 0, 1, or 2. a v-shaped diagonal segment is defined as: the segment
starts with 1, the subsequent elements follow this infinite sequence '2, 0,
2, 0, ...', the segment starts along a diagonal direction, the segment
continues the sequence in the same diagonal direction, and the segment makes
at most one clockwise 90-degree turn to another diagonal direction while
maintaining the sequence.
"""


class Solution(object):
    def lenOfVDiagonal(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        ds = [[1, 1], [1, -1], [-1, -1], [-1, 1]]
        nx = [2, 2, 0]
        ans, n, m = 0, len(grid), len(grid[0])

        def dp(i, j, x, d, k):
            if not (0 <= i < n and 0 <= j < m):
                return 0
            if grid[i][j] != x:
                return 0
            res = dp(i + ds[d][0], j + ds[d][1], nx[x], d, k) + 1
            if k > 0:
                d2 = (d + 1) % 4
                res2 = dp(i + ds[d2][0], j + ds[d2][1], nx[x], d2, 0) + 1
                res = max(res, res2)
            return res

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    curr = max(dp(i, j, 1, d, 1) for d in range(4))
                    ans = max(ans, curr)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.lenOfVDiagonal(
            grid=[
                [2, 2, 1, 2, 2],
                [2, 0, 2, 2, 0],
                [2, 0, 1, 1, 0],
                [1, 0, 2, 2, 2],
                [2, 0, 0, 2, 2],
            ]
        )
    )
    print(
        obj.lenOfVDiagonal(
            grid=[
                [2, 2, 2, 2, 2],
                [2, 0, 2, 2, 0],
                [2, 0, 1, 1, 0],
                [1, 0, 2, 2, 2],
                [2, 0, 0, 2, 2],
            ]
        )
    )
    print(
        obj.lenOfVDiagonal(
            grid=[
                [1, 2, 2, 2, 2],
                [2, 2, 2, 2, 0],
                [2, 0, 0, 0, 0],
                [0, 0, 2, 2, 2],
                [2, 0, 0, 2, 0],
            ]
        )
    )
