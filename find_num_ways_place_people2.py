# 3027. Find the Number of Ways to Place People II

"""
you are given a 2d array 'points' of size 'n x 2' representing integer
coordinates of some points on a 2d plane where 'points[i] = [x_i, y_i]'. we
define the right direction as positive x-axis and the left direction as
negative x-axis. similarly, up and down are postive and negative y-axis
accordingly. you have to place 'n' people including alice and bob at these
points such that there is exactly one person at every point. alice wants to
be alone with bob, so alice will build a rectangular fence with alice's
position as the upper left corner and bob's position as the lower right
corner
"""


class Solution(object):
    def numberOfPairs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        points.sort(key=lambda x: (-x[0], x[1]))
        ans, n = 0, len(points)
        for i in range(n - 1):
            y, yi = float("inf"), points[i][1]
            for j in range(i + 1, n):
                yj = points[j][1]
                if y > yj >= yi:
                    ans += 1
                    y = yj
                    if yi == yj:
                        break
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfPairs(points=[[1, 1], [2, 2], [3, 3]]))
    print(obj.numberOfPairs(points=[[6, 2], [4, 4], [2, 6]]))
    print(obj.numberOfPairs(points=[[3, 1], [1, 3], [1, 1]]))
