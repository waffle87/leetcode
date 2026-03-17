# 1727. Largest Submatrix With Rearrangements
from typing import List

"""
you are given a binary matrix of size 'm  n' and you are allowed to
rearrange the columns of the 'matrix' in any order. return the area of the
largest submatrix within 'matrix' where every element of the submatrix is 1
after reordering columns optimally
"""


class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        for i in range(1, m):
            for j in range(n):
                if matrix[i][j] == 1:
                    matrix[i][j] += matrix[i - 1][j]
        ans = 0
        for i in range(m):
            matrix[i].sort()
            for j in range(n):
                height = matrix[i][j]
                ans = max(ans, height * (n - j))
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.largestSubmatrix(matrix=[[0, 0, 1], [1, 1, 1], [1, 0, 1]]))
    print(obj.largestSubmatrix(matrix=[[1, 0, 1, 0, 1]]))
    print(obj.largestSubmatrix(matrix=[[1, 1, 0], [1, 0, 1]]))
