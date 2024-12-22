# 1349. Maximum Students Taking Exam

"""
given an 'm x n' matrix 'seats' that represent seats distributions in a
classroom. if a seat is broken, it is denoted by '#' character otherwise it
is denoted by a '.' character. students can see theanswers of those sitting
next to the left, right, upper left, and upper right, but cannot see the
answers of the student sitting directly in front of or behind them. return
the maximum number of students that can take the exam together without any
cheating being possible. students must be placed in seats in good condition.
"""


class Solution(object):
    def maxStudents(self, seats):
        """
        :type seats: List[List[str]]
        :rtype: int
        """
        n, m = len(seats), len(seats[0])
        match = [[-1] * m for _ in range(n)]

        def dfs(node, seen):
            r, c = node
            for nr, nc in [
                [r - 1, c - 1],
                [r, c - 1],
                [r, c + 1],
                [r - 1, c + 1],
                [r + 1, c - 1],
                [r + 1, c + 1],
            ]:
                if (
                    0 <= nr < n
                    and 0 <= nc < m
                    and not seen[nr][nc]
                    and seats[nr][nc] == "."
                ):
                    seen[nr][nc] = True
                    if match[nr][nc] == -1 or dfs(match[nr][nc], seen):
                        match[nr][nc] = (r, c)
                        return True
            return False

        def hungarian():
            res = 0
            for c in range(0, m, 2):
                for r in range(n):
                    if seats[r][c] == ".":
                        seen = [[False] * m for _ in range(n)]
                        if dfs((r, c), seen):
                            res += 1
            return res

        ans, cnt = hungarian(), 0
        for r in range(n):
            for c in range(m):
                if seats[r][c] == ".":
                    cnt += 1
        return cnt - ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxStudents(
            seats=[
                ["#", ".", "#", "#", ".", "#"],
                [".", "#", "#", "#", "#", "."],
                ["#", ".", "#", "#", ".", "#"],
            ]
        )
    )
    print(
        obj.maxStudents(
            seats=[[".", "#"], ["#", "#"], ["#", "."], ["#", "#"], [".", "#"]]
        )
    )
    print(
        obj.maxStudents(
            seats=[
                ["#", ".", ".", ".", "#"],
                [".", "#", ".", "#", "."],
                [".", ".", "#", ".", "."],
                [".", "#", ".", "#", "."],
                ["#", ".", ".", ".", "#"],
            ]
        )
    )
