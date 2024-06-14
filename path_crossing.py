# 1496. Path Crossing

"""
given a string 'path' where 'path[i] = 'N, 'S', 'E', or 'W', each
representing moving one unit north, south, east, or west, respectively. you
start at the origin '(0, 0)' on a 2d plane and walk on the path specified by
'path'. return 'true' if the path crosses itself at any point, that is, if at
any time you are on a location you have previously visited. return 'false'
otherwise.
"""


class Solution(object):
    def isPathCrossing(self, path):
        """
        :type path: str
        :rtype: bool
        """
        moves = {"N": (0, 1), "S": (0, -1), "W": (-1, 0), "E": (1, 0)}
        vis = {(0, 0)}
        x = y = 0
        for i in path:
            dx, dy = moves[i]
            x += dx
            y += dy
            if (x, y) in vis:
                return True
            vis.add((x, y))
        return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.isPathCrossing("NES"))
    print(obj.isPathCrossing("NESWW"))
