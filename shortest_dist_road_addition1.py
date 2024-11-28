# 3243. Shortest Distance After Road Addition Queries I

"""
you are given an integer 'n' and a 2d integer array 'queries'. there are 'n'
cities numbered from 0 to 'n - 1'. initially there is a unidirectional road
from city 'i' to city 'i + 1' for all '0 <= i < n - 1'. 'queries[i] = [u_i,
v_i]' represents the addition of a new unidirectional road from city 'u_i' to
city 'v_i'. after each query, you need to find the length of the shortest
path from city 0 to city 'n - 1'. return an array 'answer' where for each 'i'
in the range of '[0, queries.length - 1]', 'answer[i]' is the length of the
shortest path from city 0 to city 'n - 1' after processing the first 'i + 1'
queries.
"""


class Solution(object):
    def shortestDistanceAfterQueries(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        # ans = []
        # mp = {i: [i + 1] for i in range(n - 1)}
        # for i in queries:
        #     mp[i[0]].append(i[1])
        #     dp = [float("inf")] * n
        #     dp[n - 1] = 0
        #     for j in range(n - 2, -1, -1):
        #         for next in mp[j]:
        #             dp[j] = min(dp[j], dp[next] + 1)
        #     ans.append(dp[0])
        # return ans
        sol = []
        city_distances = {i: [-1] * i + list(range(n - i)) for i in range(n)}
        for query in queries:
            source, destination = query
            city_distances[source][destination] = 1
            for i in range(destination + 1, n):
                city_distances[source][i] = min(
                    city_distances[destination][i] + 1, city_distances[source][i]
                )
            for i in range(source - 1, -1, -1):
                city_distances[i][destination] = min(
                    city_distances[i][source] + 1, city_distances[i][destination]
                )
            sol.append(city_distances[0][-1])
        return sol


if __name__ == "__main__":
    obj = Solution()
    print(obj.shortestDistanceAfterQueries(n=5, queries=[[2, 4], [0, 2], [0, 4]]))
    print(obj.shortestDistanceAfterQueries(n=4, queries=[[0, 3], [0, 2]]))
    print(obj.shortestDistanceAfterQueries(n=5, queries=[[1, 3], [0, 3]]))
