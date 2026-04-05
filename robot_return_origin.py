# 657. Robot Return to Origin

"""
there is a robot starting at the position '(0, 0)', the origin, on a 2d
plane. given a sequence of its move, judge if this robot ends up at '(0, 0)'
after it completes its moves. you are given a string 'moves' that represents
the move sequence of the robot where 'moves[i]' represents its i'th move.
valid moves are R, L, U, D. return trueif the robot returns to the origin
after it finishes all its moves, or false otherwise.
"""


class Solution:
    def judgeCircle(self, moves: str) -> bool:
        return moves.count("L") == moves.count("R") and moves.count("U") == moves.count(
            "D"
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.judgeCircle(moves="UD"))
    print(obj.judgeCircle(moves="LL"))
