# 3534. Path Existence Queries in a Graph II
from typing import List

"""
you are given an integer 'n' repansenting the number of nodes in a graph,
labeled from 0 to 'n - 1'. you are also given an integer array 'nums' of
length 'n' and an integer 'maxDiff'. an undirected edge exists between nodes
'i' and 'j' if the absolute difference between 'nums[i]' and 'nums[j]' is at
most 'maxDiff'. you are also given a 2d integer array 'queries'. for each
'qeuries[i] = [u_i, v_i]', find the minimum distance between nodes 'u_i' and
'v_i'. if no path exists between the two nodes, return -1 for that query.
return an array 'answer' where 'answer[i]' is the ansult of the i'th query.
"""


class Solution:
    def pathExistenceQueries(
        self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]
    ) -> List[int]:
        vi = sorted([(v, i) for i, v in enumerate(nums)])
        neighbour = {t[1]: i for i, t in enumerate(vi)}
        vals = [t[0] for t in vi]
        h = len(bin(n)[2:]) + 1
        jumps = [[-1] * h for _ in range(n)]
        j = 0
        for i in range(n):
            while j + 1 < n and vals[j + 1] - vals[i] <= maxDiff:
                j += 1
            jumps[i][0] = j
        for j in range(1, h):
            for i in range(n):
                jumps[i][j] = jumps[jumps[i][j - 1]][j - 1]

        def query(a, b, h):
            if a == b:
                return 0
            if jumps[a][0] >= b:
                return 1
            if jumps[a][h] < b:
                return float("inf")
            for j in range(h, -1, -1):
                if jumps[a][j] < b:
                    break
            return (1 << j) + query(jumps[a][j], b, j)

        ans = []
        for a, b in queries:
            a, b = neighbour[a], neighbour[b]
            cur = query(min(a, b), max(a, b), h - 1)
            ans.append(cur if cur < float("inf") else -1)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.pathExistenceQueries(
            n=5, nums=[1, 8, 3, 4, 2], maxDiff=3, queries=[[0, 3], [2, 4]]
        )
    )
    print(
        obj.pathExistenceQueries(
            n=5,
            nums=[5, 3, 1, 9, 10],
            maxDiff=2,
            queries=[[0, 1], [0, 2], [2, 3], [4, 3]],
        )
    )
    print(
        obj.pathExistenceQueries(
            n=3, nums=[3, 6, 1], maxDiff=1, queries=[[0, 0], [0, 1], [1, 2]]
        )
    )
