# 1475. Final Prices With a Special Discount in a Shop

"""
you are given an integer array 'prices' where 'prices[i]' is the price of the
i'th item in a shop. there is a special discount for items in the shop. if
you buy the i'th item, then you will receive a discount equivalent to
'prices[j]' where 'j' is the minimum index such that 'j > i' and 'prices[j]
<= prices[i]'. otherwise, you will not receive any discount at all. return an
integer array 'answer' where 'answer[i]' is the final price you will pay for
the i'th item of the shop, considering the special discount
"""


class Solution(object):
    def finalPrices(self, prices):
        """
        :type prices: List[int]
        :rtype: List[int]
        """
        stack = []
        for i, j in enumerate(prices):
            while stack and prices[stack[-1]] >= j:
                prices[stack.pop()] -= j
            stack.append(i)
        return prices


if __name__ == "__main__":
    obj = Solution()
    print(obj.finalPrices(prices=[8, 4, 6, 2, 3]))
    print(obj.finalPrices(prices=[1, 2, 3, 4, 5]))
    print(obj.finalPrices(prices=[10, 1, 1, 6]))
