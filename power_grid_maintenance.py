# 3607. Power Grid Maintenance
from collections import defaultdict

"""
you are given an integer 'c' representing power stations, each with a unique
identifier 'id' from 1 to 'c'. these stations are interconnected via 'n'
bidirectional cables, represented by a 2 array 'connections' where each
element 'connections[i] = [u_i, v_i]' indicates a connection between station
'u_i' and 'v_i'. stations that are directly or indirectly connected form a
power grid. initially, all stations are online (operational). you are also
given a 2d integer array 'quries' where each query is one of the following
types: '[1, x]': a maintenance check is requested for station 'x'. if station
'x' is online, it resolves the check by itself. if station 'x' is offline,
the check is resolved by the operational station with the smallest 'id' in
the same power grid as 'x'. if no operational station exists in that grid,
return -1. '[2, x]': station 'x' goes offline. return an array of integers
representing the results of each query of type '[1, x]' in the order they
appear.
"""


class Solution(object):
    def processQueries(self, c, connections, queries):
        """
        :type c: int
        :type connections: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        graph = defaultdict(list)
        for u, v in connections:
            graph[u].append(v)
            graph[v].append(u)
        online = [True] * (c + 1)
        ans = []

        def dfs(x, vis):
            vis.add(x)
            for i in graph[x]:
                if i not in vis:
                    dfs(i, vis)

        for t, x in queries:
            if t == 1:
                if online[x]:
                    ans.append(x)
                else:
                    vis = set()
                    dfs(x, vis)
                    online_nodes = [i for i in vis if online[i]]
                    ans.append(min(online_nodes) if online_nodes else -1)
            else:
                online[x] = False
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.processQueries(
            c=5,
            connections=[[1, 2], [2, 3], [3, 4], [4, 5]],
            queries=[[1, 3], [2, 1], [1, 1], [2, 2], [1, 2]],
        )
    )
    print(obj.processQueries(c=3, connections=[], queries=[[1, 1], [2, 1], [1, 1]]))
