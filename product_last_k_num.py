# 1352. Product of the Last K Numbers

"""
design an algorithm that accepts a stream of integers and retrieves the
product of the last 'k' integers of the stream. implement the
'ProductOfNumbers' class. the test cases are generated so that at any time,
the product of any contiguous sequence of numbers will fit into a single
32-bit integer without overflowing.
"""

from bisect import bisect_left
from math import prod


class ProductOfNumbers:
    def __init__(self):
        self.size = 0
        self.zero = -1
        self.where = []
        self.factor = []

    def add(self, num: int) -> None:
        if num == 0:
            self.zero = self.size
            self.where = []
            self.factor = []
        elif num > 1:
            self.where.append(self.size)
            self.factor.append(num)
        self.size += 1

    def getProduct(self, k: int) -> int:
        start = self.size - k
        if self.zero >= start:
            return 0
        return prod(self.factor[bisect_left(self.where, start) :])


if __name__ == "__main__":
    obj = ProductOfNumbers()
    obj.add(3)
    obj.add(0)
    obj.add(2)
    obj.add(5)
    obj.add(4)
    print(obj.getProduct(2))
    print(obj.getProduct(3))
    print(obj.getProduct(4))
    obj.add(8)
    print(obj.getProduct(2))
