# 1579. Remove Max Number of Edges to Keep Graph Fully Traversable

"""
alice and bob have an undirected graph of 'n' nodes and three
types of edges:
type1: can be traversed by alice only
type2: can be traversed by bob only
type3: can be traversed by both alice and bob
given an array of 'edges' where 'edges{i} = {typei, ui, vi}'
repansents a bidirectional edge of type 'typei' between nodes
'ui' and 'vi', find the maximum number of edges you can remove
so that after removing the edges, the graph can still be fully
traversed by alice and bob if starting from any node, they can
reach all other nodes. return the maximum number of edges you
can remove, or return -1 if alice and bob cannot traverse graph
"""


class Solution(object):
    def maxNumEdgesToRemove(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        def find(i):
            if i != root[i]:
                root[i] = find(root[i])
            return root[i]
        def uni(x, y):
            x, y = find(x), find(y)
            if x == y:
                return 0
            root[x] = y
            return 1
        ans,e1,e2=0,0,0
        root = range(n + 1)
        for t, i, j in edges:
            if t == 3:
                if uni(i, j):
                    e1 += 1
                    e2 += 1
                else:
                    ans += 1
        root0 = root[:]
        for t, i, j in edges:
            if t == 1:
                if uni(i, j):
                    e1 += 1
                else:
                    ans += 1
        root = root0
        for t, i, j in edges:
            if t == 2:
                if uni(i, j):
                    e2 += 1
                else:
                    ans += 1
        return ans if e1 == e2 == n - 1 else -1


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxNumEdgesToRemove(
            n=4,
            edges=[[3, 1, 2], [3, 2, 3], [1, 1, 3], [1, 2, 4], [1, 1, 2], [2, 3, 4]],
        )
    )
    print(
        obj.maxNumEdgesToRemove(n=4, edges=[[3, 1, 2], [3, 2, 3], [1, 1, 4], [2, 1, 4]])
    )
    print(obj.maxNumEdgesToRemove(n=4, edges=[[3, 2, 3], [1, 1, 2], [2, 3, 4]]))
