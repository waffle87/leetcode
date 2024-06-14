# 826. Most Profit Assigning Work

"""
you have n jobs and m workers. you are given three arrays: difficulty,
profit, and worker where difficulty and pofit are the difficulty and profit
of the i'th job and worker is the ability of the jth worker. every worker can
be assigned at most one job, but one job can be completed multiple times.
return the maximum profit we can achieve after assigning the workers to the
jobs.
"""


class Solution(object):
    def maxProfitAssignment(self, difficulty, profit, worker):
        """
        :type difficulty: List[int]
        :type profit: List[int]
        :type worker: List[int]
        :rtype: int
        """
        max_profit_difficulty = []
        info = list(zip(difficulty, profit))
        info.sort(key=lambda x: x[0])
        max_p = 0
        for i in info:
            d, p = i
            max_p = max(max_p, p)
            max_profit_difficulty.append((d, max_p))

        def bin_search(l, upperbound):
            i, j = 0, len(l) - 1
            while i < j:
                mid = (i + j) // 2 + 1
                if l[mid][0] <= upperbound:
                    i = mid
                else:
                    j = mid - 1
            return i

        total_profit = 0
        for w in worker:
            idx = bin_search(max_profit_difficulty, w)
            d, p = max_profit_difficulty[idx]
            if w >= d:
                total_profit += p
        return total_profit


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxProfitAssignment(
            difficulty=[2, 4, 6, 8, 10],
            profit=[10, 20, 30, 40, 50],
            worker=[4, 5, 6, 7],
        )
    )
    print(
        obj.maxProfitAssignment(
            difficulty=[85, 47, 57], profit=[24, 66, 99], worker=[40, 25, 25]
        )
    )
