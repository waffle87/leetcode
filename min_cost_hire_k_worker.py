# 857. Minimum Cost to Hire K Workers
import heapq

"""
there are 'n' workers. you are given two integer arrays 'quality' and 'wage'
where 'quality[i]' is the quality of the i'th worker and 'wage[i]' is the
minimum wage expectation for the i'th worker. we want to hire exactly 'k'
workers to form a paid group. to hire a group of 'k' workers, we must pay
them according to the following rules. every worker in the paid group must be
paid at least their minimum wage expectation. in the group, each worker's pay
must be directly proportional to their quality. this means if a worker's
quality is double that of another worker in the group, then they must be paid
twice as much as the other worker. given the integer 'k', return the least
amount of money needed to form apaid group satisfying the above conditions.
"""


class Solution(object):
    def mincostToHireWorkers(self, quality, wage, k):
        """
        :type quality: List[int]
        :type wage: List[int]
        :type k: int
        :rtype: float
        """
        workers = sorted([float(w) / q, q] for w, q in zip(wage, quality))
        ans = float("inf")
        qsum = 0
        heap = []
        for r, q in workers:
            heapq.heappush(heap, -q)
            qsum += q
            if len(heap) > k:
                qsum += heapq.heappop(heap)
            if len(heap) == k:
                ans = min(ans, qsum * r)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.mincostToHireWorkers(quality=[10, 20, 5], wage=[70, 50, 30], k=2))
    print(
        obj.mincostToHireWorkers(quality=[3, 1, 10, 10, 1], wage=[4, 8, 2, 2, 7], k=3)
    )
