# 85. Maximal Rectangle

"""
given a 'rows * cols' binary 'matrix' filled with 0's and 1's, find the
largest rectangle containing only 1's and return its area.
"""


class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if not matrix:
            return 0
        n, m = len(matrix), len(matrix[0])
        heights, ans = [0] * (m + 1), 0
        for i in matrix:
            for j in range(m):
                heights[j] = heights[j] + 1 if i[j] == "1" else 0
            stack = []
            for j in range(len(heights)):
                while stack and heights[j] < heights[stack[-1]]:
                    h = heights[stack.pop()]
                    w = j if not stack else j - stack[-1] - 1
                    ans = max(ans, h * w)
                stack.append(j)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maximalRectangle(
            matrix=[
                ["1", "0", "1", "0", "0"],
                ["1", "0", "1", "1", "1"],
                ["1", "1", "1", "1", "1"],
                ["1", "0", "0", "1", "0"],
            ]
        )
    )
    print(obj.maximalRectangle(matrix=[["0"]]))
    print(obj.maximalRectangle(matrix=[["1"]]))
