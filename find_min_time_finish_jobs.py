# 1723. Find Minimum Time to Finish All Jobs
from functools import lru_cache
from itertools import product

"""
you are given an integer array 'jobs' where 'jobs[i]' is the amount of time
it takes to complete the i'th job. there are 'k' workers that you can assign
jobs to. each job should be assigned to exactly one worker. the working time
of a worker is the sum of the time it takes to complete all jobs assigned to
them. your goal is to devise an optimal assignment such that the maximum
working time of any worker is minimised. return the minimum possible maximum
working time of any assignment.
"""


class Solution(object):
    def minimumTimeRequired(self, jobs, k):
        """
        :type jobs: List[int]
        :type k: int
        :rtype: int
        """
        n = len(jobs)
        cost = [0] * (1 << n)
        for i, j in product(range(1 << n), range(n)):
            cost[i] += jobs[j] * ((i >> j) & 1)

        @lru_cache(None)
        def dp(mask, k):
            if k == 1:
                return cost[mask]
            submask, res = mask, cost[mask]
            while (submask - 1) & mask:
                submask = (submask - 1) & mask
                if cost[submask] >= res:
                    continue
                res = min(res, max(cost[submask], dp(mask ^ submask, k - 1)))
            return res

        return dp((1 << n) - 1, k)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumTimeRequired(jobs=[3, 2, 3], k=3))
    print(obj.minimumTimeRequired(jobs=[1, 2, 4, 7, 8], k=2))
