# 1352. Product of the Last K Numbers

"""
design an algorithm that accepts a stream of integers and retrieves the
product of the last 'k' integers of the stream. implement the
'ProductOfNumbers' class. the test cases are generated so that at any time,
the product of any contiguous sequence of numbers will fit into a single
32-bit integer without overflowing.
"""


class ProductOfNumbers(object):
    def __init__(self):
        self.pre = [1]

    def add(self, num):
        """
        :type num: int
        :rtype: None
        """
        if num == 0:
            self.pre = [1]
        else:
            self.pre.append(self.pre[-1] * num)

    def getProduct(self, k):
        """
        :type k: int
        :rtype: int
        """
        if k >= len(self.pre):
            return 0
        return self.pre[-1] / self.pre[-k - 1]


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
