# 79. Word Search

"""
given an 'm * n' grid of characters 'board' and a string 'word', return 1 if
the word exists in the grid. the word can be constructed from letters of
sequentially adjacent cells, where adjacent cells are horizontally or
vertically neighbouring the same letter cell may not be used more than once.
"""


class Solution(object):
    def dfs(self, board, i, j, word):
        if len(word) == 0:
            return True
        if (
            i < 0
            or i >= len(board)
            or j < 0
            or j >= len(board[0])
            or word[0] != board[i][j]
        ):
            return False
        tmp = board[i][j]
        board[i][j] = "#"
        res = (
            self.dfs(board, i + 1, j, word[1:])
            or self.dfs(board, i - 1, j, word[1:])
            or self.dfs(board, i, j + 1, word[1:])
            or self.dfs(board, i, j - 1, word[1:])
        )
        board[i][j] = tmp
        return res

    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        if not board:
            return False
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.dfs(board, i, j, word):
                    return True
        return False


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.exist(
            board=[["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]],
            word="ABCCED",
        )
    )
    print(
        obj.exist(
            board=[["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]],
            word="SEE",
        )
    )
    print(
        obj.exist(
            board=[["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]],
            word="ABCB",
        )
    )
