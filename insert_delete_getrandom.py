# 380. Insert Delete GetRandom O(1)
import random

"""
Implement the RandomizedSet class:
RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present.
Returns true if the item was not present, false otherwise. bool remove(int val)
Removes an item val from the set if present. Returns true if the item was
present, false otherwise. int getRandom() Returns a random element from the
current set of elements (it's guaranteed that at least one element exists when
this method is called). Each element must have the same probability of being
returned.
You must implement the functions of the class such that each function works in
average O(1) time complexity.
"""


class RandomizedSet(object):
    def __init__(self):
        self.lst = []
        self.idx_map = {}

    def search(self, val):
        return val in self.idx_map

    def insert(self, val):
        """
        :type val: int
        :rtype: bool
        """
        if self.search(val):
            return False
        self.lst.append(val)
        self.idx_map[val] = len(self.lst) - 1
        return True

    def remove(self, val):
        """
        :type val: int
        :rtype: bool
        """
        if not self.search(val):
            return False
        idx = self.idx_map[val]
        self.lst[idx] = self.lst[-1]
        self.idx_map[self.lst[-1]] = idx
        del self.idx_map[val]
        return True

    def getRandom(self):
        """
        :rtype: int
        """
        return random.choice(self.lst)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()

if __name__ == "__main__":
    obj = RandomizedSet()
    print(obj.insert(1))
    print(obj.remove(2))
    print(obj.insert(2))
    print(obj.getRandom())
    print(obj.remove(1))
    print(obj.insert(2))
    print(obj.getRandom())
