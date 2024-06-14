# 746. Min Cost Climbing Stairs

"""
you are given an integer array 'cost' where 'cost[i]' is the cost of the i'th
step on a staircase. once you pay the cost, you can either climb one or two
steps. you can either start from the step with index 0 or the step with
index 1. return the minimum cost to reach the top of the floor.
"""


class Solution(object):
    def minCostClimbingStairs(self, cost):
        n = len(cost)
        dp = [0] * (n + 1)
        for i in range(2, n + 1):
            j1 = dp[i - 1] + cost[i - 1]
            j2 = dp[i - 2] + cost[i - 2]
            dp[i] = min(j1, j2)
        return dp[n]


if __name__ == "__main__":
    obj = Solution()
    print(obj.minCostClimbingStairs([10, 15, 20]))  # expect: 15
    print(obj.minCostClimbingStairs([1, 100, 1, 1, 1, 100, 1, 1, 100, 1]))  # expect: 6
