# 1074. Number of Submatrices That Sum to Target
from collections import defaultdict

"""
given a 'matrix' and 'target', return the number of non-empty submatrices
that sum to target. a submatrix 'x1, y1 x2, y2' is the set of all cells
'matrix[x][y]' with 'x1 <= x <= x2' and 'y1 <= y <= y2'. two submatrices are
different if they have some coordinate that is different. for example if x1
!= x1
"""


class Solution(object):
    def numSubmatrixSumTarget(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: int
        """
        m, n = len(matrix), len(matrix[0])
        for row in matrix:
            for i in range(n - 1):
                row[i + 1] += row[i]
        ans = 0
        for i in range(n):
            for j in range(i, n):
                c = collections.defaultdict(int)
                curr, c[0] = 0, 1
                for k in range(m):
                    curr += matrix[k][j] - (matrix[k][i - 1] if i > 0 else 0)
                    ans += c[curr - target]
                    c[curr] += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.numSubmatrixSumTarget(matrix=[[0, 1, 0], [1, 1, 1], [0, 1, 0]], target=0))
    print(obj.numSubmatrixSumTarget(matrix=[[1, -1], [-1, 1]], target=0))
    print(obj.numSubmatrixSumTarget(matrix=[[904]], target=0))
