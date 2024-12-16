# 782. Transform to Chessboard

"""
you are given an 'n  n' binary grid 'board'. in each move, you can swap any
two rows with each other, or any two columns with each other. return the
minimum number of rwos to transform the board intoa chessboard board. if the
task is impossible, return -1. a chessboard board is a board where no 0's and
no 1's are 4-directionally adjacent
"""


class Solution(object):
    def movesToChessboard(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        n = len(board)
        if any(
            board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]
            for i in range(n)
            for j in range(n)
        ):
            return -1
        if not n / 2 <= sum(board[0]) <= (n + 1) / 2:
            return -1
        if not n / 2 <= sum(board[i][0] for i in range(n)) <= (n + 1) / 2:
            return -1
        col = sum(board[0][i] == i % 2 for i in range(n))
        row = sum(board[i][0] == i % 2 for i in range(n))
        if n % 2:
            if col % 2:
                col = n - col
            if row % 2:
                row = n - row
        else:
            col = min(n - col, col)
            row = min(n - row, row)
        return (col + row) / 2


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.movesToChessboard(
            board=[[0, 1, 1, 0], [0, 1, 1, 0], [1, 0, 0, 1], [1, 0, 0, 1]]
        )
    )
    print(obj.movesToChessboard(board=[[0, 1], [1, 0]]))
    print(obj.movesToChessboard(board=[[1, 0], [1, 0]]))
