# 2211. Count Collisions on a Road

"""
there are 'n' cars on an infinitely long road. the cars numbered from 0 to 'n
- 1' from left to right and each car is present at a unique point. you are
given a 0-indexed string 'directions' of length 'n'. 'directions[i]' can be
either 'L', 'R', or 'S' denoting whether the i'th car is moving towards the
left, right, or staying at its current point. each moving car has the same
speed. after a collision, the cars involved can no longer move and will stay
at the point where they collided. other than that, cars cannot change their
state or direction of motion.
"""


class Solution(object):
    def countCollisions(self, directions):
        """
        :type directions: str
        :rtype: int
        """
        return sum(i != "S" for i in directions.lstrip("L").rstrip("R"))


if __name__ == "__main__":
    obj = Solution()
    print(obj.countCollisions(directions="RLRSLL"))
    print(obj.countCollisions(directions="LLRR"))
