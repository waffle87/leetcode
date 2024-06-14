# 2706. Buy Two Chocolates

"""
given an integer array 'prices' representing the prices of various chocolates
in a store. you are also given a single integer 'money', which represents
your initial amount of money. you must buy exactly two chooclates in such a
way that you still have some non-negative money. you would to minimise the
sum of the prices of the two chocolates you buy. return the amount of money
you will have leftover after buying the two chocolates. if there is no way
for you to buy two chocolates without ending up in debt, return 'money'. note
that the leftover must be non-negative.
"""


class Solution(object):
    def buyChoco(self, prices, money):
        """
        :type prices: List[int]
        :type money: int
        :rtype: int
        """
        min1 = min2 = float("inf")
        for p in prices:
            if p < min1:
                min2, min1 = min1, p
            else:
                min2 = min(min2, p)
        leftover = money - (min1 + min2)
        return leftover if leftover >= 0 else money


if __name__ == "__main__":
    obj = Solution()
    print(obj.buyChoco(prices=[1, 2, 2], money=3))  # expect: 0
    print(obj.buyChoco(prices=[3, 2, 3], money=3))  # expect: 3
