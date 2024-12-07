# 3116. Kth Smallest Amount With Single Denomination Combination
from collections import defaultdict
from itertools import combinations
from math import lcm

"""
you are given an integer array 'coins' representing coins of different
denominations and an integer 'k'. you have an infinite number of coins of
each denomination. however, you are not allowed to combine coins of different
denominations. return the k'th smallest amount that can be made using these
coins.
"""


class Solution(object):
    def findKthSmallest(self, coins, k):
        """
        :type coins: List[int]
        :type k: int
        :rtype: int
        """
        n, dic = len(coins), defaultdict(list)
        for i in range(1, n + 1):
            for comb in combinations(coins, i):
                dic[len(comb)].append(lcm(*comb))

        def cnt(dic, target):
            res = 0
            for i in range(1, n + 1):
                for j in dic[i]:
                    res += target // j * pow(-1, i + 1)
            return res

        start, end = min(coins), min(coins) * k
        while start + 1 < end:
            mid = (start + end) // 2
            if cnt(dic, mid) >= k:
                end = mid
            else:
                start = mid
        if cnt(dic, start) >= k:
            return start
        else:
            return end


if __name__ == "__main__":
    obj = Solution()
    print(obj.findKthSmallest(coins=[3, 6, 9], k=3))
    print(obj.findKthSmallest(coins=[5, 2], k=7))
