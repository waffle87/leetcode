# 847. Shortest Path Visiting All Nodes
from math import inf
from collections import deque

"""
you have an undirected, connected graph of 'n' nodes labeled from 0 to 'n -
1'. you are given an array 'graph' where 'graph[i]' is a list of all the
nodes connected with node 'i' by an edge. return the length of the shortest
path that visits every node. you may start and stop any any node. you may
revisit nodes multiple times and you may reused edges.
"""


class Solution(object):
    def shortestPathLength(self, graph):
        node_cnt = len(graph)
        masks = [1 << i for i in range(node_cnt)]
        all_vis = (1 << node_cnt) - 1
        queue = deque([(i, masks[i]) for i in range(node_cnt)])
        steps = 0
        vis_state = [{masks[i]} for i in range(node_cnt)]
        while queue:
            cnt = len(queue)
            while cnt:
                curr_node, vis = queue.popleft()
                if vis == all_vis:
                    return steps
                for nb in graph[curr_node]:
                    new_vis = vis | masks[nb]
                    if new_vis == all_vis:
                        return steps + 1
                    if new_vis not in vis_state[nb]:
                        vis_state[nb].add(new_vis)
                        queue.append((nb, new_vis))
                cnt -= 1
            steps += 1
        return inf


if __name__ == "__main__":
    obj = Solution()
    print(obj.shortestPathLength([[1, 2, 3], [0], [0], [0]]))  # expect: 4
    print(obj.shortestPathLength([[1], [0, 2, 4], [1, 3, 4], [2], [1, 2]]))  # expect: 4
