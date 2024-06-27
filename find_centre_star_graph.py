# 1791. Find Center of Star Graph

"""
there is an undirected star graph consisting of 'n' nodes labeled from 1 to
'n'. a star graph is a graph where there is one centre node and exactly 'n -
1' edges that connect the centre node with every other node. you are given a
2d integer array 'edges' where 'edges[i] = [ui, vi]' indicates that there is
an edge between the node 'ui' and 'vi'. return the centre of the star graph.
"""


class Solution(object):
    def findCenter(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: int
        """
        x, y = edges[0][0], edges[0][1]
        if x == edges[1][0] or x == edges[1][1]:
            return x
        return y


if __name__ == "__main__":
    obj = Solution()
    print(obj.findCenter(edges=[[1, 2], [2, 3], [4, 2]]))
    print(obj.findCenter(edges=[[1, 2], [5, 1], [1, 3], [1, 4]]))
