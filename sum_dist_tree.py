# 834. Sum of Distances in Tree
from collections import defaultdict

"""
there is an undirected connected tree with 'n' nodes labeled from 0 to 'n -
1' and 'n - 1' edges. you are given the integer 'n' and the array 'edges'
where 'edges[i] = [ai, bi]' indicates that there is an edge between nodes
'ai' and 'bi' in the tree. return an array 'ans' of length 'n' where 'ans[i]'
is thesum of the distances between the i'th node in the tree and all other
nodes.
"""


class Solution(object):
    def sumOfDistancesInTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        tree = defaultdict(set)
        res = [0] * n
        count = [1] * n
        for i, j in edges:
            tree[i].add(j)
            tree[j].add(i)

        def dfs(root, pre):
            for i in tree[root]:
                if i != pre:
                    dfs(i, root)
                    count[root] += count[i]
                    res[root] += res[i] + count[i]

        def dfs2(root, pre):
            for i in tree[root]:
                if i != pre:
                    res[i] = res[root] - count[i] + n - count[i]
                    dfs2(i, root)

        dfs(0, -1)
        dfs2(0, -1)
        return res


if __name__ == "__main__":
    obj = Solution()
    print(obj.sumOfDistancesInTree(n=6, edges=[[0, 1], [0, 2], [2, 3], [2, 4], [2, 5]]))
    print(obj.sumOfDistancesInTree(n=1, edges=[]))
    print(obj.sumOfDistancesInTree(n=2, edges=[[1, 0]]))
