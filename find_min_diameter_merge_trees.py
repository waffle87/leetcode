# 3203. Find Minimum Diameter After Merging Two Trees

"""
there exists two undirected trees with 'n' and 'm' nodes numbered from 0 to
'n - 1' and from 0 to 'm - 1', respectively. you are given two 2d integer
arrays 'edges1', and 'edges2' of lengths 'n - 1' and 'm - 1', respectively,
where 'edges1[i] = [a_i, b_i]' indicates that thereis an edge between nodes
'a_i' and 'b_i' in the first tree, and 'edges2[i] = [u_i, v_i]' indicates
there is an edge between nodes 'u_i' and 'v_i' in the second tree. you must
connect one node from the first tree with another node from the second tree
with an edge. return the minimum possible diameter of the resulting tree. the
diameter of a tree is the length of the longest path between any two nodes in
the tree
"""


class Solution(object):
    def minimumDiameterAfterMerge(self, edges1, edges2):
        """
        :type edges1: List[List[int]]
        :type edges2: List[List[int]]
        :rtype: int
        """

        def farthest(hash, i):
            n = len(hash)
            bfs = [i]
            vis = [0] * n
            vis[i] = 1
            res, diam = -1, -1
            for i in bfs:
                for j in hash[i]:
                    if vis[j] == 0:
                        vis[j] = vis[i] + 1
                        bfs.append(j)
                        if vis[j] > diam:
                            res = j
                            diam = vis[j]
            return res, diam - 1

        def diameter(edges):
            if not edges:
                return 0, 0, 0
            n = len(edges) + 1
            hash = [[] for i in range(n)]
            for i, j in edges:
                hash[i].append(j)
                hash[j].append(i)
            v1, d = farthest(hash, 0)
            v2, d = farthest(hash, v1)
            return d, v1, v2

        d1, i, j = diameter(edges1)
        d2, i, j = diameter(edges2)
        return max(d1, d2, (d1 + 1) // 2 + (d2 + 1) // 2 + 1)


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.minimumDiameterAfterMerge(edges1=[[0, 1], [0, 2], [0, 3]], edges2=[[0, 1]])
    )
    print(
        obj.minimumDiameterAfterMerge(
            edges1=[[0, 1], [0, 2], [0, 3], [2, 4], [2, 5], [3, 6], [2, 7]],
            edges2=[[0, 1], [0, 2], [0, 3], [2, 4], [2, 5], [3, 6], [2, 7]],
        )
    )
