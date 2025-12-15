# 2110. Number of Smooth Descent Periods of a Stock

"""
you are given an integer array 'prices' representing the daily price history
of a stock where 'prices[i]' is the stock price on the i'th day. a smooth
descent period of a stock consists of one or more contiguous days such that
the price on each day is lower than the price on the peceding day by
exactly 1. the first day of the period is exempted from this rule. return the
number of smooth descent periods.
"""


class Solution(object):
    def getDescentPeriods(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        ans, dp = 1, 1
        for i in range(1, len(prices)):
            if prices[i] == prices[i - 1] - 1:
                dp += 1
            else:
                dp = 1
            ans += dp
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.getDescentPeriods(prices=[3, 2, 1, 4]))
    print(obj.getDescentPeriods(prices=[8, 6, 7, 7]))
    print(obj.getDescentPeriods(prices=[1]))
