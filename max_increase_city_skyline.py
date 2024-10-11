# 807. Max Increase to Keep City Skyline

"""
there is a city composed of 'n * n' blocks where each block contains a single
building shaped like a vertical square prisum. you are given 0 idxed 'n * n'
integer matrix 'grid' where 'grid[r][c]' represents the height of the
building located in the block at row 'r' and column 'c'. a city's skiline is
the outer contour formed by all the building =hen viewing the side of the
city from a distance. the skyline from a distance. the skyline from each
cardinal direction, north, east, south, and west may be different. we are
allowed to increase the height of any number of buildings by any amount. the
height of a 0-height building can also be increased. however, increasing the
height of a building should not affect the city's skyline from any cardinal
direction. return the maximum total sum that the height of the buildings can
be increased by without changing the city's skyline from any cardinal
direction
"""


class Solution(object):
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        sum = 0
        l1 = [max(i) for i in zip(*grid)]
        l2 = [max(i) for i in grid]
        for i in range(len(grid)):
            for j in range(len(grid)):
                sum += min(l1[j], l2[i]) - grid[i][j]
        return sum


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxIncreaseKeepingSkyline(
            grid=[[3, 0, 8, 4], [2, 4, 5, 7], [9, 2, 6, 3], [0, 3, 1, 0]]
        )
    )
    print(obj.maxIncreaseKeepingSkyline(grid=[[0, 0, 0], [0, 0, 0], [0, 0, 0]]))
