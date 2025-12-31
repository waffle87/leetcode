# 1970. Last Day Where You Can Still Cross

"""
there is a 1-based binary matrix where '0' represents land and '1' represents
water. you are given integers 'row' and 'col' representing the number of rows
and columns in the matrix, repsectively. initially, on day 0, the entier
matrix is land. however, each day a new cell becomes flooded with water. you
are given a 1-based 2d array 'cells' where 'cells[i] = [ri, ci]' represents
that on the i'th day, the cell on the ri'th row and the ci'th column will be
covered with water. you want to find the last day that it is still possible
to walk from the top to the bottom only by walking on land cells. you can
start rom any cell in the top row and end at any cell in the bottom row. you
can only travel in the four cardinal directions.
"""


class Solution(object):
    def latestDayToCross(self, row, col, cells):
        """
        :type row: int
        :type col: int
        :type cells: List[List[int]]
        :rtype: int
        """
        n = row * col
        top, bottom = n, n + 1
        parent = list(range(n + 2))
        rank = [0] * (n + 2)
        land = [False] * n

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(a, b):
            a, b = find(a), find(b)
            if a == b:
                return
            if rank[a] < rank[b]:
                parent[a] = b
            elif rank[a] > rank[b]:
                parent[b] = a
            else:
                parent[b] = a
                rank[a] += 1

        for d in range(len(cells) - 1, -1, -1):
            r, c = cells[d][0] - 1, cells[d][1] - 1
            idx = r * col + c
            land[idx] = True
            for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                nr, nc = r + dr, c + dc
                if 0 <= nr < row and 0 <= nc < col:
                    nid = nr * col + nc
                    if land[nid]:
                        union(idx, nid)
            if r == 0:
                union(idx, top)
            if r == row - 1:
                union(idx, bottom)
            if find(top) == find(bottom):
                return d
        return 0


if __name__ == "__main__":
    obj = Solution()
    print(obj.latestDayToCross(row=2, col=2, cells=[[1, 1], [2, 1], [1, 2], [2, 2]]))
    print(obj.latestDayToCross(row=2, col=2, cells=[[1, 1], [1, 2], [2, 1], [2, 2]]))
    print(
        obj.latestDayToCross(
            row=3,
            col=3,
            cells=[
                [1, 2],
                [2, 1],
                [3, 3],
                [2, 2],
                [1, 1],
                [1, 3],
                [2, 3],
                [3, 2],
                [3, 1],
            ],
        )
    )
