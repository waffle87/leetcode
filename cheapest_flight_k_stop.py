# 787. Cheapest Flights Within K Stops
import collections
import heapq

"""
there are 'n' cities connected by some number of flights. you are given array
'flights' where 'flight[i] = [fromi, toi, pricei]' indicates that there is a
flight from city 'fromi' to city 'toi' with cost 'pricei'.
you are also given three integers 'src, dst, & k'. return the cheapest price
from 'src' to 'dst' with at most 'k' stops. if there is no such route, -1
"""


class Solution(object):
    def findCheapestPrice(self, n, flights, src, dst, k):
        """
        :type n: int
        :type flights: List[List[int]]
        :type src: int
        :type dst: int
        :type k: int
        :rtype: int
        """
        f = collections.defaultdict(dict)
        for a, b, p in flights:
            f[a][b] = p
        heap = [(0, src, k + 1)]
        while heap:
            p, i, k = heapq.heappop(heap)
            if i == dst:
                return p
            if k > 0:
                for j in f[i]:
                    heapq.heappush(heap, (p + f[i][j], j, k - 1))
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.findCheapestPrice(
            n=4,
            flights=[[0, 1, 100], [1, 2, 100], [2, 0, 100], [1, 3, 600], [2, 3, 200]],
            src=0,
            dst=3,
            k=1,
        )
    )
    print(
        obj.findCheapestPrice(
            n=3, flights=[[0, 1, 100], [1, 2, 100], [0, 2, 500]], src=0, dst=2, k=1
        )
    )
    print(
        obj.findCheapestPrice(
            n=3, flights=[[0, 1, 100], [1, 2, 100], [0, 2, 500]], src=0, dst=2, k=0
        )
    )
