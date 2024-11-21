# 2257. Count Unguarded Cells in the Grid

"""
you are given two integers 'm' and 'n' representing a 0-indexed 'm x n' grid.
you are also given two 2d integer arrays 'guards' and 'walls' where
'guards[i] = [row_i, col_i]' and 'walls[j] = [row_i, col_i]' represent the
positions of the i'th guard and j'th wall respectively. a guard can see every
cell in the four cardinal directions starting from their position unless
obstructed by a wall or another guard. a cell is guarded if there is at least
one guard that can see it. return the number of unoccupied cells that are not
guarded.
"""


class Solution(object):
    def countUnguarded(self, m, n, guards, walls):
        """
        :type m: int
        :type n: int
        :type guards: List[List[int]]
        :type walls: List[List[int]]
        :rtype: int
        """
        vis = [[0] * n for _ in range(m)]
        for val in walls:
            vis[val[0]][val[1]] = 2
        for val in guards:
            vis[val[0]][val[1]] = 3
        for val in guards:
            row, col = val[0], val[1]
            for i in range(row + 1, m):
                if vis[i][col] in (2, 3):
                    break
                vis[i][col] = 1
            for i in range(row - 1, -1, -1):
                if vis[i][col] in (2, 3):
                    break
                vis[i][col] = 1
            for i in range(col + 1, n):
                if vis[row][i] in (2, 3):
                    break
                vis[row][i] = 1
            for i in range(col - 1, -1, -1):
                if vis[row][i] in (2, 3):
                    break
                vis[row][i] = 1
        unguarded = 0
        for i in range(m):
            for j in range(n):
                if vis[i][j] == 0:
                    unguarded += 1
        return unguarded


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.countUnguarded(
            m=4, n=6, guards=[[0, 0], [1, 1], [2, 3]], walls=[[0, 1], [2, 2], [1, 4]]
        )
    )
    print(
        obj.countUnguarded(
            m=3, n=3, guards=[[1, 1]], walls=[[0, 1], [1, 0], [2, 1], [1, 2]]
        )
    )
