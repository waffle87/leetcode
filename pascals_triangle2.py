# 119. Pascal's Triangle II

"""
given an integer 'row_index', return the 'row_index'th row of the pascals
triangle. in pascals triangle, each number is the sum of the two numbers
directly above it as shown.
"""


class Solution(object):
    def getRow(self, row_index):
        row = [1]
        for _ in range(row_index):
            row = [x + y for x, y in zip([0] + row, row + [0])]
        return row


if __name__ == "__main__":
    obj = Solution()
    print(obj.getRow(3))
    print(obj.getRow(0))
    print(obj.getRow(1))
