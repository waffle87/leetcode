# 2133. Check if Every Row and Column Contains All Numbers

"""
an 'n x n' matrix is valid if every row and every column contains all the
integers from 1 to 'n'. given an 'n x n' matrix, return true if the matrix is
valid, otherwise return false.
"""


class Solution(object):
    def checkValid(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        n = len(matrix)
        for i in range(n):
            row, col, mask = 1, 1, 1
            for j in range(n):
                row ^= 1 << matrix[i][j]
                col ^= 1 << matrix[j][i]
                mask |= 1 << j + 1
            if row ^ mask or col ^ mask:
                return False
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.checkValid(matrix=[[1, 2, 3], [3, 1, 2], [2, 3, 1]]))
    print(obj.checkValid(matrix=[[1, 1, 1], [1, 2, 3], [1, 2, 3]]))
