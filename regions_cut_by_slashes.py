# 959. Regions Cut By Slashes

"""
an 'n * n' grid is composed of 1 * 1 squares where each 1 * 1 square consists
of a '/' or '\' or blank space ' '. these characters divide the square into
contiguous regions. given the grid 'grid' represented as a string array,
return the number of regions. note that backslash characters are escaped.
"""


class Solution(object):
    def regionsBySlashes(self, grid):
        """
        :type grid: List[str]
        :rtype: int
        """
        n = {}

        def find(x):
            n.setdefault(x, x)
            if x != n[x]:
                n[x] = find(n[x])
            return n[x]

        def union(x, y):
            n[find(x)] = find(y)

        for i in range(len(grid)):
            for j in range(len(grid)):
                if i:
                    union((i - 1, j, 2), (i, j, 0))
                if j:
                    union((i, j - 1, 1), (i, j, 3))
                if grid[i][j] != "/":
                    union((i, j, 0), (i, j, 1))
                    union((i, j, 2), (i, j, 3))
                if grid[i][j] != "\\":
                    union((i, j, 3), (i, j, 0))
                    union((i, j, 1), (i, j, 2))
        return len(set(map(find, n)))


if __name__ == "__main__":
    obj = Solution()
    print(obj.regionsBySlashes(grid=[" /", "/ "]))
    print(obj.regionsBySlashes(grid=[" /", "  "]))
    print(obj.regionsBySlashes(grid=["/\\", "\\/"]))
