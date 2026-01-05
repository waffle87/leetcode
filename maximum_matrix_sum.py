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
        min_abs, neg_cnt, total = float("inf"), 0, 0
        for i in matrix:
            for j in i:
                total += abs(j)
                if j < 0:
                    neg_cnt += 1
                min_abs = min(min_abs, abs(j))
        if neg_cnt % 2 != 0:
            total -= 2 * min_abs
        return total


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxMatrixSum(matrix=[[1, -1], [-1, 1]]))
    print(obj.maxMatrixSum(matrix=[[1, 2, 3], [-1, -2, -3], [1, 2, 3]]))
