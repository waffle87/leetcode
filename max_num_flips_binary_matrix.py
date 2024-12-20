# 1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix

"""
given an 'm x n' binary matrix 'mat'. in one step, you can choose one cell
and flip it and all the four neighbours of it if they exist (fip is changing
1 to 0, and 0 to 1). a pair ofcells are called neighbours if their share one
edge. return the minimum number of steps required to convert 'mat' to a zero
matrix or -1 if you cannot. a binary matrix isa matrix with all cells equal
to 0 or 1 only. a zero matrix is a matrix with all cells equal to 0.
"""


class Solution(object):
    def minFlips(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        m, n = len(mat), len(mat[0])
        start = sum(
            cell << i * n + j for i, row in enumerate(mat) for j, cell in enumerate(row)
        )
        stack, seen = [(start, 0)], {start: 0}
        while stack:
            curr, step = stack.pop()
            for i in range(m):
                for j in range(n):
                    next = curr
                    for r, c in (i, j), (i, j + 1), (i, j - 1), (i + 1, j), (i - 1, j):
                        if m > r >= 0 <= c < n:
                            next ^= 1 << r * n + c
                    if seen.get(next, float("inf")) > step + 1:
                        seen[next] = step + 1
                        stack.append((next, step + 1))
        return seen.get(0, -1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minFlips(mat=[[0, 0], [0, 1]]))
    print(obj.minFlips(mat=[[0]]))
    print(obj.minFlips(mat=[[1, 0, 0], [1, 0, 0]]))
