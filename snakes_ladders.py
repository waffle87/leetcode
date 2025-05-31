# 909. Snakes and Ladders

"""
you are given an 'n x n' integer matrix 'board' where the cells are all
labeled from 1 to 'n^2' in 'boustropheden style' starting from bottom left of
the board, and alternating direction each row. a board square on row 'r' and
column 'c' has a snake of a ladder if 'board[r][c] != -1'. the destination of
that snake or ladder is 'board[r][c]'. squares 1 and 'n^2' are not the
starting points of any snake or ladder. note that you only take a snake or a
ladder at most once per dice roll. if the destination to a snake or ladder is
the start of another snake or ladder, you do not follow the subsequent snake
or ladder.
"""


class Solution(object):
    def snakesAndLadders(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        n = len(board)

        def coordinates(num):
            row, col = (num - 1) // n, (num - 1) % n
            col = n - 1 if row % 2 == 1 else col
            row = n - 1 - row
            return row, col

        vis, queue = set(), [(1, 0)]
        vis.add(1)
        while queue:
            curr, moves = queue.pop(0)
            if curr == n**2:
                return moves
            for i in range(1, 7):
                next = curr + i
                if next > n**2:
                    continue
                row, col = coordinates(next)
                if board[row][col] != -1:
                    next = board[row][col]
                if next == n**2:
                    return moves + 1
                if next not in vis:
                    vis.add(next)
                    queue.append((next, moves + 1))
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.snakesAndLadders(
            board=[
                [-1, -1, -1, -1, -1, -1],
                [-1, -1, -1, -1, -1, -1],
                [-1, -1, -1, -1, -1, -1],
                [-1, 35, -1, -1, 13, -1],
                [-1, -1, -1, -1, -1, -1],
                [-1, 15, -1, -1, -1, -1],
            ]
        )
    )
    print(obj.snakesAndLadders(board=[[-1, -1], [-1, 3]]))
