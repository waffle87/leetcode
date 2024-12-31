# 983. Minimum Cost For Tickets

"""
you have planned some train traveling one year in advance. the days of the
year in which you will travel are given as an integer array 'days'. each day
is an integer 1 - 365. train tickets are sold in three different ways: 1 day
pass sold for 'costs[0]' dollars 7 day pass sold for 'costs[1]' dollars 30
day pass sold for 'costs[2]' dollars the passes allow that many days of
consecutive travel. return mininum number of dollars you need to travel every
day in the given list of days.
"""


class Solution(object):
    def mincostTickets(self, days, costs):
        """
        :type days: List[int]
        :type costs: List[int]
        :rtype: int
        """
        dp = [0 for i in range(days[-1] + 1)]
        dy = set(days)
        for i in range(days[-1] + 1):
            if i not in dy:
                dp[i] = dp[i - 1]
            else:
                dp[i] = min(
                    dp[max(0, i - 7)] + costs[1],
                    dp[max(0, i - 1)] + costs[0],
                    dp[max(0, i - 30)] + costs[2],
                )
        return dp[-1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.mincostTickets(days=[1, 4, 6, 7, 8, 20], costs=[2, 7, 15]))
    print(
        obj.mincostTickets(
            days=[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31], costs=[2, 7, 15]
        )
    )
