# 3946. Maximum Number of Items From Sale I
import numpy as np


class Solution:
    def maximumSaleItems(self, items: list[list[int]], budget: int) -> int:
        factors, prices = zip(*items)
        have = np.bincount(factors)
        gains = {factor: have[factor::factor].sum() for factor in set(factors)}
        cheapest = min(prices)
        best = np.arange(budget + 1)
        for factor, price in items:
            if (gain := gains[factor]) > price // cheapest:
                best[price:] = np.maximum(best[price:], best[:-price] + gain)
        return int(best[budget])


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumSaleItems(items=[[6, 2], [2, 6], [3, 4]], budget=9))
    print(
        obj.maximumSaleItems(items=[[2, 4], [3, 2], [4, 1], [6, 4], [12, 4]], budget=8)
    )
