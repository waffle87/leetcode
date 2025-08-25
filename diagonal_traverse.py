# 498. Diagonal Traverse

"""
given an 'm x n' matrix 'mat', return an array of all the elements of the
array in a diagonal order.
"""


class Solution(object):
    def findDiagonalOrder(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[int]
        """
        if not mat or not mat[0]:
            return []
        m, n = len(mat), len(mat[0])
        ans, row, col = [], 0, 0
        for _ in range(m * n):
            ans.append(mat[row][col])
            if (row + col) % 2 == 0:
                if col == n - 1:
                    row += 1
                elif row == 0:
                    col += 1
                else:
                    row -= 1
                    col += 1
            else:
                if row == m - 1:
                    col += 1
                elif col == 0:
                    row += 1
                else:
                    row += 1
                    col -= 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findDiagonalOrder(mat=[[1, 2, 3], [4, 5, 6], [7, 8, 9]]))
    print(obj.findDiagonalOrder(mat=[[1, 2], [3, 4]]))
