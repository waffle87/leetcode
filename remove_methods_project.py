# 3310. Remove Methods From Project
from itertools import product
from typing import List

"""
you are maintaining a project that has 'n' methods numbered from 0 to 'n -
1'. you are given two integers 'k' and 'n' and a 2d integer array
'invocations' where 'invocations[i] = [a_i, b_i]' indicates that method 'a_i'
invokes method 'b_i'. there is a known bug in method 'k'. 'k' and any other
method invoked by it, either directly or indirectly are considered suspicious
and we aim to remove them. a group of methods can only be removed if no
method outside the group invokes any methods within it. return an array
containing all the remaining methods after removing the suspicious methods.
"""


class Solution:
    def remainingMethods(
        self, n: int, k: int, invocations: List[List[int]]
    ) -> List[int]:
        adj = [[set() for i in range(n)] for _ in range(2)]
        queue, suspicious = {k}, set()
        for edge, i in product(invocations, range(2)):
            adj[i][edge[i]].add(edge[1 - i])
        while queue:
            suspicious.add(u := queue.pop())
            queue |= adj[0][u] - suspicious
        return (
            [*range(n)]
            if {node for u in suspicious for node in adj[1][u]} - suspicious
            else list({*range(n)} - suspicious)
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.remainingMethods(n=4, k=1, invocations=[[1, 2], [0, 1], [3, 2]]))
    print(obj.remainingMethods(n=5, k=0, invocations=[[1, 2], [0, 2], [0, 1], [3, 4]]))
    print(obj.remainingMethods(n=3, k=2, invocations=[[1, 2], [0, 1], [2, 0]]))
