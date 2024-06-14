# 867. Transpose Matrix

"""
given a 2d integer array 'matrix', return the transpose of 'matrix'. the
transpose of a matrix is the matrix flipped over its main diagonal switching
the matrix's rows and column indices
"""


class Solution(object):
    def transpose(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(matrix)
        m = len(matrix[0])
        ans = [[0] * n for _ in range(m)]
        for i in range(n):
            for j in range(m):
                ans[j][i] = matrix[i][j]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.transpose(matrix=[[1, 2, 3], [4, 5, 6], [7, 8, 9]]))
    print(obj.transpose(matrix=[[1, 2, 3], [4, 5, 6]]))
