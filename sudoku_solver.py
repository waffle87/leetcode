# 37. Sudoku Solver

"""
write a program to solve a sudoku puzzle by filling the empty cells. a sudoku
solution must satisfy all of the following rules. each of the digits '1-9'
must occur exactly once in each row, each of the digits '1-9', must occur
exactly once in each column, and each of the digits '1-9' must occur exactly
once in each of the 9 3x3 sub-boxes of the grid. the '.' character indicates
empty cells.
"""


class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        n = 9

        def valid(row, col, idx):
            row, col = int(row), int(col)
            for i in range(9):
                if board[i][col] == idx:
                    return False
                if board[row][i] == idx:
                    return False
                if board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == idx:
                    return False
            return True

        def solve(row, col):
            if row == n:
                return True
            if col == n:
                return solve(row + 1, 0)
            if board[row][col] == ".":
                for i in range(1, 10):
                    if valid(row, col, str(i)):
                        board[row][col] = str(i)
                        if solve(row, col + 1):
                            return True
                        else:
                            board[row][col] = "."
                return False
            else:
                return solve(row, col + 1)

        solve(0, 0)


if __name__ == "__main__":
    obj = Solution()
    board = [
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
    obj.solveSudoku(board)
    print(board)
