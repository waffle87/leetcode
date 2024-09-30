# 1381. Design a Stack With Increment Operation

"""
design a stack that supports increment operations on its elements. implement
the function increment that increments the bottom 'k' elements of the stack
by 'val' if there are less than 'k' elements in the stack, increment all the
elements in the stack
"""


class CustomStack(object):
    def __init__(self, maxSize):
        """
        :type maxSize: int
        """
        self.n = maxSize
        self.stack = []
        self.inc = []

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        if len(self.inc) < self.n:
            self.stack.append(x)
            self.inc.append(0)

    def pop(self):
        """
        :rtype: int
        """
        if not self.inc:
            return -1
        if len(self.inc) > 1:
            self.inc[-2] += self.inc[-1]
        return self.stack.pop() + self.inc.pop()

    def increment(self, k, val):
        """
        :type k: int
        :type val: int
        :rtype: None
        """
        if self.inc:
            self.inc[min(k, len(self.inc)) - 1] += val


if __name__ == "__main__":
    obj = CustomStack(3)
    obj.push(1)
    obj.push(2)
    print(obj.pop())
    obj.push(2)
    obj.push(3)
    obj.push(4)
    obj.increment(5, 100)
    print(obj.pop())
    print(obj.pop())
    print(obj.pop())
    print(obj.pop())
