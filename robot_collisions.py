# 2751. Robot Collisions
from typing import List

"""
there are 'n' 1 idxexed robots, each having a position on a line, health, and
movement directions. all robots start moving on the line simultaneously at
the same speed in their given directions. if two robots ever share the same
position while moving, they will collide. if two robots collide, the robot
with lower health is removed from the line and the health of the other robot
decreases by 1. the surviving robot continues in the same direction it was
going. if both robots have the same health they are both removed from the
line. return an array containing the health of the remaining robots after no
further collisions can occur
"""


class Solution:
    def survivedRobotsHealths(
        self, positions: List[int], healths: List[int], directions: str
    ) -> List[int]:
        n = len(positions)
        robots = [[positions[i], healths[i], directions[i], i] for i in range(n)]
        robots.sort()
        stack = []
        for robot in robots:
            if robot[2] == "R" or not stack or stack[-1][2] == "L":
                stack.append(robot)
                continue
            if robot[2] == "L":
                add = True
                while stack and stack[-1][2] == "R" and add:
                    last_health = stack[-1][1]
                    if robot[1] > last_health:
                        stack.pop()
                        robot[1] -= 1
                    elif robot[1] < last_health:
                        stack[-1][1] -= 1
                        add = False
                    else:
                        stack.pop()
                        add = False
                if add:
                    stack.append(robot)

        return [robot[1] for robot in sorted(stack, key=lambda robot: robot[3])]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.survivedRobotsHealths(
            positions=[5, 4, 3, 2, 1], healths=[2, 17, 9, 15, 10], directions="RRRRR"
        )
    )
    print(
        obj.survivedRobotsHealths(
            positions=[3, 5, 2, 6], healths=[10, 10, 15, 12], directions="RLRL"
        )
    )
    print(
        obj.survivedRobotsHealths(
            positions=[1, 2, 5, 6], healths=[10, 10, 11, 11], directions="RLRL"
        )
    )
