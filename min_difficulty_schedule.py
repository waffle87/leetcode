# 1335. Minimum Difficulty of a Job Schedule

"""
You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work
on the ith job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule
is the sum of difficulties of each day of the d days. The difficulty of a day is
the maximum difficulty of a job done on that day.

You are given an integer array job_difficulty and an integer d. The difficulty of
the ith job is job_difficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule
for the jobs return -1.
"""


class Solution(object):
    def helper(self, job_difficulty, days_left, idx):
        n = len(job_difficulty)
        if days_left == 1:
            return max(job_difficulty[idx:])
        max_difficulty = job_difficulty[idx]
        days_left -= 1
        stop = n - idx - days_left + 1
        res = float("inf")
        for i in range(1, stop):
            max_difficulty = max(max_difficulty, job_difficulty[idx + i - 1])
            other = self.helper(job_difficulty, days_left, idx + i)
            res = min(res, other + max_difficulty)
        return res

    def minDifficulty(self, jobDifficulty, d):
        """
        :type jobDifficulty: List[int]
        :type d: int
        :rtype: int
        """
        if len(jobDifficulty) < d:
            return -1
        total_sum = sum(jobDifficulty)
        if total_sum == 0:
            return 0
        return self.helper(jobDifficulty, d, 0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minDifficulty(jobDifficulty=[6, 5, 4, 3, 2, 1], d=2))
    print(obj.minDifficulty(jobDifficulty=[9, 9, 9], d=4))
    print(obj.minDifficulty(jobDifficulty=[1, 1, 1], d=3))
