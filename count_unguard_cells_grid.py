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
        vis = [[0 for _ in range(n)] for _ in range(m)]
        for i in guards:
            vis[i[0]][i[1]] = 2
        for i in walls:
            vis[i[0]][i[1]] = 3
        for i in range(len(guards)):
            r = guards[i][0]
            c = guards[i][1]
            left, right = c - 1, c + 1
            up, down = r - 1, r + 1
            while left >= 0:
                if vis[r][left] == 3 or vis[r][left] == 2:
                    break
                vis[r][left] = 1
                left -= 1
            while right < n:
                if vis[r][right] == 3 or vis[r][right] == 2:
                    break
                vis[r][right] = 1
                right += 1
            while up >= 0:
                if vis[up][c] == 3 or vis[up][c] == 2:
                    break
                vis[up][c] = 1
                up -= 1
            while down < m:
                if vis[down][c] == 3 or vis[down][c] == 2:
                    break
                vis[down][c] = 1
                down += 1
        return sum(1 for i in range(m) for j in range(n) if vis[i][j] == 0)


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
