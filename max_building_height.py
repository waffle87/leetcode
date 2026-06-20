# 1840. Maximum Building Height
from typing import List

"""
you want to build 'n' new buildings in a city. the new buildings will be
built in a line and are labeled from 1 to 'n'. however, there are city
restrictions on the heights of the new buildings: the height of each building
must be a non-negative integer, the height of the first building must be 0,
and the height difference between any two adjacent buildings cannot exceed 1.
additionally, there are city restrictions on the maximum height of specific
buildings. these restrictions are given as 2d integer array 'restrictions'
where 'restrictions[i] = [id, max_height]' indicates that building 'id' must
have a height less than or equal to 'max_height'. return the maximum possible
height of the tallest building.
"""


class Solution:
    def y_cap(self, x1, y1, x2, y2):
        return min(y2, y1 + abs(x2 - x1))

    def y_peak(self, x1, y1, x2, y2):
        return (y1 + y2 + x2 - x1) >> 1

    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        restrictions.append([1, 0])
        restrictions.sort()
        n = len(restrictions)
        for i in range(1, n):
            restrictions[i][1] = self.y_cap(*restrictions[i - 1], *restrictions[i])
        for i in range(n - 2, -1, -1):
            restrictions[i][1] = self.y_cap(*restrictions[i + 1], *restrictions[i])
        ans = 0
        for i in range(1, n):
            peak = self.y_peak(*restrictions[i - 1], *restrictions[i])
            ans = max(ans, peak)
        return max(ans, restrictions[-1][1] + n - restrictions[-1][0])


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxBuilding(n=5, restrictions=[[2, 1], [4, 1]]))
    print(obj.maxBuilding(n=6, restrictions=[]))
    print(obj.maxBuilding(n=10, restrictions=[[5, 3], [2, 5], [7, 4], [10, 3]]))
