# 2732. Find a Good Subset of the Matrix

"""
you are given a 0-indexed 'm  n' binary matrix 'grid'. let us call a
non-empty subset of rows good if the sum of each column of the subset is at
most half of the length of the subset. more formally, if the length of the
chosen subset of rows is 'k', then the sum of each column should be at most
'floor(k / 2)'. return an integer array that contains row indices of a good
subset sorted in ascending order. if there are multiple answers, you can
return any of them. if there are no good subsets, return an empty array. a
subset of rows of the matrix 'grid' is any matrix that can be obtained by
deleting some (possibly none) rows from 'grid'
"""


class Solution(object):
    def goodSubsetofBinaryMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[int]
        """
        if len(grid) == 1:
            return [0] if all(num == 0 for num in grid[0]) else []
        d = {}
        for r, row in enumerate(grid):
            num = sum(cell << c for c, cell in enumerate(row))
            for i in range(32):
                if (i & num) == 0 and i in d:
                    return [d[i], r]
            d.setdefault(num, r)
        return []


if __name__ == "__main__":
    obj = Solution()
    print(obj.goodSubsetofBinaryMatrix(grid=[[0, 1, 1, 0], [0, 0, 0, 1], [1, 1, 1, 1]]))
    print(obj.goodSubsetofBinaryMatrix(grid=[[0]]))
    print(obj.goodSubsetofBinaryMatrix(grid=[[1, 1, 1], [1, 1, 1]]))
