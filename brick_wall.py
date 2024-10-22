# 554. Brick Wall

"""
there is a rectangular brick wall in front of you with 'n' rows of bricks.
the i'throw has some number of bricks each of the same height (ie. one unit)
butthey can be of different widths. the total width of each row is the same.
draw a vertical line from the top to the bottom and cross the least bricks.
if your line goes through the edge of a brick, then the brick is not
considered as crossed. you cannot draw a line just along one of the two
vertical edges of the wall, in which case the line will obviously cross no
bricks. given the 2d array 'wall' that contains the information about the
wall, return the minimum number of cross bricks after drawing such a vertical
line
"""


class Solution(object):
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        edge_freq = {}
        max_freq = 0
        for row in range(len(wall)):
            edge_pos = 0
            for brick_num in range(len(wall[row]) - 1):
                curr = wall[row][brick_num]
                edge_pos += curr
                edge_freq[edge_pos] = edge_freq.get(edge_pos, 0) + 1
                max_freq = max(edge_freq[edge_pos], max_freq)
        return len(wall) - max_freq


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.leastBricks(
            wall=[[1, 2, 2, 1], [3, 1, 2], [1, 3, 2], [2, 4], [3, 1, 2], [1, 3, 1, 1]]
        )
    )
    print(obj.leastBricks(wall=[[1], [1], [1]]))
