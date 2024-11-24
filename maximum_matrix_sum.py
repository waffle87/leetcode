# 1975. Maximum Matrix Sum

"""
you are given an 'n x n' integer 'matrix'. you can do the following operation
any number of times: choose any two adjacent elements of 'matrix' and
multiply each of them by -1. two elements are considered adjacent if and only
if they share a border. your goal is to maximise the summation of the
matrix's elements. return maximum sum of the matrix's elements using the
afforementioned operation.
"""


class Solution(object):
    def maxMatrixSum(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        ans, mult, val = 0, 0, float("inf")
        for i in range(len(matrix)):
            for j in range(len(matrix)):
                ans += abs(matrix[i][j])
                val = min(val, abs(matrix[i][j]))
                if matrix[i][j] < 0:
                    mult ^= 1
        return ans - 2 * mult * val


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxMatrixSum(matrix=[[1, -1], [-1, 1]]))
    print(obj.maxMatrixSum(matrix=[[1, 2, 3], [-1, -2, -3], [1, 2, 3]]))
