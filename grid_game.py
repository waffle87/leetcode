# 2017. Grid Game

"""
you are given a 0-indexed 2d array 'grid' of size '2 x n' where 'grid[r][c]'
represents the number of points at position '[r, c]' on the matrix. two
robots are playing a game on this matrix. both robots initially starts at
'(0, 0)' and want to reach '(1, n - 1)'. each robot may only move to the
right or down. at the start of the game, the first robot moves from '(0, 0)'
to '(1, n - 1)', collecting all the points. first robot wants to minimise the
number of points collected by the second robot. in contrast, the second robot
wants to maximise the number of points it collects. return the number of
points collected by the second robot
"""


class Solution(object):
    def gridGame(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        ans, up, down = float("inf"), sum(grid[0]), 0
        for i in range(len(grid[0])):
            up -= grid[0][i]
            ans = min(ans, max(up, down))
            down += grid[1][i]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.gridGame(grid=[[2, 5, 4], [1, 5, 1]]))
    print(obj.gridGame(grid=[[3, 3, 1], [8, 5, 2]]))
    print(obj.gridGame(grid=[[1, 3, 1, 15], [1, 3, 3, 1]]))
