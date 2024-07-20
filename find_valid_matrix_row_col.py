# 1605. Find Valid Matrix Given Row and Column Sums

"""
given two arrays 'rowSum' and 'colSum' of non negative integers where
'rowSum[i]' is the sum of the elements in the i'th row and 'colSum[i]' is the
sum of the elemtns in the i'th row and 'colSum[j]' is the sum of the elemtns
of the j'th column of a 2d matrix. in other words, you do not know the
elements of the matrix, but you do know the sumes of each row and column.
"""


class Solution(object):
    def restoreMatrix(self, rowSum, colSum):
        """
        :type rowSum: List[int]
        :type colSum: List[int]
        :rtype: List[List[int]]
        """
        m, n = len(rowSum), len(colSum)
        ans = [[0] * n for i in range(m)]
        for i in range(m):
            for j in range(n):
                ans[i][j] = min(rowSum[i], colSum[j])
                rowSum[i] -= ans[i][j]
                colSum[j] -= ans[i][j]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.restoreMatrix(rowSum=[3, 8], colSum=[4, 7]))
    print(obj.restoreMatrix(rowSum=[5, 7, 10], colSum=[8, 6, 8]))
