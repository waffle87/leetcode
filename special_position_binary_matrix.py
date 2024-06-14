# 1582. Special Positions in a Binary Matrix

"""
given an 'm  n' binary matrix 'mat', return the number of special positions
in 'mat'. a position '(i, j)' is called special  if 'mat[i][j] == 1'  and all
other elements in a row and column are 0
"""


class Solution(object):
    def numSpecial(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """


if __name__ == "__main__":
    obj = Solution()
    print(obj.numSpecial(mat=[[1, 0, 0], [0, 0, 1], [1, 0, 0]]))  # expect: 1
    print(obj.numSpecial(mat=[[1, 0, 0], [0, 1, 0], [0, 0, 1]]))  # expect: 3
