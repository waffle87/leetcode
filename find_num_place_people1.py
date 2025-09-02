# 3025. Find the Number of Ways to Place People I

"""
you are given a 2d array 'points' of size 'n x 2' representing integer
coordinates of some points on a 2d plane, where 'points[i] = [x_i, y_i]'.
count the number of pairs of points '(a, b)' where 'a' is on the upper left
side of 'b' and there are no other points in the rectangle they make,
including the border. return the count.
"""


class Solution(object):
    def numberOfPairs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        points.sort(key=lambda x: (-x[0], x[1]))
        n, ans = len(points), 0
        for i in range(n - 1):
            y = float("inf")
            for j in range(i + 1, n):
                if y > points[j][1] >= points[i][1]:
                    ans += 1
                    y = points[j][1]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfPairs(points=[[1, 1], [2, 2], [3, 3]]))
    print(obj.numberOfPairs(points=[[6, 2], [4, 4], [2, 6]]))
    print(obj.numberOfPairs(points=[[3, 1], [1, 3], [1, 1]]))
