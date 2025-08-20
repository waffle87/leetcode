# 1277. Count Square Submatrices with All Ones

"""
given an 'm * n' matrix of ones and zeros, return how many square submatrices
have all ones.
"""


class Solution(object):
    def countSquares(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                matrix[i][j] += (
                    min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]) + 1
                )
        return sum(map(sum, matrix))


if __name__ == "__main__":
    obj = Solution()
    print(obj.countSquares(matrix=[[0, 1, 1, 1], [1, 1, 1, 1], [0, 1, 1, 1]]))
    print(obj.countSquares(matrix=[[1, 0, 1], [1, 1, 0], [1, 1, 0]]))
