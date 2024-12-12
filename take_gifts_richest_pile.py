# 2558. Take Gifts From the Richest Pile
import heapq
from math import isqrt

"""
you are given an integer array 'gifts' denoting the number of gifts in
various piles. every second, you do the following: choose the pile with the
maximum number of gifts, if there is more than one pile with the maximum
number of gifts, choose any. leave behind the floor of the square root of the
number of gifts in the pile. take the rest of the gifts. return the number of
gifts remaining after 'k' seconds.
"""


class Solution(object):
    def pickGifts(self, gifts, k):
        """
        :type gifts: List[int]
        :type k: int
        :rtype: int
        """
        gifts = [-i for i in gifts]
        heapq.heapify(gifts)
        x, i = 1 << 32, 0
        while i < k and x > 1:
            x = -heapq.heappop(gifts)
            heapq.heappush(gifts, -isqrt(x))
            i += 1
        return -sum(gifts)


if __name__ == "__main__":
    obj = Solution()
    print(obj.pickGifts(gifts=[25, 64, 9, 4, 100], k=4))
    print(obj.pickGifts(gifts=[1, 1, 1, 1], k=4))
