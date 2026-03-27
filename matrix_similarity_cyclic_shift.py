# 2946. Matrix Similarity After Cyclic Shifts
from typing import List

"""
you are given an 'm x n' integer matrix 'mat' and an integer 'k'. the matrix
rows are 0-indexed. the following process happens 'k' times: even indexed
rows are cyclically shifted to the left. odd indexed rows are cyclically
shifted to the right. return true if the final modified matrix after 'k'
steps is identical to the original matrix and false otherwise.
"""


class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        m, n = len(mat), len(mat[0])
        k %= n
        for i in range(m):
            for j in range(n):
                if mat[i][j] != mat[i][(j + k) % n]:
                    return False
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.areSimilar(mat=[[1, 2, 3], [4, 5, 6], [7, 8, 9]], k=4))
    print(obj.areSimilar(mat=[[1, 2, 1, 2], [5, 5, 5, 5], [6, 3, 6, 3]], k=2))
    print(obj.areSimilar(mat=[[2, 2], [2, 2]], k=3))
