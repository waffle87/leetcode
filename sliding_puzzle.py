# 773. Sliding Puzzle
from collections import deque

"""
on an empty 2 x 3 board there are five tiles labeled from 1 to 5 and an empty
square represented by 0. a move consists of choosing 0 and a 4-directionall
adjacent number and swapping it. the state of the board is solved if and only
if the board is '[[1,2,3],[4,5,0]]'. given the puzzle 'board', return the
least number of moves required so that the state of the board is solved. if
it is impossible for the state of the board to be solved, return -1
"""


class Solution(object):
    def slidingPuzzle(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        s = "".join(str(n) for r in board for n in r)
        dq, vis = deque(), {s}
        dq.append((s, s.index("0")))
        steps, height, width = 0, len(board), len(board[0])
        while dq:
            for _ in range(len(dq)):
                t, i = dq.popleft()
                if t == "123450":
                    return steps
                x, y = i // width, i % width
                for r, c in (x, y + 1), (x, y - 1), (x + 1, y), (x - 1, y):
                    if height > r >= 0 <= c < width:
                        ch = [n for n in t]
                        ch[i], ch[r * width + c] = ch[r * width + c], "0"
                        s = "".join(ch)
                        if s not in vis:
                            vis.add(s)
                            dq.append((s, r * width + c))
            steps += 1
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.slidingPuzzle(board=[[1, 2, 3], [4, 0, 5]]))
    print(obj.slidingPuzzle(board=[[1, 2, 3], [5, 4, 0]]))
    print(obj.slidingPuzzle(board=[[4, 1, 2], [5, 0, 3]]))
