# 2144. Minimum Cost of Buying Candies With Discount

"""
a shop is selling candies at a discount. for every two candies sold, the shop
gives a third candy for free. the customer can choose any candy to take away
for free as long as the cost of the chosen candy is less than or equal to the
minimum cost of the two candies bought. given a 0-indexed integer array
'cost', where 'cost[i]' denotes the cost of the i'th candy, return the
minimum cost of buying all the candies.
"""


class Solution:
    minimumCost = lambda self, cost: sum(
        c for i, c in enumerate(sorted(cost, reverse=True)) if i % 3 != 2
    )


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumCost(cost=[1, 2, 3]))
    print(obj.minimumCost(cost=[6, 5, 7, 9, 2, 2]))
    print(obj.minimumCost(cost=[5, 5]))
