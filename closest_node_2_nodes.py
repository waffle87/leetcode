# 2359. Find Closest Node to Given Two Nodes

"""
you are given a directed graph of 'n' nodes numbered from 0 to 'n - 1', where
each node has at most one outgoing edge. the graph is represented with a
given 0-indexed array 'edges' of size 'n', indicating that there is a
directed edge from node 'i' to node 'edges[i]'. if there is no outgoing edge
from 'i' then 'edges[i] == -1'. you are also given two integers 'node1' and
'node2'. return the indes of the node that can be reached from both 'node1'
and 'node2' such that the maximum between the distance from 'node1' to that
node and from 'node2' to that node is minimised
"""


class Solution(object):
    def dfs(self, node, edges, dist, vis):
        vis[node] = True
        neigh = edges[node]
        if neigh != -1 and vis[neigh] == False:
            dist[neigh] = dist[node] + 1
            self.dfs(neigh, edges, dist, vis)

    def closestMeetingNode(self, edges, node1, node2):
        """
        :type edges: List[int]
        :type node1: int
        :type node2: int
        :rtype: int
        """
        n, ans = len(edges), -1
        min_dist = float("inf")
        n1, n2 = [0] * n, [0] * n
        v1, v2 = [False] * n, [False] * n
        self.dfs(node1, edges, n1, v1)
        self.dfs(node2, edges, n2, v2)
        for i in range(n):
            if v1[i] and v2[i] and min_dist > max(n1[i], n2[i]):
                min_dist = max(n1[i], n2[i])
                ans = i
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.closestMeetingNode(edges=[2, 2, 3, -1], node1=0, node2=1))
    print(obj.closestMeetingNode(edges=[1, 2, -1], node1=0, node2=2))
