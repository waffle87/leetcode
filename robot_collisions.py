# 2751. Robot Collisions

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


class Solution(object):
    def survivedRobotsHealths(self, positions, healths, directions):
        """
        :type positions: List[int]
        :type healths: List[int]
        :type directions: str
        :rtype: List[int]
        """
        n = len(positions)
        idx = sorted(range(n), key=positions.__getitem__)
        stack = []
        for i in idx:
            if directions[i] == "R":
                stack.append(i)
                continue
            while stack and healths[i] > 0:
                if healths[stack[-1]] < healths[i]:
                    healths[stack.pop()] = 0
                    healths[i] -= 1
                elif healths[stack[-1]] > healths[i]:
                    healths[stack[-1]] -= 1
                    healths[i] = 0
                else:
                    healths[stack.pop()] = 0
                    healths[i] = 0
        return [v for v in healths if v > 0]


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
