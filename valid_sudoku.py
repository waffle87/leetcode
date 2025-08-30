# 36. Valid Sudoku

"""
determine if a 9 x 9 sudoku board is valid. only the filled cells need to be
validated acording to the following rules. each row must contain the digits
1-9 without repetition, each column must contain the digits 1-9 without
reptition, each of the nine 3 x 3 sub-boxes of the grid must contain the
digits 1-9 without reptition. note, a sudoku board (partially filled) could
be valid but it is not necessarily solvable. only the filled cells need to be
validated according to the mentioned rules.
"""


class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        rows = [[False] * 9 for _ in range(9)]
        cols = [[False] * 9 for _ in range(9)]
        boxes = [[False] * 9 for _ in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j] != ".":
                    num = ord(board[i][j] - ord("1"))
                    box_idx = (i // 3) * 3 + (j // 3)
                    if rows[i][num] or cols[j][num] or boxes[box_idx][num]:
                        return False
                    rows[i][num] = cols[j][num] = boxes[box_idx][num] = True
        return True


if __name__ == "__main__":
    obj = Solution()
    b1 = [
        ["5", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"],
    ]
    b2 = [
        ["8", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"],
    ]
    print(obj.isValidSudoku(b1))
    print(obj.isValidSudoku(b2))
