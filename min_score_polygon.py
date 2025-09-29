# 1039. Minimum Score Triangulation of Polygon

"""
given a convex n-sided polygon where each vertex has an integer value. you
are given an integer array 'values' where 'values[i]' is the value of the
i'th vertex (ie. clockwise order). you will triangulate the polygon into 'n -
2' triangles. for each triangle, the value of that triangle is the product of
the values of its vertices and the total score of the triangulation is the
sum of these values over all 'n - 2' triangles in the triangulation. return
the smallest possible total score that you can achieve with some
triangulation of the polygon
"""


class Solution(object):
    def minScoreTriangulation(self, values):
        """
        :type values: List[int]
        :rtype: int
        """
        n = len(values)
        dp = [[0] * n for i in range(n)]
        for i in range(2, n):
            for j in range(n - i):
                k = j + i
                dp[j][k] = min(
                    dp[j][l] + dp[l][k] + values[j] * values[k] * values[l]
                    for l in range(j + 1, k)
                )
        return dp[0][n - 1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.minScoreTriangulation(values=[1, 2, 3]))
    print(obj.minScoreTriangulation(values=[3, 7, 4, 5]))
    print(obj.minScoreTriangulation(values=[1, 3, 1, 4, 1, 5]))
