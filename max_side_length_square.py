# 1292. Maximum Side Length of a Square with Sum Less than or Equal to
# Threshold

"""
given a 'm x n' matrix 'mat' and an integer 'threshold', return the maximum
side-length of a square with a sum less than or equal to 'threshold' or
return 0 if there is no such square.
"""


class Solution(object):
    def maxSideLength(self, mat, threshold):
        """
        :type mat: List[List[int]]
        :type threshold: int
        :rtype: int
        """
        best = 0

        def a(i, j):
            return mat[i][j] if i >= 0 <= j else 0

        for i in range(len(mat)):
            for j in range(len(mat[0])):
                mat[i][j] += a(i - 1, j) + a(i, j - 1) - a(i - 1, j - 1)
                best += (
                    i >= best <= j
                    and a(i, j)
                    - a(i - best - 1, j)
                    - a(i, j - best - 1)
                    + a(i - best - 1, j - best - 1)
                    <= threshold
                )
        return best


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxSideLength(
            mat=[[1, 1, 3, 2, 4, 3, 2], [1, 1, 3, 2, 4, 3, 2], [1, 1, 3, 2, 4, 3, 2]],
            threshold=4,
        )
    )
    print(
        obj.maxSideLength(
            mat=[
                [2, 2, 2, 2, 2],
                [2, 2, 2, 2, 2],
                [2, 2, 2, 2, 2],
                [2, 2, 2, 2, 2],
                [2, 2, 2, 2, 2],
            ],
            threshold=1,
        )
    )
