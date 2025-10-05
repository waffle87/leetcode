# 417. Pacific Atlantic Water Flow
from collections import deque

"""
there is an 'm x n' rectangular island that bords both the pacific and
atlantic ocean. the pacific ocean touches the island's left and top edges,
and the atlantic ocean touches the islands right and bottom edges. the island
is partitioned into a grid of square cells. you are given an 'm x n' integer
matrix 'heights' where 'heights[r][c]' represents the height above sea level
of the cell at coordinate '(r, c)'. the island receives a lot of rain, and
the rain water can flow to neighbouring cells directly in any cardinal
direction. return a 2d list of grid coordinates 'result' where 'result[i] =
[r_i, c_i]' denotes that rain water can flow from cell '(r_i, c_i)' to both
the pacific and atlantic oceans.
"""


class Solution(object):
    def pacificAtlantic(self, heights):
        """
        :type heights: List[List[int]]
        :rtype: List[List[int]]
        """
        if not heights or not heights[0]:
            return []
        n, m = len(heights), len(heights[0])

        def bfs(start):
            q = deque(start)
            vis = set(start)
            while q:
                x, y = q.popleft()
                for dx, dy in [(x, y + 1), (x, y - 1), (x - 1, y), (x + 1, y)]:
                    if (
                        0 <= dx < n
                        and 0 <= dy < m
                        and (dx, dy) not in vis
                        and heights[dx][dy] >= heights[x][y]
                    ):
                        q.append((dx, dy))
                        vis.add((dx, dy))
            return vis

        pacific = [(0, i) for i in range(m)] + [(i, 0) for i in range(1, n)]
        atlantic = [(n - 1, i) for i in range(m)] + [(i, m - 1) for i in range(n - 1)]
        return bfs(pacific) & bfs(atlantic)


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.pacificAtlantic(
            heights=[
                [1, 2, 2, 3, 5],
                [3, 2, 3, 4, 4],
                [2, 4, 5, 3, 1],
                [6, 7, 1, 4, 5],
                [5, 1, 1, 2, 4],
            ]
        )
    )
    print(obj.pacificAtlantic(heights=[[1]]))
