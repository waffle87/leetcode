# 641. Design Circular Deque

"""
design your implementation of the circular double ended queue (deque).
implement the 'MyCircularDeque' class
"""


class MyCircularDeque(object):
    def __init__(self, k):
        """
        :type k: int
        """
        self.size = 0
        self.front = 0
        self.rear = 0
        self.capacity = k
        self.data = [-1] * k

    def insertFront(self, value):
        """
        :type value: int
        :rtype: bool
        """
        if self.isFull():
            return False
        if self.isEmpty():
            self.data[self.front] = value
        else:
            self.front = (self.front - 1) % self.capacity
            self.data[self.front] = value
        self.size += 1
        return True

    def insertLast(self, value):
        """
        :type value: int
        :rtype: bool
        """
        if self.isFull():
            return False
        if self.isEmpty():
            self.data[self.rear] = value
        else:
            self.rear = (self.rear + 1) % self.capacity
            self.data[self.rear] = value
        self.size += 1
        return True

    def deleteFront(self):
        """
        :rtype: bool
        """
        if self.isEmpty():
            return False
        self.data[self.front] = -1
        self.front = (self.front + 1) % self.capacity
        self.size -= 1
        if self.isEmpty():
            self.rear = self.front
        return True

    def deleteLast(self):
        """
        :rtype: bool
        """
        if self.isEmpty():
            return False
        self.data[self.rear] = -1
        self.rear = (self.rear - 1) % self.capacity
        self.size -= 1
        if self.isEmpty():
            self.front = self.rear
        return True

    def getFront(self):
        """
        :rtype: int
        """
        return self.data[self.front]

    def getRear(self):
        """
        :rtype: int
        """
        return self.data[self.rear]

    def isEmpty(self):
        """
        :rtype: bool
        """
        return self.size == 0

    def isFull(self):
        """
        :rtype: bool
        """
        return self.size == self.capacity


if __name__ == "__main__":
    obj = MyCircularDeque(3)
    print(obj.insertLast(1))
    print(obj.insertLast(2))
    print(obj.insertFront(3))
    print(obj.insertFront(4))
    print(obj.getRear())
    print(obj.isFull())
    print(obj.deleteLast())
    print(obj.insertFront(4))
    print(obj.getFront())
