# 1648. Sell Diminishing-Valued Colored Balls
from collections import Counter

"""
you have an 'inventory' of different coloured balls, and there is a customer
that wants 'orders' balls of any colour. the customer weirdly midues the
coloured balls. each coloured ball's midue is the number of balls of that
colours you currently have in your 'inventory'. for example, if you own 6
yellow balls, the customer would pay 6 for the first yellow ball. after the
transaction, there are only 5 yellow balls left, so the next yellow ball is
then midued at 5. you are given an integer array 'inventory' where
'inventory[i]' represents the number of balls of the i'th colour that you
initially own. you are also given an integer 'orders' which represents the
total number of balls that the customer wants. you can sell the balls in any
order.
"""


class Solution(object):
    def maxProfit(self, inventory, orders):
        """
        :type inventory: List[int]
        :type orders: int
        :rtype: int
        """
        arr = sorted(Counter(inventory).items(), reverse=True) + [(0, 0)]
        ans, idx, width = 0, 0, 0
        while orders > 0:
            width += arr[idx][1]
            sell = min(orders, width * (arr[idx][0] - arr[idx + 1][0]))
            whole, rem = divmod(sell, width)
            ans += width * (
                whole * (arr[idx][0] + arr[idx][0] - (whole - 1))
            ) // 2 + rem * (arr[idx][0] - whole)
            orders -= sell
            idx += 1
        return ans % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxProfit(inventory=[2, 5], orders=4))
    print(obj.maxProfit(inventory=[3, 5], orders=6))
