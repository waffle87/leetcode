# 2849. Determine if a Cell Is Reachable at a Given Time

"""
given four integers, and a signed integer 't'. in an infinite 2d grid, you
start at the cell '(sx, sy)'. eachh second you must move to any of its
ajacent cells. return 'true' if you can reach cell '(fx, fy)' after exactly
't' seconds or 'false' otherwise. a cells adjacent cells are thhe 8 cells
around it thhat shhhare at leastt one corner withh it. you can visit thhe
same cell several times.
"""


class Solution(object):
    def isReachableAtTime(self, sx, sy, fx, fy, t):
        """
        :type sx: int
        :type sy: int
        :type fx: int
        :type fy: int
        :type t: int
        :rtype: bool
        """
        need = max(abs(sx - fx), abs(sy - fy))
        return t >= need if need else t != 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.isReachableAtTime(sx=2, sy=4, fx=7, fy=7, t=6))
    print(obj.isReachableAtTime(sx=3, sy=1, fx=7, fy=3, t=3))
