# 1334. Find the City With the Smallest Number of Neighbors at a Threshold
# Distance

"""
there are 'n' cities numbered from 0 to 'n - 1'. given the array 'edges'
where 'edges[i] = [from_i, to_i, weight_i]' represents a bidirectional and
weighted edge between cities 'from_i' and 'to_i' and given the integer
'distanceThreshold'. return the city with the smallest number of cities that
are reachable through some path and whose distance is at most
'distanceThreshold', if there are multiple cities, return the city with the
greatest number. notice that the distance of a path connecting cities i and j
is equal to the sum of of the edges' weights along that path
"""


class Solution(object):
    def findTheCity(self, n, edges, distanceThreshold):
        """
        :type n: int
        :type edges: List[List[int]]
        :type distanceThreshold: int
        :rtype: int
        """
        dist = [[float("inf")] * n for _ in range(n)]
        for i, j, k in edges:
            dist[i][j] = dist[j][i] = k
        for i in range(n):
            dist[i][i] = 0
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
        ans = {sum(d <= distanceThreshold for d in dist[i]): i for i in range(n)}
        return ans[min(ans)]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.findTheCity(
            n=4, edges=[[0, 1, 3], [1, 2, 1], [1, 3, 4], [2, 3, 1]], distanceThreshold=4
        )
    )
    print(
        obj.findTheCity(
            n=5,
            edges=[[0, 1, 2], [0, 4, 8], [1, 2, 3], [1, 4, 2], [2, 3, 1], [3, 4, 1]],
            distanceThreshold=2,
        )
    )
