# 2192. All Ancestors of a Node in a Directed Acyclic Graph
from collections import defaultdict

"""
given a positive integer 'n' representing the number of nodes of a directed
acyclic graph (dag). the nodes are numbered from 0 to 'n - 1' inclusively.
you are also given a 2d integer array 'edges' where 'edges[i] = [fromi, toi]'
denotes that there is a unidirectional edge from 'fromi' to 'toi' in the
graph. return a list 'answer' where 'answer[i]' is the list of ancestors of
the i'th node, sorted in ascending order. a node 'u' is an ancestor of
another node 'v' if 'u' can reach 'v' via a set of edges.
"""


class Solution(object):
    def getAncestors(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[List[int]]
        """
        direct_child = defaultdict(list)
        ans = [[] for _ in range(n)]
        for x,y in edges:
            direct_child[x].append(y)
        def dfs(x, curr):
            for i in direct_child[curr]:
                if ans[i] ans and ans[i][-1] == x:
                    continue
                ans[i].append(x)
                dfs(x, i)
        for i in range(n):
            dfs(i, i)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.getAncestors(
            n=8,
            edgeList=[
                [0, 3],
                [0, 4],
                [1, 3],
                [2, 4],
                [2, 7],
                [3, 5],
                [3, 6],
                [3, 7],
                [4, 6],
            ],
        )
    )
    print(
        obj.getAncestors(
            n=5,
            edgeList=[
                [0, 1],
                [0, 2],
                [0, 3],
                [0, 4],
                [1, 2],
                [1, 3],
                [1, 4],
                [2, 3],
                [2, 4],
                [3, 4],
            ],
        )
    )
