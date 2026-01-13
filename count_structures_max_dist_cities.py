# 1617. Count Subtrees With Max Distance Between Cities
import collections

"""
there are 'n' cities numbered from 1 to 'n'. you are given an array 'edges'
of size 'n - 1', where 'edges[i] = [ui, vi]' represents a bidirectional edge
between cities 'ui' and 'vi'. there exists a unique path between each pair of
cities. in other words, the cities form a tree. a subtree is a subset of
cities where every city is reachable from every other city in the subset,
where the path between each pair passes through only the cities from the
subset. two subtrees are different if there is a city in one subtree that is
not present in the other. for each 'd' from 'n - 1', find the number of
subtrees in which the maximum distance between any two cities in the subtree
is equal to 'd'. return an array of size 'n - 1' where the d'th element is
the number of subtrees in which the maximum distance between any two cities
is equal to 'd'. notice that the distance between the two cities is the
number of edges in the path between them.
"""


class Solution(object):
    def countSubgraphsForEachDiameter(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """

        def bfs(src, cities):
            visited, max_dist = {src}, 0
            q = collections.deque([(src, 0)])
            while len(q) > 0:
                u, d = q.popleft()
                max_dist = d
                for v in graph[u]:
                    if v not in visited and v in cities:
                        visited.add(v)
                        q.append((v, d + 1))
            return max_dist, visited

        def farthest(state):
            cities = set()
            for i in range(n):
                if (state >> i) & 1 == 1:
                    cities.add(i)
            ans = 0
            for i in cities:
                max_dist, visited = bfs(i, cities)
                if len(visited) < len(cities):
                    return 0
                ans = max(ans, max_dist)
            return ans

        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u - 1].append(v - 1)
            graph[v - 1].append(u - 1)
        ans = [0] * (n - 1)
        for state in range(1, 2**n):
            d = farthest(state)
            if d > 0:
                ans[d - 1] += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countSubgraphsForEachDiameter(n=4, edges=[[1, 2], [2, 3], [2, 4]]))
    print(obj.countSubgraphsForEachDiameter(n=2, edges=[[1, 2]]))
    print(obj.countSubgraphsForEachDiameter(n=3, edges=[[1, 2], [2, 3]]))
