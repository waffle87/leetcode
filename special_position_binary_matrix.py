# 1582. Special Positions in a Binary Matrix
from typing import List

"""
given an 'm  n' binary matrix 'mat', return the number of special positions
in 'mat'. a position '(i, j)' is called special  if 'mat[i][j] == 1'  and all
other elements in a row and column are 0
"""


class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        col_idx = [0] * len(mat)
        row_sum = [0] * len(mat)
        col_sum = [0] * len(mat[0])
        for r, row in enumerate(mat):
            for c, col in enumerate(mat[r]):
                if col:
                    row_sum[r] += 1
                    col_sum[c] += 1
                    col_idx[r] = c
        cnt = 0
        for i, j in enumerate(row_sum):
            if j == 1 and col_sum[col_idx[i]] == 1:
                cnt += 1
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.numSpecial(mat=[[1, 0, 0], [0, 0, 1], [1, 0, 0]]))
    print(obj.numSpecial(mat=[[1, 0, 0], [0, 1, 0], [0, 0, 1]]))
