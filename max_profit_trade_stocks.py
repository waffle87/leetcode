# 3562. Maximum Profit from Trading Stocks with Discounts

"""
you are given an integer 'n' representing the number of employees in a
company. each employee is assign a unique id from 1 to 'n', and employee 1 is
the ceo. you are given two integers arrays 'present' and 'future', each of
length 'n', where 'present[i]' represents the current price at which the i'th
employee can buy  stock today. 'future[i]' represents the expected price at
which the i'th employee can sell the stock tomorrow. the company's hierarchy
is represented by a 2d integer array 'hierarchy', where 'hierarchy[i] = [u_i,
v_i]' means that employee 'u_i' is the direct boss of employee can buy their
stock at half the original price. return the maximum profit that can be
achieve without exceeding the budget.
"""


class Solution(object):
    def maxProfit(self, n, present, future, hierarchy, budget):
        """
        :type n: int
        :type present: List[int]
        :type future: List[int]
        :type hierarchy: List[List[int]]
        :type budget: int
        :rtype: int
        """
        tree = [[] for _ in range(n)]
        for u, v in hierarchy:
            tree[u - 1].append(v - 1)
        dp = [[[0] * (budget + 1) for _ in range(2)] for _ in range(n)]
        self.dfs(0, present, future, tree, dp, budget)
        return max(dp[0][0])

    def dfs(self, u, present, future, tree, dp, budget):
        children = tree[u]
        child_dps = []
        for v in children:
            self.dfs(v, present, future, tree, dp, budget)
            child_dps.append((dp[v][0], dp[v][1]))
        for parentBought in range(2):
            price = present[u] // 2 if parentBought else present[u]
            profit = future[u] - price
            base = [0] * (budget + 1)
            for c0, _ in child_dps:
                next_base = [0] * (budget + 1)
                for b in range(budget + 1):
                    if base[b] == 0 and b != 0:
                        continue
                    for k in range(budget - b + 1):
                        next_base[b + k] = max(next_base[b + k], base[b] + c0[k])
                base = next_base
            curr = base[:]
            if price <= budget:
                base = [0] * (budget + 1)
                for _, c1 in child_dps:
                    next_base = [0] * (budget + 1)
                    for b in range(budget + 1):
                        if base[b] == 0 and b != 0:
                            continue
                        for k in range(budget - b + 1):
                            next_base[b + k] = max(next_base[b + k], base[b] + c1[k])
                    base = next_base
                for b in range(price, budget + 1):
                    curr[b] = max(curr[b], base[b - price] + profit)
            dp[u][parentBought] = curr


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxProfit(n=2, present=[1, 2], future=[4, 3], hierarchy=[[1, 2]], budget=3)
    )
    print(
        obj.maxProfit(n=2, present=[3, 4], future=[5, 8], hierarchy=[[1, 2]], budget=4)
    )
    print(
        obj.maxProfit(
            n=3,
            present=[4, 6, 8],
            future=[7, 9, 11],
            hierarchy=[[1, 2], [1, 3]],
            budget=10,
        )
    )
    print(
        obj.maxProfit(
            n=3,
            present=[5, 2, 3],
            future=[8, 5, 6],
            hierarchy=[[1, 2], [2, 3]],
            budget=7,
        )
    )
