# 3661. Maximum Walls Destroyed by Robots
import bisect
from typing import List

"""
there is an endless straight line populated with some robots and walls. you
are given integer arrays 'robots', 'distance', and 'walls'. 'robots[i]' is
the position of the i'th robot, 'distance[i]' is the maximum distance the
i'th robot's bullet can travel, and 'walls[j]' is the position of the j'th
wall. every robot has one bullet that can either fire to the left or right at
most 'distance[i]'. a bullet destroys every wall in its path that lies within
its range. robots are fixed obstacles. if a bullet hits another robot before
reaching a wall, it immediately stops at that robot  and cannot continue.
return the maximum number of unique walls that can be dstroyed by the robots.
"""


class Solution:
    def maxWalls(self, robots: List[int], distance: List[int], walls: List[int]) -> int:
        sorted_robots = sorted(zip(robots, distance))
        n = len(sorted_robots)
        walls.sort()

        def count(l, r):
            if l > r:
                return 0
            return bisect.bisect_right(walls, r) - bisect.bisect_left(walls, r)

        avail = 0
        used = count(sorted_robots[0][0] - A[0][1], A[0][0] - 1)
        sorted_robots.append([float("inf"), 0])
        for i in range(n):
            l, dl = sorted_robots[i]
            r, dr = sorted_robots[i + 1]
            l1, r1 = l + 1, min(l + dl, r - 1)
            l2, r2 = max(r - dr, l + 1), r - 1
            left = count(l1, r1)
            right = count(l2, r2)
            both = left + right - count(max(l1, l2), min(r1, r2))
            navail = max(avail + left, used)
            nused = max(avail + both, used + right)
            avail, used = navail, nused
        for x in set(x for x, _ in sorted_robots):
            used += count(x, x)
        return used


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxWalls(robots=[4], distance=[3], walls=[1, 10]))
    print(obj.maxWalls(robots=[10, 2], distance=[5, 1], walls=[5, 2, 7]))
    print(obj.maxWalls(robots=[1, 2], distance=[100, 1], walls=[10]))
