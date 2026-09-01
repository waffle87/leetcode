# 3568. Minimum Moves to Clean the Classroom
from collections import deque

"""
you are given an 'm x n' grid 'classroom' where a student volunteer is taked
with cleaning up litter scattered around the room. each cell in the grid is
one of the following: 'S': starting position, 'L': litter that must be
collected, 'R': reset area that restores the student's energy to full, 'X':
obstacle that the student cannot pass through, and '.': empty space. you are
also given an integer 'energy' representing the student's maximum energy
capacity. the student starts with this energy from the starting position 'S'.
each move to an adjacent cell costs 1 unit of energy. return the minimum
number of moves requiresto collect all litter items, or -1 if it is
impossible.
"""


class Solution:
    def minMoves(self, classroom: List[str], energy: int) -> int:
        m = len(classroom)
        n = len(classroom[0])
        dp = [[-1] * n for _ in range(m)]
        k, sr, sc = 0, 0, 0
        for r in range(m):
            for c in range(n):
                if classroom[r][c] == "S":
                    sr = r
                    sc = c
                elif classroom[r][c] == "L":
                    dp[r][c] = k
                    k += 1
        if k == 0:
            return 0
        total_mask = (1 << k) - 1
        best = [[[-1] * (1 << k) for _ in range(n)] for _ in range(m)]
        queue = deque()
        best[sr][sc][0] = energy
        queue.append((sr, sc, 0, energy, 0))
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        while queue:
            r, c, mask, e, moves = queue.popleft()
            for dr, dc in dirs:
                nr = r + dr
                nc = c + dc
                if nr < 0 or nr >= m or nc < 0 or nc >= n:
                    continue
                if classroom[nr][nc] == "X":
                    continue
                ne = e - 1
                if ne < 0:
                    continue
                nm = mask
                if classroom[nr][nc] == "R":
                    ne = energy
                if classroom[nr][nc] == "L":
                    nm |= 1 << dp[nr][nc]
                if nm == total_mask:
                    return moves + 1
                if ne <= best[nr][nc][nm]:
                    continue
                best[nr][nc][nm] = ne
                queue.append((nr, nc, nm, ne, moves + 1))
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.minMoves(classroom=["S.", "XL"], energy=2))
    print(obj.minMoves(classroom=["LS", "RL"], energy=4))
    print(obj.minMoves(classroom=["L.S", "RXL"], energy=3))
