# 1301. Number of Paths with Max Score

"""
you are given a square 'board' of characters. you can move on the board
starting at the bottom right sqaure marked with the character 'S'. you need
to reach the top left square marked with the character 'E'. the rest of the
squares are labeled either with a numeric character '1, 2, ..., 9' or with an
obstacle 'X'. in one move you can go up, left, or up-left (diagonally) only
if there is no obstacle there. return a list of two integers: the first
integer is the maximum sum of numeric characters you can collect and the
second is the number of such paths that youcan take to get that maximum sum,
modulo 10^9 + 7.
"""


class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        mod, n = 10**9 + 7, len(board)
        score = [-1] * (n + 1)
        ways = [0] * (n + 1)
        for r in range(n - 1, -1, -1):
            new_score = [-1] * (n + 1)
            new_ways = [0] * (n + 1)
            for c in range(n - 1, -1, -1):
                if board[r][c] == "X":
                    continue
                if board[r][c] == "S":
                    new_score[c] = 0
                    new_ways[c] = 1
                    continue
                best = max(score[c], new_score[c + 1], score[c + 1])
                if best == -1:
                    continue
                cnt = 0
                if score[c] == best:
                    cnt += ways[c]
                if new_score[c + 1] == best:
                    cnt += new_ways[c + 1]
                if score[c + 1] == best:
                    cnt += ways[c + 1]
                val = 0 if board[r][c] == "E" else int(board[r][c])
                new_score[c] = best + val
                new_ways[c] = cnt % mod
            score = new_score
            ways = new_ways
        if score[0] == -1:
            return [0, 0]
        return [score[0], ways[0]]


if __name__ == "__main__":
    obj = Solution()
    print(obj.pathsWithMaxScore(board=["E23", "2X2", "12S"]))
    print(obj.pathsWithMaxScore(board=["E12", "1X1", "21S"]))
    print(obj.pathsWithMaxScore(board=["E11", "XXX", "11S"]))
