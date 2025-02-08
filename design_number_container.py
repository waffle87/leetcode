# 2349. Design a Number Container System
from collections import defaultdict
from bisect import insort_left

"""
design a number container system that can do the following: insert or replace
a number at the given index in the system or return the smallest index for
the given number in the system. implement the 'NumberContainers' class.
"""


class NumberContainers(object):
    def __init__(self):
        self.idxs = {}
        self.nums = defaultdict(list)

    def change(self, index, number):
        """
        :type index: int
        :type number: int
        :rtype: None
        """
        if index in self.idxs:
            old = self.idxs[index]
            self.nums[old].remove(index)
        self.idxs[index] = number
        insort_left(self.nums[number], index)

    def find(self, number):
        """
        :type number: int
        :rtype: int
        """
        return -1 if not self.nums[number] else self.nums[number][0]


if __name__ == "__main__":
    obj = NumberContainers()
    print(obj.find(10))
    obj.change(2, 10)
    obj.change(1, 10)
    obj.change(3, 10)
    obj.change(5, 10)
    print(obj.find(10))
    obj.change(1, 20)
    print(obj.find(10))
