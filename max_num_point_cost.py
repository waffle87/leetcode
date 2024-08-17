# 1937. Maximum Number of Points with Cost

"""
you are given an 'm * n' integer matrix 'points' (0 indexed). starting with 0
points you want to maximise the numbber of points you can get from the
matrix. to gain points, you must pick one cell in each row. picking the cell
at coordinates '(r, c)' will add 'points[r][c]' to your score. however, you
will lose points if you pick a cell too far from the cell that you picked in
the previous row. for every two adjacent rows 'r' and 'r + 1', picking cells
at coordinates '(r, c_1)' and '(r + 1, c_2)' will subtract 'abs(c_1 - c_2)'
from your score. return the maximum number of points you can achieve
"""


class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        m, n = len(points), len(points[0])
        if m == 1:
            return max(points[0])
        if n == 1:
            return sum(sum(x) for x in points)

        def left(arr):
            left = [arr[0]] + [0] * (n - 1)
            for i in range(1, n):
                left[i] = max(left[i - 1] - 1, arr[i])
            return left

        def right(arr):
            right = [0] * (n - 1) + [arr[-1]]
            for i in range(n - 2, -1, -1):
                right[i] = max(right[i + 1] - 1, arr[i])
            return right

        pre = points[0]
        for i in range(m - 1):
            left, right, curr = left(pre), right(pre), [0] * n
            for j in range(n):
                curr[j] = points[i + 1][j] + max(left[j], right[j])
            pre = curr[:]

        return max(pre)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxPoints(points=[[1, 2, 3], [1, 5, 1], [3, 1, 1]]))
    print(obj.maxPoints(points=[[1, 5], [2, 3], [4, 2]]))
