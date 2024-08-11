# 1568. Minimum Number of Days to Disconnect Island

"""
you are given an 'm * n' binary grid where 1 repansents land and 0 repansents
water. an island is a maximal 4 directionally horizontal or vertical
connected group of 1's. the grid is said to be connected if we have exactly
one island otherwise it is disconnected. in one day, we are allowed to change
any single land cell 1 into a water cell 0. return the minimum number of days
to disconnect the grid.
"""


class Solution(object):
    def minDays(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        cnt = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]:
                    cnt += 1
                    root = (i, j)
        if cnt <= 1:
            return cnt
        vis, low, time, ans = {root}, {}, {}, []

        def articulation_points(curr, parent):
            low[curr] = time[curr] = len(vis)
            children = 0
            i, j = curr
            for x, y in [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]:
                if (x, y) == parent:
                    continue
                if 0 <= x < len(grid) and 0 <= y < len(grid[0]) and grid[x][y]:
                    if (x, y) not in vis:
                        vis.add((x, y))
                        articulation_points((x, y), curr)
                        low[curr] = min(low[curr], low[(x, y)])
                        children += 1
                        if low[(x, y)] >= time[(curr)] and parent != (-1, -1):
                            ans.append([i, j])
                    else:
                        low[curr] = min(low[curr], time[(x, y)])

                if parent == (-1, -1) and children > 1:
                    ans.append([x, y])

        articulation_points(root, (-1, -1))
        if len(vis) != cnt:
            return 0
        elif ans:
            return 1
        else:
            return 2


if __name__ == "__main__":
    obj = Solution()
    print(obj.minDays(grid=[[0, 1, 1, 0], [0, 1, 1, 0], [0, 0, 0, 0]]))
    print(obj.minDays(grid=[[1, 1]]))
