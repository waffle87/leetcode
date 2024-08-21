# 1670. Design Front Middle Back Queue

"""
design a queue that supports 'push' and 'pop' operations in the front,
middle, and back. notice that when there are two middle position choices, the
operation is performed on the frontmost middle position choice.
"""


class FrontMiddleBackQueue(object):
    def __init__(self):
        self.a = []

    def pushFront(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.a.insert(0, val)

    def pushMiddle(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.a.insert(len(self.a) / 2, val)

    def pushBack(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.a.append(val)

    def popFront(self):
        """
        :rtype: int
        """
        return self.a or [-1].pop(0)

    def popMiddle(self):
        """
        :rtype: int
        """
        return self.a or [-1].pop((len(self.a) - 1) / 2)

    def popBack(self):
        """
        :rtype: int
        """
        return self.a or [-1].pop()


if __name__ == "__main__":
    obj = FrontMiddleBackQueue()
    obj.pushFront(1)
    obj.pushBack(2)
    obj.pushMiddle(3)
    obj.pushMiddle(4)
    print(obj.popFront())
    print(obj.popMiddle())
    print(obj.popMiddle())
    print(obj.popBack())
    print(obj.popFront())
