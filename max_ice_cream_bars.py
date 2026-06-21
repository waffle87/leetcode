# 1833. Maximum Ice Cream Bars

"""
it is a sweltering summer day, and a boy wants to buy some ice cream bars. at
the store, there are 'n' ice cream bars. you are given an array 'costs' of
length 'n' where 'costs[i]' is the price of the i'th ice cream bar in coins.
the boy initially has 'coins' coins to spend and he wants to buy as many ice
cream bars as possible. note, the boy can buy the ice cream bars in any
order. return the maximum number of ice cream bars the boy can buy with
'coins' coins. you must solve the problem by counting sort.
"""


class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        return sum(1 for i in sorted(costs) if (coins := coins - i) >= 0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxIceCream(costs=[1, 3, 2, 4, 1], coins=7))
    print(obj.maxIceCream(costs=[10, 6, 8, 7, 7, 8], coins=5))
    print(obj.maxIceCream(costs=[1, 6, 3, 1, 2, 5], coins=20))
