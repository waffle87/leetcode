# 1380. Lucky Numbers in a Matrix

"""
given an 'm  n' matrix of distinct numbers, return all lucky numbers in the
matrix in any order. a lucky number is an element of the matrix such that it
is the minimum element in its row and maximum in its column
"""


class Solution(object):
    def luckyNumbers(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        return list({min(row) for row in matrix} & {max(col) for col in zip(*matrix)})


if __name__ == "__main__":
    obj = Solution()
    print(obj.luckyNumbers(matrix=[[3, 7, 8], [9, 11, 13], [15, 16, 17]]))
    print(obj.luckyNumbers(matrix=[[1, 10, 4, 2], [9, 3, 8, 7], [15, 16, 17, 12]]))
    print(obj.luckyNumbers(matrix=[[7, 8], [1, 2]]))
