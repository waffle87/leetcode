# 3573. Best Time to Buy and Sell Stock V

"""
you are given an integer array 'prices' where 'prices[i]' is the price of a
stock in dollars on the i'th day, and an integer 'k'. you are allowed to make
at most 'k' transactions, where each transaction can be either of the
following: normal transaction is buy on day 'i', then sell on a later day 'j'
where 'i < j'. short selling transaction where you sell on day 'i', then buy
back on a later day 'j' where 'i < j'. note that you must complete each
transaction betfore starting another. additionally, you can't buy or sell on
the same day you are selling or buying back as part of a previous
transaction. return the maximum total profit you can earn by making at most
'k' transactions.
"""


class Solution(object):
    def maximumProfit(self, prices, k):
        """
        :type prices: List[int]
        :type k: int
        :rtype: int
        """
        prev = [float("-inf")] * k
        curr = [0] * k
        ans = [0] * (k + 1)
        for i in prices:
            for j in range(k, 0, -1):
                ans[j] = max(ans[j], prev[j - 1] + i, curr[j - 1] - i)
                prev[j - 1] = max(prev[j - 1], ans[j - 1] - i)
                curr[j - 1] = max(curr[j - 1], ans[j - 1] + i)
        return max(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumProfit(prices=[1, 7, 9, 8, 2], k=2))
    print(obj.maximumProfit(prices=[12, 16, 19, 19, 8, 1, 19, 13, 9], k=3))
