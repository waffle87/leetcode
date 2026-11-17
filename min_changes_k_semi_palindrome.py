# 2911. Minimum Changes to Make K Semi-palindromes

from functools import cache
from operator import ne


class Solution:
    def minimumChanges(self, s: str, k: int) -> int:
        n = len(s)
        divisors = [[] for _ in range(n + 1)]
        for d in range(1, n):
            for length in range(2 * d, n + 1, d):
                divisors[length].append(d)

        @cache
        def peel(i, j, d):
            if j - i <= d:
                return 0
            return sum(map(ne, s[i : i + d], s[j - d : j])) + peel(i + d, j - d, d)

        @cache
        def cost(i, j):
            return min(peel(i, j, d) for d in divisors[j - i])

        best = {0: 0}
        for pieces in range(1, k):
            room = range(2 * pieces, n - 2 * (k - pieces) + 1)
            best = {
                j: min(best[i] + cost(i, j) for i in best if i <= j - 2) for j in room
            }
        return min(best[i] + cost(i, n) for i in best)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumChanges(s="abcac", k=2))
    print(obj.minimumChanges(s="abcdef", k=2))
    print(obj.minimumChanges(s="aabbaa", k=3))
