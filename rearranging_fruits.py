# 2561. Rearranging Fruits
from collections import Counter

"""
you have two fruit baskests containing 'n' fruits each. you are given two
indexed integer arrays 'basket1' and 'basket2' representing the cost of fruit
in each baset. you want o make both baskets equal. to do so, you can use the
following operation as many times as you want: chose two indices 'i' and 'j'
and swap the i'th fruit of 'basket1' with the j'th fruit of 'basket2'. the
cost of the swap is 'min(basket1[i], basket2[j])'. two baskets are considered
equal if sorting them according to the fruit cost makes them exactly the same
baksets. return the minimum cost to make both baskets equal or -1 if
impossible.
"""


class Solution(object):
    def minCost(self, basket1, basket2):
        """
        :type basket1: List[int]
        :type basket2: List[int]
        :rtype: int
        """
        cnt = Counter(basket1 + basket2)
        for i in cnt:
            if cnt[i] % 2:
                return -1
            cnt[i] >>= 1
        a1 = list((Counter(basket1) - cnt).elements())
        a2 = list((Counter(basket2) - cnt).elements())
        low = min(cnt)
        c = sorted(a1 + a2)
        return sum(min(low * 2, c[i]) for i in range(len(a1)))


if __name__ == "__main__":
    obj = Solution()
    print(obj.minCost(basket1=[4, 2, 2, 2], basket2=[1, 4, 1, 2]))
    print(obj.minCost(basket1=[2, 3, 4, 1], basket2=[3, 2, 5, 1]))
