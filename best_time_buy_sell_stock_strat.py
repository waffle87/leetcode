# 3652. Best Time to Buy and Sell Stock using Strategy

"""
you are given two integer arrays 'prices' and 'strategy' where 'prices[i]' is
the price of a given stock, and 'strategy[i]' represents a trading action
taken: -1 indicates buying one unit of the stock, 0 indicates holding the
stock, 1 indicates selling one unit of the stock. you are also given an even
integer 'k' and may perform at most one modification to 'strategy'. the
profit is defined as the sum of 'strategy[i]  prices[i]' across all days.
return the maximum possible profit you can achieve.
"""


class Solution(object):
    def maxProfit(self, prices, strategy, k):
        """
        :type prices: List[int]
        :type strategy: List[int]
        :type k: int
        :rtype: int
        """
        n, ans = len(prices), 0
        for i in range(n):
            ans += prices[i] * strategy[i]
        new = ans
        for i in range(n):
            if i > k - 1:
                new += prices[i - k] * strategy[i - k]
                new -= prices[i - k // 2]
            if i < k // 2:
                new += prices[i] * (-1 * strategy[i])
            else:
                new += prices[i] * (-1 * strategy[i])
                new += prices[i]
            if i >= k - 1:
                ans = max(ans, new)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxProfit(prices=[4, 2, 8], strategy=[-1, 0, 1], k=2))
    print(obj.maxProfit(prices=[5, 4, 3], strategy=[1, 1, 0], k=2))
