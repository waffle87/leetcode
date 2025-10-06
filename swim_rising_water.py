# 778. Swim in Rising Water
import heapq

"""
you are given an 'n x n' integer matrix 'grid' where each value 'grid[i][j]'
represnts the elevation at that point '(i, j)'. it starts raining and water
gradually rises over time. at time 't', the water level is 't', meaning any
cell with elevation less than or equal to 't' is submerged or reachable. you
can swim from a square to another 4-direction adjacent square if and only if
the elevation of both squares individually are at most 't'. you can swim
infinite distances in zero time. of course, you must stay within the
boundaries of the grid. return the minimum time until you can reach the
bottom right . you can swim infinite distances in zero time. of course, you
must stay within the boundaries of the grid. return the minimum time until
you can reach the bottom right square if you start at the top left. you can
swim infinite distances in zero time. of course, you must stay within the
boundaries of the grid. return the minimum time until you can reach the
bottom right square if you start at the top left..square if you start at the
top left.
"""


class Solution(object):
    def swimInWater(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n, ans = len(grid), 0
        pq = [(grid[0][0], 0, 0)]
        vis = set([(0, 0)])
        while True:
            tmp, x, y = heapq.heappop(pq)
            if x == y == n - 1:
                return ans
            for i, j in [(x + 1, y), (x, y + 1), (x - 1, y), (x, y - 1)]:
                if 0 <= i < n and 0 <= j < n and (i, j) not in vis:
                    vis.add((i, j))
                    heapq.heappush(pq, (grid[i][j], i, j))


if __name__ == "__main__":
    obj = Solution()
    print(obj.swimInWater(grid=[[0, 2], [1, 3]]))
    print(
        obj.swimInWater(
            grid=[
                [0, 1, 2, 3, 4],
                [24, 23, 22, 21, 5],
                [12, 13, 14, 15, 16],
                [11, 17, 18, 19, 20],
                [10, 9, 8, 7, 6],
            ]
        )
    )
