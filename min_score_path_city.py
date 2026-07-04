# 2492. Minimum Score of a Path Between Two Cities

"""
you are given a positive integer 'n' representing 'n' cities numbered from 1
to 'n'. you are also given a 2d array 'roads' where 'roads[i] = [a_i, b_i,
distance_i]' indicates that there is a bidirectional road between cities
'a_i' and 'b_i' with a distance equal to 'distance_i'. the cities graph is
not necessarily connected. the score of a path between two cities is defined
as the minimum distance of a road in this path. return the minimum possible
score of a path between cities 1 and 'n'.
"""

from queue import Queue


class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        ans = float("inf")
        graph = [[] for _ in range(n + 1)]
        for i in roads:
            graph[i[0]].append((i[1], i[2]))
            graph[i[1]].append((i[0], i[2]))
        vis, q = [False] * (n + 1), Queue()
        vis[1] = True
        q.put(1)
        while not q.empty():
            node = q.get()
            for i, j in graph[node]:
                ans = min(ans, j)
                if not vis[i]:
                    vis[i] = True
                    q.put(i)
        return int(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minScore(n=4, roads=[[1, 2, 9], [2, 3, 6], [2, 4, 5], [1, 4, 7]]))
    print(obj.minScore(n=4, roads=[[1, 2, 2], [1, 3, 4], [3, 4, 7]]))
