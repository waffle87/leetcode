# 684. Redundant Connection

"""
in this problem, a tree is an undirected graph that is connected and has no
cycles. you are given a graph that started as a tree with 'n' nodes labeled
from 1 to 'n', with one additional edge added. the added edge has two
different vertices chosen from 1 to 'n', and was not an edge that already
existed. the graph is represented as an array 'edges' of length 'n' where
'edges[i] = [a_i, b_i]' indicates that there is an edge between nodes 'a_i'
and 'b_i' in the graph. return an edge that can removed so that the resulting
graph is a tree of 'n' nodes. if there are multiple answers, return the
answer that occurs last in the input.
"""


class Solution(object):
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        parent = [-1] * (len(edges) + 1)
        rank = [0] * (len(edges) + 1)

        def find(x):
            if parent[x] == -1:
                return x
            parent[x] = find(parent[x])
            return parent[x]

        def union_set(x, y):
            root_x, root_y = find(x), find(y)
            if root_x == root_y:
                return False
            elif rank[root_x] < rank[root_y]:
                parent[root_x] = root_y
                rank[root_y] += 1
                return True
            else:
                parent[root_y] = root_x
                rank[root_x] += 1
                return True

        for x, y in edges:
            if not union_set(x, y):
                return [x, y]


if __name__ == "__main__":
    obj = Solution()
    print(obj.findRedundantConnection(edges=[[1, 2], [1, 3], [2, 3]]))
    print(obj.findRedundantConnection(edges=[[1, 2], [2, 3], [3, 4], [1, 4], [1, 5]]))
