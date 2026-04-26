# 1559. Detect Cycles in 2D Grid
from typing import List

"""
given a 2d array of characters 'grid' of size 'm x n', you eed to find if
there exists any cycle consisting of the same value in 'grid'. a cycle is a
path of length 4 or more in the grid that starts and ends at the same cell.
from a given cell, you can move to one of the cells adjacent to it - in one
of the four directions, if it has the same value of the current cell. also,
you cannot move to the cell that you visited in your last move. return true
if any cycle of the same value exists in 'grid', otherwise return false.
"""


class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        def dfs(node, parent):
            if node in vis:
                return True
            vis.add(node)
            nx, ny = node
            childs = [
                (cx, cy)
                for cx, cy in [[nx + 1, ny], [nx - 1, ny], [nx, ny + 1], [nx, ny - 1]]
                if 0 <= cx < m
                and 0 <= cy < n
                and grid[cx][cy] == grid[nx][ny]
                and (cx, cy) != parent
            ]
            for x in childs:
                if dfs(x, node):
                    return True
            return False

        m, n = len(grid), len(grid[0])
        vis = set()
        for i in range(m):
            for j in range(n):
                if (i, j) in vis:
                    continue
                if dfs((i, j), None):
                    return True
        return False


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.containsCycle(
            grid=[
                ["a", "a", "a", "a"],
                ["a", "b", "b", "a"],
                ["a", "b", "b", "a"],
                ["a", "a", "a", "a"],
            ]
        )
    )
    print(
        obj.containsCycle(
            grid=[
                ["c", "c", "c", "a"],
                ["c", "d", "c", "c"],
                ["c", "c", "e", "c"],
                ["f", "c", "c", "c"],
            ]
        )
    )
    print(obj.containsCycle(grid=[["a", "b", "b"], ["b", "z", "b"], ["b", "b", "a"]]))
