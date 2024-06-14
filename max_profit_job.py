# 1235. Maximum Profit in Job Scheduling

"""
We have n jobs, where every job is scheduled to be done from startTime[i] to
endTime[i], obtaining a profit of profit[i].
You're given the startTime, endTime and profit arrays, return the maximum profit
you can take such that there are no two jobs in the subset with overlapping time
range.
If you choose a job that ends at time X you will be able to start another job
that starts at time X.
"""


class Solution(object):
    def jobScheduling(self, startTime, endTime, profit):
        """
        :type startTime: List[int]
        :type endTime: List[int]
        :type profit: List[int]
        :rtype: int
        """
        jobs = sorted(zip(endTime, startTime, profit))
        number_of_jobs = len(profit)
        dp = [0] * (number_of_jobs + 1)
        for i, (current_end_time, current_start_time, current_profit) in enumerate(
            jobs
        ):
            index = bisect_right(jobs, current_start_time, hi=i, key=lambda x: x[0])
            dp[i + 1] = max(dp[i], dp[index] + current_profit)
        return dp[number_of_jobs]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.jobScheduling(
            startTime=[1, 2, 3, 3], endTime=[3, 4, 5, 6], profit=[50, 10, 40, 70]
        )
    )
    print(
        obj.jobScheduling(
            startTime=[1, 2, 3, 4, 6],
            endTime=[3, 5, 10, 6, 9],
            profit=[20, 20, 100, 70, 60],
        )
    )
    print(obj.jobScheduling(startTime=[1, 1, 1], endTime=[2, 3, 4], profit=[5, 6, 4]))
