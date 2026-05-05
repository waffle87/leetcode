# 2497. Maximum Star Sum of a Graph
from collections import defaultdict
from typing import List

"""
there is an undirected graph consisting of 'n' nodes numbered from 0 to 'n -
1'. you are given a 0-indexed integer array 'vals' of length 'n' where
'vals[i]' denotes the value of the i'th node. you are also given a 2d integer
array 'edges' where 'edges[i] = [ai, bi]' denotes that there exists an
undirected edge connecting nodes 'ai' and 'bi'. a star graph is a subgraph of
the given graph having a center node containing 0 or more neighbours. given
an integer 'k', return the maximum star sum of a star graph containing at
most 'k' edges.
"""


class Solution:
    def maxStarSum(self, vals: List[int], edges: List[List[int]], k: int) -> int:
        graph = defaultdict(set)
        for i, j in edges:
            if vals[i] > 0:
                graph[j].add(i)
            if vals[j] > 0:
                graph[i].add(j)
        stars = []
        for i, v in enumerate(vals):
            vv = [vals[j] for j in graph[i]]
            vv.sort(reverse=True)
            stars.append(v + sum(vv[0:k]))
        return max(stars)


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxStarSum(
            vals=[1, 2, 3, 4, 10, -10, -20],
            edges=[[0, 1], [1, 2], [1, 3], [3, 4], [3, 5], [3, 6]],
            k=2,
        )
    )
    print(obj.maxStarSum(vals=[-5], edges=[], k=0))
