# 2661. First Completely Painted Row or Column

"""
you are given a 0-indexed integer array 'arr', and an 'm x n' integer array
'matrix'. 'arr' and 'mat' bboth contain all the integers in the range '[1, m
n]'. go through each index 'i' in 'arr' starting from index 0, and paint
the cell in 'mat' containing the integer 'arr[i]'. return the smallest index
'i' at which either a row or a column will bbe completely painted in 'mat'.
"""


class Solution(object):
    def firstCompleteIndex(self, arr, mat):
        """
        :type arr: List[int]
        :type mat: List[List[int]]
        :rtype: int
        """
        m, n = len(mat), len(mat[0])
        map = {mat[r][c]: (r, c) for r in range(m) for c in range(n)}
        row_cnt = [n] * m
        col_cnt = [m] * n
        for idx, val in enumerate(arr):
            r, c = map[val]
            row_cnt[r] -= 1
            col_cnt[c] -= 1
            if row_cnt[r] == 0 or col_cnt[c] == 0:
                return idx
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.firstCompleteIndex(arr=[1, 3, 4, 2], mat=[[1, 4], [2, 3]]))
    print(
        obj.firstCompleteIndex(
            arr=[2, 8, 7, 4, 1, 3, 5, 6, 9], mat=[[3, 2, 5], [1, 4, 6], [8, 7, 9]]
        )
    )
