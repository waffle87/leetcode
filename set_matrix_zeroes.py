# 73. Set Matrix Zeroes

"""
given an 'm x n' integer 'matrix', if an element is '0', set its entire row
and columns to '0's. you must do it in place
"""


class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        r, c = 0, 0
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == 0:
                    r |= 1 << i
                    c |= 1 << j
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if r & 1 << i or c & 1 << j:
                    matrix[i][j] = 0


if __name__ == "__main__":
    obj = Solution()
    m1 = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    m2 = matrix = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
    obj.setZeroes(m1)
    obj.setZeroes(m2)
    print(m1)
    print(m2)
