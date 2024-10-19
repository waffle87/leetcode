# 3249. Count the Number of Good Nodes
from collections import defaultdict

"""
there is an undirected tree with 'n' nodes labeled from 0 to 'n - 1', and
rooted at node 0. you are given a 2d integer array 'edges' of length 'n - 1'
where 'edges[i] = [a_i, b_i]' indicates that there is an edge between nodes
'a_i' and 'b_i' in the tree. a node is good if all the subtrees rooted at is
children have the same size. return the number of good nodes in the given
tree. a subtree of 'treeName' is a tree consisting of a node in 'treeName'
and all of its descendants.
"""


class Solution(object):
    def countGoodNodes(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: int
        """
        n = len(edges) + 1
        graph = defaultdict(list)
        subtree_size = [0] * n

        def dfs(curr, parent):
            n = 1
            for i in graph[curr]:
                if i != parent:
                    n += dfs(i, curr)
            subtree_size[curr] = n
            return n

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        dfs(0, -1)
        ans = 0
        for i in range(n):
            flag, prev = True, -1
            for j in graph[i]:
                if subtree_size[j] < subtree_size[i]:
                    if prev == -1:
                        prev = subtree_size[j]
                    elif prev != subtree_size[j]:
                        flag = False
                        break
            if flag:
                ans += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countGoodNodes(edges=[[0, 1], [0, 2], [1, 3], [1, 4], [2, 5], [2, 6]]))
    print(
        obj.countGoodNodes(
            edges=[[0, 1], [1, 2], [2, 3], [3, 4], [0, 5], [1, 6], [2, 7], [3, 8]]
        )
    )
    print(
        obj.countGoodNodes(
            edges=[
                [0, 1],
                [1, 2],
                [1, 3],
                [1, 4],
                [0, 5],
                [5, 6],
                [6, 7],
                [7, 8],
                [0, 9],
                [9, 10],
                [9, 12],
                [10, 11],
            ]
        )
    )
