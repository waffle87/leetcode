# 638. Shopping Offers

"""
in leetcode store, there are 'n' items to sell. each item has a price.
however, there are some special offers, and a special offer consists of one
or more different kinds of items with a sale price. you are given an integer
array 'price' where 'price[i]' is the price of the i'th item, and an integer
array 'needs' where 'needs[i]' is the number of pieces the i'th item you want
to buy. you are also given an array 'special', where 'special[i]' is of size
'n + 1' where 'special[i][j]' is the number of pieces of the j'th item in the
i'th other. return the lowest price you have to pay for exactly certain items
as given, where you could make optimal use of the special offers. you are not
allowed to buy more items that you want, even if that would lower the overall
price.
"""


class Solution(object):
    def shoppingOffers(self, price, special, needs):
        """
        :type price: List[int]
        :type special: List[List[int]]
        :type needs: List[int]
        :rtype: int
        """
        dp = {}

        def dfs(curr):
            val = sum(curr[i] * price[i] for i in range(len(needs)))
            for *spec, cost in special:
                tmp = [curr[j] - spec[j] for j in range(len(needs))]
                if min(tmp) >= 0:  # skip deals that exceed needs
                    val = min(val, dp.get(tuple(tmp), dfs(tmp)) + cost)
            dp[tuple(curr)] = val
            return val

        return dfs(needs)


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.shoppingOffers(price=[2, 5], special=[[3, 0, 5], [1, 2, 10]], needs=[3, 2])
    )
    print(
        obj.shoppingOffers(
            price=[2, 3, 4], special=[[1, 1, 0, 4], [2, 2, 1, 9]], needs=[1, 2, 1]
        )
    )
