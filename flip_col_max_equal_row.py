# 1072. Flip Columns For Maximum Number of Equal Rows

"""
you are given an 'm x n' binary matrix 'matrix'. you choose any number of
columns in the matrix and flip every cell in that column (ie. change the
value of the cell from 0 to 1 or vice versa). return the maximum number of
rows that have all values equal after some number of flips.
"""


class Solution(object):
    def maxEqualRowsAfterFlips(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        cnt = {}
        for row in matrix:
            norm = tuple(cell if row[0] == 0 else 1 - cell for cell in row)
            if norm not in cnt:
                cnt[norm] = 0
            cnt[norm] += 1
        return max(cnt.values())


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxEqualRowsAfterFlips(matrix=[[0, 1], [1, 1]]))
    print(obj.maxEqualRowsAfterFlips(matrix=[[0, 1], [1, 0]]))
    print(obj.maxEqualRowsAfterFlips(matrix=[[0, 0, 0], [0, 0, 1], [1, 1, 0]]))
