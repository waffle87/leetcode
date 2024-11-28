# 123. Best Time to Buy and Sell Stock III

"""
you are given an array 'prices' where 'prices[i]' is the price of a given
stock on the i'th day. find the maximum profit you can achieve. you may
complete at most two transactions. note, you may not engage in multiple
transactions simultaneously.
"""


class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0
        k = 2
        states = [0] + [-float("inf") for i in range(k * 2)]
        states[1] = -prices[0]
        for i in range(1, len(prices)):
            for j in range(k):
                states[2 * j + 1] = max(states[2 * j + 1], states[2 * j] - prices[i])
                states[2 * j + 2] = max(
                    states[2 * j + 2], states[2 * j + 1] + prices[i]
                )
        return max(0, states[-1])


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxProfit(prices=[3, 3, 5, 0, 0, 3, 1, 4]))
    print(obj.maxProfit(prices=[1, 2, 3, 4, 5]))
    print(obj.maxProfit(prices=[7, 6, 4, 3, 1]))
