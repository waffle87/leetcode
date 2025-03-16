# 2594. Minimum Time to Repair Cars
import heapq
from collections import Counter

"""
you are given an integer array 'ranks' representing the ranks of some
mechanics. 'ranks[i]' is the rank of the i'th mechanic. a mechanic with a
rank 'r' can repair 'n' cars in 'r  n^2' minutes. you are also given an
integer 'cars' representing the total number of cars waiting in the garage to
be repaired. return the minimum time taken to repair all the cars. note: all
the mechanics can repair the cars simultaneously.
"""


class Solution(object):
    def repairCars(self, ranks, cars):
        """
        :type ranks: List[int]
        :type cars: int
        :rtype: int
        """
        cnt = Counter(ranks)
        h = [[i, i, 1, cnt[i]] for i in cnt]
        heapq.heapify(h)
        while cars > 0:
            time, rank, k, count = heapq.heappop(h)
            cars -= count
            k += 1
            heapq.heappush(h, [rank * k * k, rank, k, count])
        return time


if __name__ == "__main__":
    obj = Solution()
    print(obj.repairCars(ranks=[4, 2, 3, 1], cars=10))
    print(obj.repairCars(ranks=[5, 1, 8], cars=6))
