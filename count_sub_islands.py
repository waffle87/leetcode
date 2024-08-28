# 1905. Count Sub Islands

"""
you are given two 'm * n' binary matricies 'grid1', and 'grid2' containing
only 0's (represeting water) and 1's (representing land). an island is a
group of 1's connected 4 directionally (horizontal or vertical). any cells
outside of the grid are considered water cells. an island in 'grid2' is
considered a sub-island if there is an island in 'grid1' that contains all
the cells that make up this island is 'grid2'. return the number of islands
in 'grid2' that are considered sub islands
"""


class Solution(object):
    def countSubIslands(self, grid1, grid2):
        """
        :type grid1: List[List[int]]
        :type grid2: List[List[int]]
        :rtype: int
        """
        n, m = len(grid1), len(grid1[0])

        def dfs(i, j):
            if not (0 <= i < n and 0 <= j < m and grid1[i][j] == 1):
                return 1
            grid1[i][j] = 0
            res = grid2[i][j]
            for di, dj in [[0, 1], [1, 0], [-1, 0], [0, -1]]:
                res &= dfs(i + di, j + dj)
            return res

        return sum(dfs(i, j) for i in range(n) for j in range(m) if grid1[i][j])


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.countSubIslands(
            grid1=[
                [1, 1, 1, 0, 0],
                [0, 1, 1, 1, 1],
                [0, 0, 0, 0, 0],
                [1, 0, 0, 0, 0],
                [1, 1, 0, 1, 1],
            ],
            grid2=[
                [1, 1, 1, 0, 0],
                [0, 0, 1, 1, 1],
                [0, 1, 0, 0, 0],
                [1, 0, 1, 1, 0],
                [0, 1, 0, 1, 0],
            ],
        )
    )
    print(
        obj.countSubIslands(
            grid1=[
                [1, 0, 1, 0, 1],
                [1, 1, 1, 1, 1],
                [0, 0, 0, 0, 0],
                [1, 1, 1, 1, 1],
                [1, 0, 1, 0, 1],
            ],
            grid2=[
                [0, 0, 0, 0, 0],
                [1, 1, 1, 1, 1],
                [0, 1, 0, 1, 0],
                [0, 1, 0, 1, 0],
                [1, 0, 0, 0, 1],
            ],
        )
    )
