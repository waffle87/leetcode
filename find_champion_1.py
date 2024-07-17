# 2923. Find Champion I

"""
there are 'n' teams numbered from 0 to 'n - 1' in a tournament. given
0-indexed 2d boolean matrix 'grid' of size 'n  n'. for all 'i, j' that '0 <=
i, j <= n - 1' and 'i != j' team 'i' is stronger than team 'j' if 'grid[i][j]
== 1' otherwise team 'j' is stronger tham team 'i'. team 'a' will be the
champion of the tournament if there is no team 'b' that is stronger than team
'a'. return the team that will be the champion of the tournament.
"""


class Solution(object):
    def findChampion(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        for i in range(n):
            if sum(grid[i]) == n - 1:
                return i


if __name__ == "__main__":
    obj = Solution()
    print(obj.findChampion(grid=[[0, 1], [0, 0]]))
    print(obj.findChampion(grid=[[0, 0, 1], [1, 0, 1], [0, 0, 0]]))
