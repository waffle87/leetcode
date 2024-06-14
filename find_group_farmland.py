# 1992. Find All Groups of Farmland

"""
given a 0-indexed 'm  n' binary matrix 'land' where a 0 represents a hectare
of forested land and a 1 represents a hectare of farmland. to keep the land
organised, there are designated rectangular areas of hectares that consist
entirely of farmland. these rectangular areas are called groups. no two
groups are adjacent, meaning farmland in one group is not four directionally
adjacent to another farmland in another group. return a 2d array containing
the 4 length arrays described above for each group o farmland in 'land'.
"""


class Solution(object):
    def findFarmland(self, land):
        """
        :type land: List[List[int]]
        :rtype: List[List[int]]
        """

        def dfs(x, y):
            stack = [(x, y)]
            min_row, min_col = x, y
            max_row, max_col = x, y
            visited.add((x, y))
            while stack:
                cur_x, cur_y = stack.pop()
                for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    nx, ny = cur_x + dx, cur_y + dy
                    if (
                        0 <= nx < rows
                        and 0 <= ny < cols
                        and (nx, ny) not in visited
                        and land[nx][ny] == 1
                    ):
                        visited.add((nx, ny))
                        stack.append((nx, ny))
                        min_row = min(min_row, nx)
                        min_col = min(min_col, ny)
                        max_row = max(max_row, nx)
                        max_col = max(max_col, ny)
            return (min_row, min_col, max_row, max_col)

        rows, cols = len(land), len(land[0])
        visited = set()
        ans = []
        for i in range(rows):
            for j in range(cols):
                if land[i][j] == 1 and (i, j) not in visited:
                    min_row, min_col, max_row, max_col = dfs(i, j)
                    ans.append([min_row, min_col, max_row, max_col])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findFarmland(land=[[1, 0, 0], [0, 1, 1], [0, 1, 1]]))
    print(obj.findFarmland(land=[[1, 1], [1, 1]]))
    print(obj.findFarmland(land=[[0]]))
