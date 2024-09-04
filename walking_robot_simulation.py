# 874. Walking Robot Simulation

"""
a robot on an infinite xy plane starts at point '(0, 0)' facing north. the
robot can receive a sequence of these three possible types of 'commands': -2
turn left 90 degree, -1 turn right 90 degrees, '1 <= k <= 9' move forward 'k'
units, one unit at a time. some of the grid squares are 'obstacles'. the i'th
obstacle is at grid point 'obstacles[i] = (xi, yi)'. if the robot runs into
an obstacle, then it will instead stay in its current location and move on to
the next command. return the maximum euclidean distance that the robot ever
gets from the origin squared.
"""


class Solution(object):
    def robotSim(self, commands, obstacles):
        """
        :type commands: List[int]
        :type obstacles: List[List[int]]
        :rtype: int
        """
        i, j, max_dist, dir = 0, 0, 0, 0
        move, obstacles = (
            [
                (0, 1),
                (-1, 0),
                (0, -1),
                (1, 0),
            ],
            set(map(tuple, obstacles)),
        )
        for c in commands:
            if c == -2:
                dir = (dir + 1) % 4
            elif c == -1:
                dir = (dir - 1) % 4
            else:
                x, y = move[dir]
                while c and (i + x, j + y) not in obstacles:
                    i += x
                    j += y
            max_dist = max(max_dist, i**2 + j**2)
        return max_dist


if __name__ == "__main__":
    obj = Solution()
    print(obj.robotSim(commands=[4, -1, 3], obstacles=[]))
    print(obj.robotSim(commands=[4, -1, 4, -2, 4], obstacles=[[2, 4]]))
    print(obj.robotSim(commands=[6, -1, -1, 6], obstacles=[]))
